/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:55:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/23 09:50:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			draw_col(mglimg *scr, int column, int height, t_ray *ray)
{
	const int		offset = ((int)scr->y - height) / 2;
	size_t			px;
	unsigned char	*pxs;
	unsigned int	y;
	int				tx, ty;
	float			uva, uvb;

	// ft_printf("base : %u, %i\noffset : %i\n", scr->y, height, offset);
	if (ray->bloc->tex)
		tx = (int)((((ray->end.x  + ray->end.y) * 0.5f)
		- (float)(int)((ray->end.x + ray->end.y) * 0.5f)) * ray->bloc->tex->x);
	uva = 1.0 / (height + 1);
	uvb = 0.0;
	pxs = scr->pixels;
	y = 0;
	if (offset > 0)
		y = (unsigned int)offset;
	else
	{
		uvb = -offset * uva;
		height = (int)scr->y;
	}
	while (height--)
	{
		// ft_printf("px : %i, %i\n", column, y);
		px = column + y * scr->x;
		if (ray->bloc->tex)
		{
			ty = (int)roundf(uvb * ray->bloc->tex->y) % ray->bloc->tex->y;
			((unsigned int *)pxs)[px] = ((unsigned int *)(
				ray->bloc->tex->pixels))[tx + (ty * ray->bloc->tex->x)];
			uvb += uva;
		}
		else
		{
			pxs[px * 4] = ray->bloc->color.r;
			pxs[px * 4 + 1] = ray->bloc->color.g;
			pxs[px * 4 + 2] = ray->bloc->color.b;
			pxs[px * 4 + 3] = 255;
		}
		y++;
	}
}

void			w3d_process_mov(t_w3dpc *player)
{
	if (player->movkey & W3D_PCK_FW)
		player->movement.x = player->speed;
	else if (player->movkey & W3D_PCK_BW)
		player->movement.x = -player->speed;
	else
		player->movement.x = 0.0f;
	if (player->movkey & W3D_PCK_LE)
		player->movement.y = player->speed;
	else if (player->movkey & W3D_PCK_RI)
		player->movement.y = -player->speed;
	else
		player->movement.y = 0.0f;
	if (player->movkey & W3D_PCK_LLE)
		player->look.x -= player->speed;
	else if (player->movkey & W3D_PCK_LRI)
		player->look.x += player->speed;
}

int				w3d_draw_lvl(t_w3dl *lay, t_w3d *w3d)
{
	const float	fov = 1.047197551f;
	int			x;
	double		angle;
	double		rot;
	t_v2f		a;
	float		dist;
	t_ray		ray;
	t_v3f		mv;
	t_v2f		look;

	look = (t_v2f){cosf(lay->level.player.look.x),
		sinf(lay->level.player.look.x)};
	(void)lay;
	x = w3d->screen->x;
	angle = -sin(fov / 2.0f);
	rot = (angle * -2.0) / (double)x;
	w3d_process_mov(&(lay->level.player));
	mv = lay->level.player.movement;
	mv = (t_v3f){mv.x * look.x + mv.y * look.y,
		- mv.y * look.x + mv.x * look.y, 0.0f};
	pv3faddv3f(&(lay->level.player.position), &mv);
	// lay->level.player.movement = (t_v3f){0.0f, 0.0f, 0.0f};
	ray = (t_ray){.start = v3to2f(lay->level.player.position),
		.dir = (t_v2f){0.0f, 1.0f}, .end = (t_v2f){0.0f, 0.0f},
		.grid_id = (t_v2ui){0, 0}, .normale = (t_v3f){0.0f, 0.0f, 0.0f},
		.distance = 0.0f, .bloc = NULL};
	ft_bzero(w3d->screen->pixels, w3d->screen->memlen);
	while (x--)
	{
		a = normalize2f((t_v2f){(float)cos(fov / 2.0f), (float)angle});
		ray.dir = (t_v2f){look.x * a.x + a.y * look.y,
			-look.x * a.y + look.y * a.x};
		dist = w3d_raycast(lay->level.lvl_data, &ray);
		dist *= (float)a.x;
		// dist *= (float)cos(a);
		// ft_printf("coucou : % 6.4f\e[20D", cosf((float)angle));
		// ray.end = (t_v2f){ ray.start.x + ray.dir.x * dist,
		// 	ray.start.y + ray.dir.y * dist};
		if (dist > 0.0f)
			draw_col(w3d->screen, x,
				round(((2.0 * w3d->screen->y) / dist)), &ray);
		// else if (dist > 0.0f)
		// 	draw_col(w3d->screen, x, w3d->screen->y,
		// 		lay->level.lvl_data->blocs[lay->level.lvl_data->grid[
		// 			ray.grid_id.y][ray.grid_id.x]].color);
		// else
		// 	draw_col(w3d->screen, x, 5, (t_rgba){255,0,0,255});
		angle += rot;
	}
	return (0);
}
