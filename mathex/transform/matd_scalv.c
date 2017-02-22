/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matd_scalv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:06:20 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 05:03:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/matrix.h"

t_mattd				*pmattd_scalv(t_mattd *mat, t_v3d sizev)
{
	pv3dmulv3d(&(mat->x), &sizev);
	pv3dmulv3d(&(mat->y), &sizev);
	pv3dmulv3d(&(mat->z), &sizev);
	return (mat);
}

t_mattd				mattd_scalv(t_mattd mat, t_v3d sizev)
{
	pv3dmulv3d(&(mat.x), &sizev);
	pv3dmulv3d(&(mat.y), &sizev);
	pv3dmulv3d(&(mat.z), &sizev);
	return (mat);
}

t_mattd				nmattd_scalv(t_v3d sizev)
{
	return ((t_mattd){
		(t_v3d){ sizev.x, 0.0, 0.0},
		(t_v3d){ 0.0, sizev.y, 0.0},
		(t_v3d){ 0.0, 0.0, sizev.z},
		(t_v3d){ 0.0, 0.0, 0.0},
		(t_v4d){ 0.0, 0.0, 0.0, 1.0}});
}
