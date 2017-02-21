/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:10:34 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/21 22:43:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"

int				w3d_getblocfromid(t_w3dmap *map, int id)
{
	int				i;

	i = (int)map->bloclen - 1;
	while ((i >= 0) && (map->blocs[i].userid != id))
		--i;
	return (i);
}

int				w3d_allkeyfound(t_w3dmap *map)
{
	t_v2i			i;
	t_w3dbox		*bloc;

	i = (t_v2i){(int)map->size.x, (int)map->size.y};
	while (i.y-- > 0)
	{
		i.x = (int)map->size.x;
		while (i.x-- > 0)
		{
			bloc = w3dlvl_getbox_vi(map, i, 0);
			if ((bloc->flags & W3D_BLOC_KEY) &&
				!(map->grid[i.y][i.x].flags & W3D_BLOC_VISITED))
				return (0);
		}
	}
	return (1);
}

void			w3dlvl_free(t_w3dlvl *lvl, t_w3d *w3d)
{
	int				i;
	t_w3dmap		*map;

	i = lvl->level_num;
	while (i--)
	{
		map = lvl->lvl_data + i;
		if (map->grid)
			free(map->grid);
		if (map->bloclen)
			w3d_rmlayout(w3d, map);
	}
	free(lvl->lvl_data);
}

static void		minimap_player(t_w3dlvl *lvl, const t_w3dmap *m, t_w3d *w3d)
{
	t_v2ui			t;

	t = (t_v2ui){w3d->gui->x - (t_ui)(((float)m->size.x
		- lvl->player.position.x) * 6), (t_ui)(lvl->player.position.y * 6)};
	if ((t.x < w3d->gui->x) && (t.y < w3d->gui->y))
	{
		if (t.x > 1)
			w3d_setpx(w3d->gui, t.x - 1, t.y, 0xffffffff);
		if ((t.x + 1) < w3d->gui->x)
			w3d_setpx(w3d->gui, t.x + 1, t.y, 0xffffffff);
		if (t.y > 1)
			w3d_setpx(w3d->gui, t.x, t.y - 1, 0xffffffff);
		if ((t.y + 1) < w3d->gui->y)
			w3d_setpx(w3d->gui, t.x, t.y + 1, 0xffffffff);
		if ((t.x > 1) && (t.y > 1))
			w3d_setpx(w3d->gui, t.x - 1, t.y - 1, 0xffffffff);
		if (((t.x + 1) < w3d->gui->x) && (t.y > 1))
			w3d_setpx(w3d->gui, t.x + 1, t.y - 1, 0xffffffff);
		if ((t.x > 1) && ((t.y + 1) < w3d->gui->y))
			w3d_setpx(w3d->gui, t.x - 1, t.y + 1, 0xffffffff);
		if (((t.y + 1) < w3d->gui->y) && ((t.x + 1) < w3d->gui->x))
			w3d_setpx(w3d->gui, t.x + 1, t.y + 1, 0xffffffff);
		w3d_setpx(w3d->gui, t.x, t.y, 0xffffffff);
	}
}

void			w3d_drawminimap(t_w3dlvl *lvl, t_w3d *w3d)
{
	const t_w3dmap	*m = &(lvl->lvl_data[lvl->active_lvl]);
	t_v2i			p;
	t_v2ui			t;
	t_w3dbox		*bloc;

	t = (t_v2ui){mxminu(m->size.x * 6, w3d->gui->x),
		mxminu(m->size.y * 6, w3d->gui->y - 1)};
	p = (t_v2i){w3d->gui->x, t.y};
	while (p.x-- > 0 && (t.x--))
		w3d_setpx(w3d->gui, p.x, p.y, 0xff000000);
	while ((p.y-- > 0) && (t.y-- > 0))
	{
		p.x = w3d->gui->x;
		t.x = mxminu(m->size.x * 6, w3d->gui->x);
		while ((p.x-- > 0) && (t.x-- > 0))
			w3d_setpx(w3d->gui, p.x, p.y, ((bloc = w3dlvl_getbox_ui(m,
				t.x / 6, t.y / 6, 0)) && ((m->grid)[t.y / 6][t.x / 6].flags
				& W3D_BLOC_VISITED)) ? *((t_ui *)&(bloc->color)) : 0xd0000000);
		if (p.x >= 0)
			w3d_setpx(w3d->gui, p.x, p.y, 0xff000000);
	}
	if (w3dlvl_in((t_w3dmap *)m, (t_v2i){(int)lvl->player.position.x,
		(int)lvl->player.position.y}))
		minimap_player(lvl, m, w3d);
}
