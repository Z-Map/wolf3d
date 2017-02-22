/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matd_multiply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:54:05 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 05:00:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/matrix.h"

static inline void	pmattd_vecprod(t_v3d *v, const t_mattd *mat)
{
	*v = (t_v3d){(mat->x.x * v->x) + (mat->y.x * v->y) + (mat->z.x * v->z),
		(mat->x.y * v->x) + (mat->y.y * v->y) + (mat->z.y * v->z),
		(mat->x.z * v->x) + (mat->y.z * v->y) + (mat->z.z * v->z)};
}

t_mattd				*pmattd_multiply(t_mattd *dest, const t_mattd *mat)
{
	pmattd_apply(&(dest->offset), mat);
	pmattd_vecprod(&(dest->x), mat);
	pmattd_vecprod(&(dest->y), mat);
	pmattd_vecprod(&(dest->z), mat);
	return (dest);
}

t_mattd				mattd_multiply(t_mattd mat1, t_mattd mat2)
{
	pmattd_multiply(&mat1, &mat2);
	return (mat1);
}

t_v3d				*pmattd_apply(t_v3d *v, const t_mattd *mat)
{
	pmattd_vecprod(v, mat);
	v->x += mat->offset.x;
	v->y += mat->offset.y;
	v->z += mat->offset.z;
	return (v);
}

t_v3d				mattd_apply(t_v3d v, t_mattd mat)
{
	return ((t_v3d){
		(mat.x.x * v.x) + (mat.y.x * v.y) + (mat.z.x * v.z) + mat.offset.x,
		(mat.x.y * v.x) + (mat.y.y * v.y) + (mat.z.y * v.z) + mat.offset.y,
		(mat.x.z * v.x) + (mat.y.z * v.y) + (mat.z.z * v.z) + mat.offset.z});
}
