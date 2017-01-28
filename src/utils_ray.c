/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 20:08:57 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/28 12:50:33 by qloubier         ###   ########.fr       */
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

t_v2f			w3d_ray(const t_ray *ray, t_v2f pos)
{

}
