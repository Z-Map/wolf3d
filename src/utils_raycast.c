/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 20:08:57 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/31 17:27:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		get_startidx(t_v2ui size, t_ray *ray, t_v2i *idx)
{
	t_v4f		d;

	d = (t_v4f){-1.0f, -1.0f, -1.0f, -1.0f};
	if (ray->dir.x)
		d = (t_v4f){(-ray->start.x) / ray->dir.x, -1.0f,
			((float)size.x - ray->start.x) / ray->dir.x, -1.0f};
	if (ray->dir.y)
		d = (t_v4f){d.x, (-ray->start.y) / ray->dir.y, d.z,
			((float)size.y - ray->start.y) / ray->dir.y};
	if ((d.x < 0.0) || ((d.z >= 0.0) && (d.z < d.x)))
		d.x = d.z;
	if ((d.y < 0.0) || ((d.w >= 0.0) && (d.w < d.y)))
		d.y = d.w;
	d.w = (((ray->start.x < 0.0) && (ray->start.y < 0.0))
		|| ((ray->start.x >= size.x) && (ray->start.y >= size.y))
		|| ((ray->start.x < 0.0) && (ray->start.y >= size.y))
		|| ((ray->start.x >= size.x) && (ray->start.y < 0.0))) ? 0.0 : 1.0;
	d.z = d.y;
	if ((d.x < 0.0f) && (d.y < 0.0f))
		return (0);
	else if (((d.x < d.y) && (d.w == 1.0)) || ((d.x > d.y) && (d.w == 0.0)))
		d.z = d.x;
	idx->x = (int)(ray->start.x + (d.z * ray->dir.x));
	idx->y = (int)(ray->start.y + (d.z * ray->dir.y));
	return (1);
}

t_ul			w3d_raystart(t_w3dmap *map, t_ray *ray, t_v3f *pos, t_v2i *idx)
{
	t_w3dbox	*bloc;

	*idx = (t_v2i){(int)ray->start.x, (int)ray->start.y};
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


float			w3d_rayboxstep(const t_ray *ray, t_v2i *idx)
{
	t_v2f		pos;

	pos = (t_v2f){(float)idx->x - ray->start.x, (float)idx->y - ray->start.y};
	if (ray->dir.x > 0.0f)
		pos.x += 1.0f;
	if (ray->dir.y > 0.0f)
		pos.y += 1.0f;
	if ((ray->dir.x == 0.0f) || (ray->dir.y == 0.0f))
	{
		idx->x += (int)ray->dir.x;
		idx->y += (int)ray->dir.y;
		return ((ray->dir.x) ? ray->dir.x * pos.x : ray->dir.y * pos.y);
	}
	else
	{
		pos = (t_v2f){pos.x / ray->dir.x, pos.y / ray->dir.y};
		if (mxabsf(pos.x) < mxabsf(pos.y))
		{
			idx->x += (ray->dir.x < 0.0) ? -1 : 1;
			return (pos.x);
		}
		idx->y += (ray->dir.y < 0.0) ? -1 : 1;
		return (pos.y);
	}

}
