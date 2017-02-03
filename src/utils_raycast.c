/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 20:08:57 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/03 00:04:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		clip_val(int dim, float d, t_ray *ray, t_v2i *idx)
{
	t_v2f		pos;

	pos.x = ray->start.x + (d * ray->dir.x);
	pos.y = ray->start.y + (d * ray->dir.y);
	if ((pos.x < -0.001) || (pos.y < -0.001))
		return (0);
	*idx = (t_v2i){(int)pos.x, (int)pos.y};
	if ((dim == 0) && (!idx->x))
		idx->x = -1;
	else if ((dim == 1) && (!idx->y))
		idx->y = -1;
	return (1);
}

static int		get_startidx(t_v2ui size, t_ray *ray, t_v2i *idx)
{
	t_v4f		d;

	d = (t_v4f){-INFINITY, -INFINITY, INFINITY, INFINITY};
	if (ray->dir.x)
		d = (t_v4f){(-ray->start.x) / ray->dir.x, -INFINITY,
			((float)size.x - ray->start.x) / ray->dir.x, INFINITY};
	if (ray->dir.y)
		d = (t_v4f){d.x, (-ray->start.y) / ray->dir.y, d.z,
			((float)size.y - ray->start.y) / ray->dir.y};
	if (d.x > d.z)
		swapf(&(d.x), &(d.z));
	if (d.y > d.w)
		swapf(&(d.y), &(d.w));
	if ((!ray->dir.x) || ((d.y >= 0.0f) && (d.y >= d.x) && (d.y <= d.z)))
		return (clip_val(1, d.y, ray, idx));
	else if ((!ray->dir.y) || ((d.x >= 0.0f) && (d.x >= d.y) && (d.x <= d.w)))
		return (clip_val(0, d.x, ray, idx));
	return (0);
}

t_ul			w3d_raystart(t_w3dmap *map, t_ray *ray, t_v3f *pos, t_v2i *idx)
{
	t_w3dbox	*bloc;

	*idx = (t_v2i){(int)ray->start.x, (int)ray->start.y};
	idx->x -= (ray->start.x < 0.0f) ? 1 : 0;
	idx->y -= (ray->start.y < 0.0f) ? 1 : 0;
	if (!w3dlvl_in(map, *idx) && !get_startidx(map->size, ray, idx))
		return (0);
	if (pos)
	{
		*pos = (t_v3f){(float)idx->x - ray->start.x,
			(float)idx->y - ray->start.y, 0.0f};
		if (ray->dir.x > 0.0f)
			pos->x += 1.0f;
		if (ray->dir.y > 0.0f)
			pos->y += 1.0f;
	}
	if (!(bloc = w3dlvl_getbox_vi(map, *idx)))
		return (1);
	return (bloc->layer);
}


t_ray			w3d_rayend(t_ray ray, t_v2i *idx, t_w3dbox *bloc, float dist)
{
	if (idx)
		ray.grid_id = (t_v2ui){(t_ui)idx->x, (t_ui)idx->y};
	ray.bloc = bloc;
	ray.distance = dist;
	if (dist >= 0.0f)
	{
		ray.end.x = ray.start.x + (dist * ray.dir.x);
		ray.end.y = ray.start.y + (dist * ray.dir.y);
	}
	return (ray);
}
