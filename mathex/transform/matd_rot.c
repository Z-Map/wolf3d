/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matd_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:27:24 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 05:03:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/matrix.h"
#include <math.h>

t_mattd				*pmattd_rot(t_mattd *mat, t_v3d vrad)
{
	t_mattd			rot;

	rot = nmattd_rot(vrad);
	return (pmattd_multiply(mat, &rot));
}

t_mattd				mattd_rot(t_mattd mat, t_v3d vrad)
{
	t_mattd			rot;

	rot = nmattd_rot(vrad);
	pmattd_multiply(&mat, &rot);
	return (mat);
}

t_mattd				nmattd_rot(t_v3d vrad)
{
	const t_v3d		c = (t_v3d){cos(vrad.x), cos(vrad.y), cos(vrad.z)};
	const t_v3d		s = (t_v3d){sin(vrad.x), sin(vrad.y), sin(vrad.z)};
	const double		sxsz = s.x * s.z;
	const double		sycz = s.y * c.z;

	return ((t_mattd){
		(t_v3d){ (c.y * c.z) - (s.y * sxsz), -s.z * c.x, sycz + (c.y * sxsz)},
		(t_v3d){ (s.z * c.y) + (s.y * s.x * c.z), c.z * c.x,
			(s.y * s.z) - (c.y * s.x * c.z)},
			(t_v3d){ -s.y * c.x, s.x, c.x * c.y},
			(t_v3d){ 0.0, 0.0, 0.0},
			(t_v4d){ 0.0, 0.0, 0.0, 1.0}});
}
