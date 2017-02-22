/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:50:44 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 13:10:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

static int		parse_init(t_w3d *w3d, t_pdata *dat, t_w3dmap *map)
{
	int			ret;
	char		cfg[256];

	if (((ret = (int)read(dat->fd, dat->buf, PBUFS)) < 5) ||
		(ft_strncmp(dat->buf, "#map", 4)))
		return (0);
	dat->buf[ret] = '\0';
	dat->buf[PBUFS + 1] = (ret < PBUFS) ? 0 : 1;
	dat->blist[0] = ft_blstnew(sizeof(t_w3dmap), 8);
	dat->data[0] = map;
	*map = w3d->default_cfg;
	map->grid = NULL;
	ret = 0;
	dat->ret[15] = 1;
	if (ft_sscanf(dat->buf, "#map %*s %255s", cfg) >= 1)
		ret = w3d_parse_cfg(w3d, cfg, map);
	if (ret)
		dat->ret[15] = 0;
	else
		map->flags = W3D_MAP_STATIC;
	return (1);
}

static int		parse_loop(t_w3d *w3d, t_pdata *dat)
{
	char		sav;
	int			ret;
	int			check;

	sav = '\n';
	check = 1;
	while (check && ((ret = w3dp_nextline(dat)) >= 0))
	{
		if (!dat->c[ret])
			sav = '\0';
		dat->c[ret] = '\0';
		if (dat->c[0] == '[')
			check = w3dp_newmap(w3d, dat, dat->c);
		else
			check = w3dp_mapline(w3d, dat);
		dat->c[ret] = sav;
	}
	return (check);
}

static t_w3dmap	*create_layerdata(t_w3d *w3d, t_pdata *dat, int *len)
{
	t_blit		it;
	t_w3dmap	*map;
	t_w3dmap	*maps;
	int			i;

	if (!w3dp_rendermap(dat))
		dat->error = 0;
	*len = 0;
	it = (t_blit){dat->blist[0], 0};
	while ((map = ft_blstiter(&it)))
		*len += (map->grid) ? 1 : 0;
	if (!(*len) || !(maps = malloc(*len * sizeof(t_w3dmap))))
		return (NULL);
	i = 0;
	it = (t_blit){dat->blist[0], 0};
	while ((map = (t_w3dmap *)ft_blstiter(&it)))
	{
		if (map->grid)
			maps[i++] = *map;
		else
			w3d_rmlayout(w3d, map);
	}
	return (maps);
}

static void		setup_layer(t_w3dlvl *lvl)
{
	t_v2i		v2;

	lvl->active_lvl = 0;
	v2 = w3d_find_playerstart(lvl->lvl_data);
	lvl->player = (t_w3dpc){ .movkey = 0, .flags = 0,
		.position = (t_v3f){(float)v2.x + 0.5f, (float)v2.y + 0.5f, 0.5f},
		.speed = 3.0f, .movement = (t_v3f){ 0.0f, 0.0f, 0.0f},
		.eyes = (t_v3f){ 0.0f, 0.0f, 0.0f}, .look = (t_v2f){0.0f, 0.0f},
		.fov = (t_v2f){1.047197551f, 1.047197551f}};
	lvl->size = lvl->lvl_data->size;
	lvl->height = lvl->lvl_data->height;
	lvl->layer.type = W3D_LVL;
	lvl->layer.flags = W3DLAY_PRESSINPUT | W3DLAY_RELEASEINPUT;
	lvl->layer.drawer = &w3d_draw_lvl;
	lvl->layer.evt_process = &w3d_event_process_lvl;
}

t_w3dlvl		w3d_parse_lvl(t_w3d *w3d, const char *path, t_w3dl layer)
{
	t_pdata		dat;
	t_w3dmap	map;

	w3dp_parsedat_init(&dat);
	if (path && (path[0] == '@') && ft_filename_ext(w3d->paths.lvl_file,
		path + 1, ".w3dl", w3d->paths.lvl_len))
		path = w3d->paths.lvl_dir;
	if ((dat.fd = open(path, O_RDONLY)) < 0)
		return (layer.level);
	if ((dat.error = parse_init(w3d, &dat, &map)))
	{
		if ((dat.error = parse_loop(w3d, &dat)) &&
			(layer.level.lvl_data = create_layerdata(w3d,
				&dat, &(layer.level.level_num))))
			setup_layer(&(layer.level));
		if (!dat.ret[15])
			w3d_rmlayout(w3d, &map);
		ft_blstfree(&(dat.blist[0]));
		ft_blstfree(&(dat.blist[1]));
		ft_blstfree(&(dat.blist[2]));
	}
	close(dat.fd);
	return (layer.level);
}
