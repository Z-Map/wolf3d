/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:37:57 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/13 19:50:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

t_w3dbox		*w3d_getlvlbox(t_w3dmap *map, t_v2ui idx)
{
	int			i;

	if ((idx.x >= map->size.x) || (idx.y >= map->size.y))
		return (NULL);
	i = map->grid[idx.y][idx.x];
	if (i < 0)
		i += (int)map->bloclen;
	return (map->blocs + i);
}

static int		inrange(t_w3dmap *map, t_v2i idx)
{
	if ((idx.x < 0) || (idx.y < 0))
		return (0);
	else if ((idx.x < (int)map->size.x) || (idx.y < (int)map->size.y))
		return (1);
	return (0);
}

float			w3d_raycast(t_w3dmap *map, t_ray *ray)
{
	t_v2ui		idx;
	t_v2i		nidx;
	t_w3dbox	*box;

	nidx = (t_v2i){(int)(ray->start.x), (int)(ray->start.y)};
	idx = (t_v2ui){(unsigned int)nidx.x, (unsigned int)nidx.y};
	ray->distance = w3d_rayboxstep(ray, &nidx);
	box = w3d_getlvlbox(map, idx);
	while (inrange(map, nidx) && box && !(box->flags & W3D_BLOC_WALL))
	{
		idx = (t_v2ui){(unsigned int)nidx.x, (unsigned int)nidx.y};
		box = w3d_getlvlbox(map, idx);
		if ((!box) || (box->flags & W3D_BLOC_WALL))
			break ;
		ray->distance = w3d_rayboxstep(ray, &nidx);
	}
	ray->grid_id = idx;
	if (!box || !(box->flags & W3D_BLOC_WALL))
		ray->distance = -1.0f;
	else
		ray->end = (t_v2f){ray->start.x + (ray->distance * ray->dir.x),
			ray->start.y + (ray->distance * ray->dir.y)};
	return (ray->distance);
}
