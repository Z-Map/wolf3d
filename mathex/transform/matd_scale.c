/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matd_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:27:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 05:03:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/matrix.h"

t_mattd				*pmattd_scale(t_mattd *mat, double size)
{
	const t_v3d		s = nv3d(size);

	pv3dmulv3d(&(mat->x), &s);
	pv3dmulv3d(&(mat->y), &s);
	pv3dmulv3d(&(mat->z), &s);
	return (mat);
}

t_mattd				mattd_scale(t_mattd mat, double size)
{
	const t_v3d		s = nv3d(size);

	pv3dmulv3d(&(mat.x), &s);
	pv3dmulv3d(&(mat.y), &s);
	pv3dmulv3d(&(mat.z), &s);
	return (mat);
}

t_mattd				nmattd_scale(double size)
{
	return ((t_mattd){
		(t_v3d){ size, 0.0, 0.0},
		(t_v3d){ 0.0, size, 0.0},
		(t_v3d){ 0.0, 0.0, size},
		(t_v3d){ 0.0, 0.0, 0.0},
		(t_v4d){ 0.0, 0.0, 0.0, 1.0}});
}
