/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:55:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/06 18:30:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				w3d_draw_lvl(t_w3dl *lay, t_w3d *w3d)
{
	unsigned char	*pxs;

	(void)lay;
	pxs = w3d->screen->pixels;
	unsigned int x, y;
	for (y = 0; y < w3d->screen->y; y++)
	{
		for (x = 0; x < w3d->screen->x; x++)
		{
			pxs[(x + y * w3d->screen->x) * 4] += 1;
			pxs[(x + y * w3d->screen->x) * 4 + 1] += 2;
			pxs[(x + y * w3d->screen->x) * 4 + 2] += 3;
			pxs[(x + y * w3d->screen->x) * 4 + 3] = 255;
		}
	}
	return (0);
}
