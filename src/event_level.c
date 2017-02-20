/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:31:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/20 17:19:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			w3d_set_evtflags(t_ui *flags, t_w3devt evt, t_ui flag)
{
	static int	active[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int			i;
	int			c;

	if (!flag)
		return ;
	i = -1;
	c = flag;
	while ((i++ < 31) && !(c & 1))
		c >>= 1;
	if (evt.status == 0)
	{
		active[i]--;
		if (!active[i])
			*flags &= ~flag;
	}
	else
	{
		active[i]++;
		if (active[i])
			*flags |= flag;
	}
}

int				w3d_event_process_lvl(t_w3dl *lay, t_w3d *w3d, t_w3devt evt)
{
	(void)w3d;
	if (evt.keycode == MGLW_KEY_LEFT)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_LLE);
	if (evt.keycode == MGLW_KEY_RIGHT)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_LRI);
	if ((evt.keycode == MGLW_KEY_W) || (evt.keycode == MGLW_KEY_UP))
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_FW);
	if ((evt.keycode == MGLW_KEY_S) || (evt.keycode == MGLW_KEY_DOWN))
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_BW);
	if (evt.keycode == MGLW_KEY_A)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_LE);
	if (evt.keycode == MGLW_KEY_D)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_RI);
	if (evt.keycode == MGLW_KEY_LEFT_SHIFT)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_SPEED);
	return (0);
}

int				w3dlvl_next(t_w3dlvl *lvl, t_w3d *w3d)
{
	t_v2i		ppos;
	t_w3dmap	*map;

	lvl->active_lvl++;
	ft_bzero(w3d->gui->pixels, w3d->gui->memlen);
	if (lvl->active_lvl == lvl->level_num)
		return (0);
	map = &(lvl->lvl_data[lvl->active_lvl]);
	ppos = w3d_find_playerstart(map);
	lvl->player.position.x = (float)ppos.x + 0.5f;
	lvl->player.position.y = (float)ppos.y + 0.5f;
	w3d_drawimg(w3d, 10, -10, w3d->helpimg);
	return (1);
}

void			w3dlvl_mainloop(t_w3dlvl *lvl, t_w3d *w3d)
{
	t_v2i		ppos;
	t_w3dmap	*map;
	t_w3dbox	*bloc;

	map = &(lvl->lvl_data[lvl->active_lvl]);
	ppos = (t_v2i){(int)lvl->player.position.x, (int)lvl->player.position.y};
	bloc = w3dlvl_getbox_vi(map, ppos, 0);
	if (w3d_allkeyfound(map))
	{
		w3d_drawimg(w3d, 10, 10, w3d->openimg);
		if (bloc && (bloc->flags & W3D_BLOC_EXIT) && !w3dlvl_next(lvl, w3d))
			w3d->flags |= W3D_WIN;
	}
}
