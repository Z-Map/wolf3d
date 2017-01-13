/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:37:57 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/13 17:56:17 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float			w3d_rayboxstep(t_w3dmap *map, t_ray *ray, t_v2ui *idx)
{
	t_v2f		pos;

	pos = (t_v2f){(float)idx->x - ray->start.x, (float)idx->y - ray->start.y};
	if (ray->dir.x > 0.0f)
		pos.x += 1.0f;
	if (ray->dir.y > 0.0f)
		pos.y += 1.0f;
	if ((ray->dir.x == 0.0f) || (ray->dir.y == 0.0f))
	{
		idx->x = (unsigned int)((int)idx->x + (int)ray->dir.x);
		idx->y = (unsigned int)((int)idx->y + (int)ray->dir.y);
		{(unsigned int)(ray->dir.x * pos.x),
			(unsigned int)(ray->dir.y * pos.y)}
		return mxmin
	}

}

float			w3d_raycast(t_w3dmap *map, t_ray *ray)
{
	t_v2ui		idxs;

	idxs = (t_v2ui){(unsigned int)ray->start.x, (unsigned int)(ray->start.y)};
	while ()
	{

	}
	return (ray->distance);
}
