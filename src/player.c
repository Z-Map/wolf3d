/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:49:04 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 13:13:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"

static t_v3f		w3d_getphymov(t_w3dlvl *lvl, t_w3dpc pc)
{
	const t_v2f		look = v4to2f(lvl->player.rotations);
	t_v3f			mv;
	t_ray			ray;
	t_w3dmap		*map;

	map = &(lvl->lvl_data[lvl->active_lvl]);
	mv = pc.movement;
	mv = (t_v3f){mv.x * look.x + mv.y * look.y,
		-mv.y * look.x + mv.x * look.y, 0.0f};
	mv.z = mv.x;
	ray = w3d_mkray((t_v2f){pc.position.x, pc.position.y + mv.y},
		(t_v2f){(mv.x > 0.0f) ? 1.0f : -1.0f, 0.0f},
		RAY_NOLAYER | W3D_BLOC_COLLIDER, mxabsf(mv.x) + 0.4f);
	if ((mv.x) && (w3d_raycast(map, &ray) > 0.0f))
		mv.x *= (ray.distance > 0.1f) ?
			(ray.distance - 0.1f) / (mxabsf(mv.x) + 0.3f) : 0.0f;
	ray = w3d_mkray((t_v2f){pc.position.x + mv.z, pc.position.y},
		(t_v2f){0.0f, (mv.y > 0.0f) ? 1.0f : -1.0f},
		RAY_NOLAYER | W3D_BLOC_COLLIDER, mxabsf(mv.y) + 0.4f);
	if ((mv.y) && (w3d_raycast(map, &ray) > 0.0f))
		mv.y *= (ray.distance > 0.1f) ?
			(ray.distance - 0.1f) / (mxabsf(mv.y) + 0.3f) : 0.0f;
	mv.z = 0.0f;
	return (mv);
}

void				w3d_update_player(t_w3d *w3d, t_w3dlvl *lvl)
{
	t_v3f			mv;
	float			s;

	lvl->player.fov.x = lvl->player.fov.y * w3d->render.ratio.y;
	s = lvl->player.speed * ((lvl->player.movkey & W3D_PCK_SPEED) ? 2.0f : 1);
	w3d_update_pcmov(&(lvl->player), s);
	lvl->player.rotations = (t_v4f){cosf(lvl->player.look.x),
		sinf(lvl->player.look.x), cosf(lvl->player.look.y),
		sinf(lvl->player.look.y)};
	mv = w3d_getphymov(lvl, lvl->player);
	pv3faddv3f(&(lvl->player.position), &mv);
}

void				w3d_update_pcmov(t_w3dpc *player, float speed)
{
	static double	ltime = 0.0;
	float			ftime;

	ftime = (float)ltime;
	ltime = mglw_time();
	if (ftime > 0.0)
		ftime = (float)ltime - ftime;
	if (player->movkey & W3D_PCK_FW)
		player->movement.x = speed * ftime;
	else if (player->movkey & W3D_PCK_BW)
		player->movement.x = -speed * ftime;
	else
		player->movement.x = 0.0f;
	if (player->movkey & W3D_PCK_LE)
		player->movement.y = speed * ftime;
	else if (player->movkey & W3D_PCK_RI)
		player->movement.y = -speed * ftime;
	else
		player->movement.y = 0.0f;
	if (player->movkey & W3D_PCK_LLE)
		player->look.x -= player->speed * ftime * 0.80f;
	else if (player->movkey & W3D_PCK_LRI)
		player->look.x += player->speed * ftime * 0.80f;
}

t_v2i				w3d_find_playerstart(t_w3dmap *map)
{
	t_v2i			pos1;
	t_v2i			pos2;
	int				i;
	int				j;
	t_w3dbox		*b;

	pos1 = (t_v2i){-1, -1};
	pos2 = (t_v2i){0, 0};
	i = map->size.y;
	while (i--)
	{
		j = map->size.x;
		while (j--)
		{
			b = w3dlvl_getbox(map, i, j, 0);
			if (b && (b->flags & W3D_BLOC_PLAYER))
				pos1 = ((pos1.x == -1) ||
					((rand() % 10) > 5)) ? (t_v2i){i, j} : pos1;
			if (b && !(b->flags & W3D_BLOC_COLLIDER))
				pos2 = (t_v2i){i, j};
		}
	}
	return ((pos1.x >= 0) ? pos1 : pos2);
}
