/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:55:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/13 20:22:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			draw_col(mglimg *scr, int column, int height, t_rgba color)
{
	const int		offset = ((int)scr->y - height) / 2;
	unsigned char	*pxs;
	unsigned int	y;

	// ft_printf("base : %u, %i\noffset : %i\n", scr->y, height, offset);
	pxs = scr->pixels;
	if (offset > 0)
	{
		y = offset;
		while (height--)
		{
			// ft_printf("px : %i, %i\n", column, y);
			pxs[(column + y * scr->x) * 4] = color.r;
			pxs[(column + y * scr->x) * 4 + 1] = color.g;
			pxs[(column + y * scr->x) * 4 + 2] = color.b;
			pxs[(column + y * scr->x) * 4 + 3] = color.a;
			y++;
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
	ft_bzero(w3d->screen->pixels, w3d->screen->memlen);
	while (x--)
	{
		ray.dir = (t_v2f){cosf(lay->level.player.look.x - angle),
			sinf(lay->level.player.look.x - angle)};
		dist = w3d_raycast(lay->level.lvl_data, &ray) *
			cosf(mxabsf(angle - 1.5708f));
		if (dist > 1.0f)
			draw_col(w3d->screen, x, round((float)(w3d->screen->y) / dist),
				lay->level.lvl_data->blocs[	lay->level.lvl_data->grid[
					ray.grid_id.y][ray.grid_id.x]].color);
		else if (dist > 0.0f)
			draw_col(w3d->screen, x, w3d->screen->y, (t_rgba){0,0,255,255});
				// lay->level.lvl_data->blocs[	lay->level.lvl_data->grid[
				// 	ray.grid_id.y][ray.grid_id.x]].color);
		else
			draw_col(w3d->screen, x, 5, (t_rgba){255,0,0,255});
		angle += rot;
	}
	return (0);
}
