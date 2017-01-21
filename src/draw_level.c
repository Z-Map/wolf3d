/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:55:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/20 16:12:31 by qloubier         ###   ########.fr       */
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
	y = 0;
	if (offset > 0)
		y = (unsigned int)offset;
	else
		height = (int)scr->y;
	while (height--)
	{
		// ft_printf("px : %i, %i\n", column, y);
		pxs[(column + y * scr->x) * 4] = color.r;
		pxs[(column + y * scr->x) * 4 + 1] = color.g;
		pxs[(column + y * scr->x) * 4 + 2] = color.b;
		pxs[(column + y * scr->x) * 4 + 3] = 255;
		y++;
	}
}

void			w3d_process_mov(t_w3dpc *player)
{
	if (player->movkey & W3D_PCK_FW)
		player->movement.x = player->speed;
	else if (player->movkey & W3D_PCK_BW)
		player->movement.x = -(player->speed);
	else
		player->movement.x = 0.0f;
	if (player->movkey & W3D_PCK_LE)
		player->movement.y = player->speed;
	else if (player->movkey & W3D_PCK_RI)
		player->movement.y = -player->speed;
	else
		player->movement.y = 0.0f;
	if (player->movkey & W3D_PCK_LLE)
		player->look.x += player->speed;
	else if (player->movkey & W3D_PCK_LRI)
		player->look.x -= player->speed;
}

int				w3d_draw_lvl(t_w3dl *lay, t_w3d *w3d)
{
	const float	fov = 1.047197551f;
	int			x;
	double		angle;
	double		rot;
	double		a;
	float		dist;
	t_ray		ray;
	t_v3f		mv;
	t_v2f		look;

	look = (t_v2f){cosf(lay->level.player.look.x),
		sinf(lay->level.player.look.x)};
	(void)lay;
	x = w3d->screen->x;
	angle = -sin(fov / 2.0f);
	rot = (angle * -2.0f) / (double)x;
	w3d_process_mov(&(lay->level.player));
	mv = lay->level.player.movement;
	mv = (t_v3f){mv.x * look.x - mv.y * look.y,
		mv.y * look.x + mv.x * look.y, 0.0f};
	pv3faddv3f(&(lay->level.player.position), &mv);
	// lay->level.player.movement = (t_v3f){0.0f, 0.0f, 0.0f};
	ray = (t_ray){.start = v3to2f(lay->level.player.position),
		.dir = (t_v2f){0.0f, 1.0f}, .end = (t_v2f){0.0f, 0.0f},
		.grid_id = (t_v2ui){0, 0}, .normale = (t_v3f){0.0f, 0.0f, 0.0f},
		.distance = 0.0f};
	ft_bzero(w3d->screen->pixels, w3d->screen->memlen);
	while (x--)
	{
		a = asin(angle);
		ray.dir = normalize2f((t_v2f){look.x - (float)angle * look.y,
			look.x * (float)angle + look.y});
		dist = w3d_raycast(lay->level.lvl_data, &ray);
		dist *= normalize2f((t_v2f){1.0, (float)angle}).x;
		// dist *= (float)cos(a);
		// ft_printf("coucou : % 6.4f\e[20D", cosf((float)angle));
		if (dist > 0.0f)
			draw_col(w3d->screen, x,
				round((2.0f / dist) * ((float)w3d->screen->y) / 2.0f),
				lay->level.lvl_data->blocs[lay->level.lvl_data->grid[
					ray.grid_id.y][ray.grid_id.x]].color);
		// else if (dist > 0.0f)
		// 	draw_col(w3d->screen, x, w3d->screen->y,
		// 		lay->level.lvl_data->blocs[lay->level.lvl_data->grid[
		// 			ray.grid_id.y][ray.grid_id.x]].color);
		else
			draw_col(w3d->screen, x, 5, (t_rgba){255,0,0,255});
		angle += rot;
	}
	return (0);
}
