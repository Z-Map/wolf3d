/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:31:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/15 03:07:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			w3d_set_evtflags(t_ui *flags, t_w3devt evt, t_ui flag)
{
	if (evt.status == 0)
		*flags &= ~flag;
	else
		*flags |= flag;
}

int				w3d_event_process_lvl(t_w3dl *lay, t_w3d *w3d, t_w3devt evt)
{
	(void)w3d;
	if (evt.keycode == MGLW_KEY_LEFT)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_LLE);
	if (evt.keycode == MGLW_KEY_RIGHT)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_LRI);
	if (evt.keycode == MGLW_KEY_W)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_FW);
	if (evt.keycode == MGLW_KEY_S)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_BW);
	if (evt.keycode == MGLW_KEY_A)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_LE);
	if (evt.keycode == MGLW_KEY_D)
		w3d_set_evtflags(&(lay->level.player.movkey), evt, W3D_PCK_RI);
	return (0);
}
