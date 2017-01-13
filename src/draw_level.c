/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:55:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/12 22:11:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			draw_col(mglimg *scr, int column, int height, t_rgba color)
{
	const int		offset = (scr->y - height) / 2;
	unsigned char	*pxs;
	unsigned int	y;

	pxs = scr->pixels;
	if (offset > 0)
	{
		y = offset;
		while (height--)
		{
			pxs[(column + y * scr->x) * 4] = color.r;
			pxs[(column + y * scr->x) * 4 + 1] = color.g;
			pxs[(column + y * scr->x) * 4 + 2] = color.b;
			pxs[(column + y * scr->x) * 4 + 3] = color.a;
		}
	}
}

int				w3d_draw_lvl(t_w3dl *lay, t_w3d *w3d)
{
	int			x;
	float		angle;
	float		rot;
	float		dist;
	t_ray		ray;

	(void)lay;
	x = w3d->screen->x;
	angle = 0.785398f;
	rot = 1.5708f / (float)x;
	ray = (t_ray){.start = (t_v2f){5.5f, 5.5f}, .dir = (t_v2f){0.0f, 1.0f},
		.end = (t_v2f){0.0f, 0.0f}, .grid_id = (t_v2ui){0, 0},
		.normale = (t_v3f){0.0f, 0.0f, 0.0f}, .distance = 0.0f};
	while (x--)
	{
		ray.dir = (t_v2f){cosf(angle), sinf(angle)};
		dist = w3d_raycast(lay->level.lvl_data, &ray);
		if (dist > 0.0f)
			draw_col(w3d->screen, x, round((float)(w3d->screen->y) / dist),
				lay->level.lvl_data->blocs[	lay->level.lvl_data->grid[
					ray.grid_id.x][ray.grid_id.y]].color);
		angle += rot;
	}
	return (0);
}
