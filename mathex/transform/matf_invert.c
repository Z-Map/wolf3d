/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf_invert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:33:48 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/31 18:58:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/matrix.h"

t_mattf				*pmattf_invert(t_mattf *mat)
{
	float			det;

	det = mat->x.x * (mat->y.y * mat->z.z - mat->y.z * mat->z.y)
		- mat->y.x * (mat->x.y * mat->z.z - mat->z.y * mat->x.z)
		+ mat->z.x * (mat->x.y * mat->y.z - mat->y.y * mat->x.z);
	det = 1 / det;
	*mat = (t_mattf){
		(t_v3f){((mat->y.y * mat->z.z) - (mat->y.z * mat->z.y)) * det,
			((mat->z.y * mat->x.z) - (mat->x.y * mat->z.z)) * det,
			((mat->x.y * mat->x.z) - (mat->x.z * mat->y.y)) * det},
		(t_v3f){((mat->z.x * mat->y.z) - (mat->y.x * mat->z.z)) * det,
			((mat->x.x * mat->z.z) - (mat->z.x * mat->x.z)) * det,
			((mat->x.z * mat->y.x) - (mat->x.x * mat->y.z)) * det},
		(t_v3f){((mat->y.x * mat->z.y) - (mat->z.x * mat->y.y)) * det,
			((mat->x.y * mat->z.x) - (mat->x.x * mat->z.y)) * det,
			((mat->x.x * mat->y.y) - (mat->x.y * mat->y.x)) * det},
		(t_v3f){ -mat->offset.x, -mat->offset.y, -mat->offset.z},
		(t_v4f){ 0.0f, 0.0f, 0.0f, 1.0f}};
	return (mat);
}

t_mattf				mattf_invert(const t_mattf *mat)
{
	t_mattf			m;

	m = *mat;
	pmattf_invert(&m);
	return (m);
}
