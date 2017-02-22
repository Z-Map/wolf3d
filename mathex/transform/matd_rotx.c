/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matd_rotx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:15:34 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 05:03:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/matrix.h"
#include <math.h>

t_mattd				*pmattd_rotx(t_mattd *mat, double rad)
{
	t_mattd			rot;

	rot = nmattd_rotx(rad);
	return (pmattd_multiply(mat, &rot));
}

t_mattd				mattd_rotx(t_mattd mat, double rad)
{
	t_mattd			rot;

	rot = nmattd_rotx(rad);
	pmattd_multiply(&mat, &rot);
	return (mat);
}

t_mattd				nmattd_rotx(double rad)
{
	const double		c = cos(rad);
	const double		s = sin(rad);

	return ((t_mattd){
		(t_v3d){ 1.0, 0.0, 0.0},
		(t_v3d){ 0.0, c, s},
		(t_v3d){ 0.0, -s, c},
		(t_v3d){ 0.0, 0.0, 0.0},
		(t_v4d){ 0.0, 0.0, 0.0, 1.0}});
}
