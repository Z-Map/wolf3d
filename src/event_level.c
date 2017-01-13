/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:31:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/13 20:23:37 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				w3d_event_process_lvl(t_w3dl *lay, t_w3d *w3d, t_w3devt evt)
{
	(void)w3d;
	if (evt.keycode == MGLW_KEY_LEFT)
		lay->level.player.look.x -= 0.05f;
	if (evt.keycode == MGLW_KEY_RIGHT)
		lay->level.player.look.x += 0.05f;
	return (0);
}
