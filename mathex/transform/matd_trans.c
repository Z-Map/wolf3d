/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matf_trans.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:47:59 by qloubier          #+#    #+#             */
/*   Updated: 2016/04/21 14:58:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/matrix.h"

t_mattd				*pmattd_trans(t_mattd *mat, t_v3d mov)
{
	pv3daddv3d(&(mat->offset), &mov);
	return (mat);
}

t_mattd				mattd_trans(t_mattd mat, t_v3d mov)
{
	pv3daddv3d(&(mat.offset), &mov);
	return (mat);
}

t_mattd				nmattd_trans(t_v3d mov)
{
	return ((t_mattd){
		(t_v3d){ 1.0, 0.0, 0.0},
		(t_v3d){ 0.0, 1.0, 0.0},
		(t_v3d){ 0.0, 0.0, 1.0},
		mov,
		(t_v4d){ 0.0, 0.0, 0.0, 1.0}});
}
