/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:37:57 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/31 15:43:29 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_ray			w3d_rayloopy(t_w3dmap *map, t_ray ray)
{
	t_v2i		idx;
	int			dir;
	t_ul		lay;
	t_w3dbox	*bloc;
	float		dist;

	if (!(lay = w3d_raystart(map, &ray, NULL, &idx)))
		return (w3d_rayend(ray, NULL, NULL, -1.0f));
	dir = (ray.dir.y > 0.0f) ? 1 : -1;
	idx.y += dir;
	while (w3dlvl_in(map, idx))
	{
		if ((bloc = w3dlvl_getbox_vi(map, idx)) && !(bloc->layer & lay))
		{
			ray.normale = (t_v3f){0.0f, -(float)dir, 0.0f};
			dist = mxabsf((float)((dir < 0) ? idx.y + 1 : idx.y) - ray.start.y);
			if ((ray.distance > 0.0f) && (dist > ray.distance))
				break ;
			return (w3d_rayend(ray, &idx, bloc, dist));
		}
		idx.y += dir;
	}
	return (w3d_rayend(ray, NULL, NULL, -1.0f));
}

t_ray			w3d_rayloopx(t_w3dmap *map, t_ray ray)
{
	t_v2i		idx;
	int			dir;
	t_ul		lay;
	t_w3dbox	*bloc;
	float		dist;

	if (!(lay = w3d_raystart(map, &ray, NULL, &idx)))
		return (w3d_rayend(ray, NULL, NULL, -1.0f));
	dir = (ray.dir.x > 0.0f) ? 1 : -1;
	idx.x += dir;
	while (w3dlvl_in(map, idx))
	{
		if ((bloc = w3dlvl_getbox_vi(map, idx)) && !(bloc->layer & lay))
		{
			ray.normale = (t_v3f){-(float)dir, 0.0f, 0.0f};
			dist = mxabsf((float)((dir < 0) ? idx.x + 1 : idx.x) - ray.start.x);
			if ((ray.distance > 0.0f) && (dist > ray.distance))
				break ;
			return (w3d_rayend(ray, &idx, bloc, dist));
		}
		idx.x += dir;
	}
	return (w3d_rayend(ray, NULL, NULL, -1.0f));
}

static int		rl_process(t_w3dmap *map, t_ray *ray, t_v3f *pos, t_v2i *idx)
{
	t_v4f		dist;

	dist = (t_v4f){mxabsf(pos->x / ray->dir.x), mxabsf(pos->y / ray->dir.y),
		0.0f, 0.0f};
	if (dist.x < dist.y)
	{
		dist.z = (ray->dir.x < 0.0) ? -1.0 : 1.0;
		pos->z = dist.x;
		pos->x += dist.z;
		idx->x += (int)dist.z;
		ray->normale = (t_v3f){-dist.z, 0.0f, 0.0f};
	}
	else
	{
		dist.w = (ray->dir.y < 0.0) ? -1.0 : 1.0;
		pos->z = dist.y;
		pos->y += dist.w;
		idx->y += (int)dist.w;
		ray->normale = (t_v3f){0.0f, -dist.w, 0.0f};
	}
	if (!w3dlvl_in(map, *idx))
		return (0);
	return (1);
}

t_ray			w3d_rayloop(t_w3dmap *map, t_ray ray)
{
	t_v3f		pos;
	t_v2i		idx;
	t_ul		lay;
	t_w3dbox	*bloc;

	if (!(lay = w3d_raystart(map, &ray, &pos, &idx)))
		return (w3d_rayend(ray, NULL, NULL, -1.0f));
	while (rl_process(map, &ray, &pos, &idx)
		&& ((ray.distance <= 0.0f) || (pos.z <= ray.distance)))
	{
		if ((bloc = w3dlvl_getbox_vi(map, idx)) && (
			(ray.flags & (t_ul)bloc->flags) ||
			(!(ray.flags & RAY_NOLAYER) && !(bloc->layer & lay))))
			return (w3d_rayend(ray, &idx, bloc, pos.z));
	}
	return (w3d_rayend(ray, NULL, NULL, -1.0f));
}

// static int		inrange(t_w3dmap *map, t_v2i idx)
// {
// 	if ((idx.x < 0) || (idx.y < 0))
// 		return (0);
// 	else if ((idx.x < (int)map->size.x) || (idx.y < (int)map->size.y))
// 		return (1);
// 	return (0);
// }

float			w3d_raycast(t_w3dmap *map, t_ray *ray)
{
	t_ray		tr;

	if (ray->dir.y == 0.0f)
		tr = w3d_rayloopx(map, *ray);
	if (ray->dir.x == 0.0f)
		tr = w3d_rayloopy(map, *ray);
	else
		tr = w3d_rayloop(map, *ray);
	if (tr.distance >= 0.0f)
		*ray = tr;
	return (tr.distance);
}
// float			w3d_raycast(t_w3dmap *map, t_ray *ray)
// {
// 	t_v2ui		idx;
// 	t_v2i		nidx;
// 	t_w3dbox	*box;
//
// 	nidx = (t_v2i){(int)(ray->start.x), (int)(ray->start.y)};
// 	idx = (t_v2ui){(unsigned int)nidx.x, (unsigned int)nidx.y};
// 	ray->distance = w3d_rayboxstep(ray, &nidx);
// 	box = w3dlvl_getbox_vui(map, idx);
// 	while (inrange(map, nidx) && box && !(box->flags & W3D_BLOC_WALL))
// 	{
// 		idx = (t_v2ui){(unsigned int)nidx.x, (unsigned int)nidx.y};
// 		box = w3dlvl_getbox_vui(map, idx);
// 		if ((!box) || (box->flags & W3D_BLOC_WALL))
// 			break ;
// 		ray->distance = w3d_rayboxstep(ray, &nidx);
// 	}
// 	ray->grid_id = idx;
// 	if (!box || !(box->flags & W3D_BLOC_WALL))
// 		ray->distance = -1.0f;
// 	else
// 		ray->end = (t_v2f){ray->start.x + (ray->distance * ray->dir.x),
// 			ray->start.y + (ray->distance * ray->dir.y)};
// 	ray->bloc = box;
// 	return (ray->distance);
// }
