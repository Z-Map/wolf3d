/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:49:04 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/03 01:02:15 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_v3f		w3d_getphymov(t_w3dlvl *lvl, t_w3dpc pc)
{
	const t_v2f		look = v4to2f(lvl->player.rotations);
	t_v3f			mv;
	t_ray			ray;

	mv = pc.movement;
	mv = (t_v3f){mv.x * look.x + mv.y * look.y,
		- mv.y * look.x + mv.x * look.y, 0.0f};
	mv.z = mv.x;
	ray = w3d_mkray((t_v2f){pc.position.x, pc.position.y + mv.y},
		(t_v2f){(mv.x > 0.0f) ? 1.0f : -1.0f, 0.0f},
		RAY_NOLAYER | W3D_BLOC_COLLIDER, mxabsf(mv.x) + 0.4f);
	if ((mv.x) && (w3d_raycast(lvl->lvl_data, &ray) > 0.0f))
		mv.x *= (ray.distance > 0.1f) ?
			(ray.distance - 0.1f) / (mxabsf(mv.x) + 0.3f) : 0.0f;
		// mv.x = 0.0f;
	ray = w3d_mkray((t_v2f){pc.position.x + mv.z, pc.position.y},
		(t_v2f){0.0f, (mv.y > 0.0f) ? 1.0f : -1.0f},
		RAY_NOLAYER | W3D_BLOC_COLLIDER, mxabsf(mv.y) + 0.4f);
	if ((mv.y) && (w3d_raycast(lvl->lvl_data, &ray) > 0.0f))
		mv.y *= (ray.distance > 0.1f) ?
			(ray.distance - 0.1f) / (mxabsf(mv.y) + 0.3f) : 0.0f;
		// mv.y = 0.0f;
	mv.z = 0.0f;
	return (mv);
}

void				w3d_update_player(t_w3d *w3d, t_w3dlvl *lvl)
{
	t_v3f			mv;

	lvl->player.fov.x = lvl->player.fov.y * w3d->render.ratio.y;
	w3d_update_pcmov(&(lvl->player));
	lvl->player.rotations = (t_v4f){cosf(lvl->player.look.x),
		sinf(lvl->player.look.x), cosf(lvl->player.look.y),
		sinf(lvl->player.look.y)};
	mv = w3d_getphymov(lvl, lvl->player);
	pv3faddv3f(&(lvl->player.position), &mv);
}

void				w3d_update_pcmov(t_w3dpc *player)
{
	static double	ltime = 0.0;
	float			ftime;

	ftime = (float)ltime;
	ltime = mglw_time();
	if (ftime > 0.0)
		ftime = (float)ltime - ftime;
	if (player->movkey & W3D_PCK_FW)
		player->movement.x = player->speed * ftime;
	else if (player->movkey & W3D_PCK_BW)
		player->movement.x = -player->speed * ftime;
	else
		player->movement.x = 0.0f;
	if (player->movkey & W3D_PCK_LE)
		player->movement.y = player->speed * ftime;
	else if (player->movkey & W3D_PCK_RI)
		player->movement.y = -player->speed * ftime;
	else
		player->movement.y = 0.0f;
	if (player->movkey & W3D_PCK_LLE)
		player->look.x -= player->speed * ftime;
	else if (player->movkey & W3D_PCK_LRI)
		player->look.x += player->speed * ftime;
}
