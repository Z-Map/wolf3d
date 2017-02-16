/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:50:44 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/15 21:43:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		parse_init(t_w3d *w3d, t_pdata *dat, t_w3dmap *map)
{
	int			ret;
	char		cfg[256];

	dat->c = dat->buf;
	dat->cursor = 0;
	dat->len[0] = 0;
	if (((ret = (int)read(dat->fd, dat->buf, PBUFS)) < 5) ||
		(ft_strncmp(dat->buf, "#map", 4)))
		return (0);
	dat->buf[ret] = '\0';
	dat->buf[PBUFS] = '\0';
	dat->buf[PBUFS + 1] = (ret < PBUFS) ? 0 : 1;
	dat->blist[0] = ft_blstnew(sizeof(t_w3dmap), 32);
	dat->data[0] = map;
	*map = w3d->default_cfg;
	map->height = (t_v2f){0.0f, 2.0f};
	if (ft_sscanf(dat->buf, "#map %*s %255s", cfg) == 1)
		w3d_parse_cfg(w3d, cfg, map);
	else
		map->flags = W3D_MAP_STATIC;
	dat->data[1] = ft_blststore(dat->blist[0], map);
	return (1);
}

static int		parse_loop(t_pdata *dat)
{
	char		sav;
	int			ret;

	sav = '\n';
	while ((ret = w3dp_nextline(dat)) >= 0)
	{
		if (!dat->c[ret])
			sav = '\0';
		dat->c[ret] = '\0';
		if (dat->c[0] == '[')
			w3dp_newmap(dat);
		else
			w3dp_mapline(dat);
		dat->c[ret] = sav;
	}
	return (1);
}

t_w3dl			w3d_parse_lvl(t_w3d *w3d, const char *path, t_w3dl layer)
{
	t_pdata		dat;
	int			fd;
	t_w3dmap	map;

	dat.error = 1;
	if (path && (path[0] == '@') && ft_filename_ext(w3d->paths.lvl_file,
		path + 1, ".w3dl", w3d->paths.lvl_len))
		path = w3d->paths.lvl_dir;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (layer);
	if ((dat.error = parse_init(w3d, &dat, &map)))
	{

	}
	close(fd);
	return (layer);
}
