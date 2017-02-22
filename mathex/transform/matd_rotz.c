/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matd_rotz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:20:59 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 05:03:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/matrix.h"
#include <math.h>

t_mattd				*pmattd_rotz(t_mattd *mat, double rad)
{
	t_mattd			rot;

	rot = nmattd_rotz(rad);
	return (pmattd_multiply(mat, &rot));
}

t_mattd				mattd_rotz(t_mattd mat, double rad)
{
	t_mattd			rot;

	rot = nmattd_rotz(rad);
	pmattd_multiply(&mat, &rot);
	return (mat);
}

t_mattd				nmattd_rotz(double rad)
{
	const double		c = cos(rad);
	const double		s = sin(rad);

	return ((t_mattd){
		(t_v3d){ c, s, 0.0},
		(t_v3d){ -s, c, 0.0},
		(t_v3d){ 0.0, 0.0, 1.0},
		(t_v3d){ 0.0, 0.0, 0.0},
		(t_v4d){ 0.0, 0.0, 0.0, 1.0}});
}
