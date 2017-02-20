/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 14:20:09 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/20 05:00:02 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			w3d_drawimg(t_w3d *w3d, int x, int y, mglimg *img)
{
	t_v3i		t;
	t_v2i		p;

	t = (t_v3i){img->x , img->y, img->x};
	x += (x < 0) ? w3d->gui->x : img->x;
	y += (y < 0) ? w3d->gui->y : img->y;
	if (x > (int)w3d->gui->x)
		t.z -= x - w3d->gui->x;
	if (y > (int)w3d->gui->y)
		t.y -= y - w3d->gui->y;
	if ((x <= 0) || (y <= 0) || (t.y <= 0) || (t.x <= 0))
		return ;
	p = (t_v2i){x, y};
	while ((p.y-- > 0) && (t.y-- > 0))
	{
		p.x = x;
		t.x = t.z;
		while ((p.x-- > 0) && (t.x-- > 0))
			((t_ui *)(w3d->gui->pixels))[p.x + (p.y * w3d->gui->x)] =
				((t_ui *)(img->pixels))[t.x + (t.y * img->x)];
	}
}
