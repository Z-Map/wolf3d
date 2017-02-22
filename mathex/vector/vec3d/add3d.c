/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 01:06:47 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 05:07:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/vector.h"

t_v3d					v3daddv3i(t_v3d a, t_v3i b)
{
	return ((t_v3d){ a.x + (double)(b.x),
		a.y + (double)(b.y),
		a.z + (double)(b.z)});
}

t_v3d					*pv3daddv3i(t_v3d *a, const t_v3i *b)
{
	a->x += (double)(b->x);
	a->y += (double)(b->y);
	a->z += (double)(b->z);
	return (a);
}

t_v3d					v3daddv3d(t_v3d a, t_v3d b)
{
	return ((t_v3d){ a.x + (double)(b.x),
		a.y + (double)(b.y),
		a.z + (double)(b.z)});
}

t_v3d					*pv3daddv3d(t_v3d *a, const t_v3d *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (a);
}
