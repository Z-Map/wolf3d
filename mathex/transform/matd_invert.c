/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matd_invert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:33:48 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 05:03:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/matrix.h"

t_mattd				*pmattd_invert(t_mattd *mat)
{
	double			det;

	det = mat->x.x * (mat->y.y * mat->z.z - mat->y.z * mat->z.y)
		- mat->y.x * (mat->x.y * mat->z.z - mat->z.y * mat->x.z)
		+ mat->z.x * (mat->x.y * mat->y.z - mat->y.y * mat->x.z);
	det = 1 / det;
	*mat = (t_mattd){
		(t_v3d){((mat->y.y * mat->z.z) - (mat->y.z * mat->z.y)) * det,
			((mat->z.y * mat->x.z) - (mat->x.y * mat->z.z)) * det,
			((mat->x.y * mat->x.z) - (mat->x.z * mat->y.y)) * det},
		(t_v3d){((mat->z.x * mat->y.z) - (mat->y.x * mat->z.z)) * det,
			((mat->x.x * mat->z.z) - (mat->z.x * mat->x.z)) * det,
			((mat->x.z * mat->y.x) - (mat->x.x * mat->y.z)) * det},
		(t_v3d){((mat->y.x * mat->z.y) - (mat->z.x * mat->y.y)) * det,
			((mat->x.y * mat->z.x) - (mat->x.x * mat->z.y)) * det,
			((mat->x.x * mat->y.y) - (mat->x.y * mat->y.x)) * det},
		(t_v3d){ -mat->offset.x, -mat->offset.y, -mat->offset.z},
		(t_v4d){ 0.0, 0.0, 0.0, 1.0}};
	return (mat);
}

t_mattd				mattd_invert(const t_mattd *mat)
{
	t_mattd			m;

	m = *mat;
	pmattd_invert(&m);
	return (m);
}
