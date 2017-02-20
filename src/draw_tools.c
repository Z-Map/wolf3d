/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:07:30 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/19 21:16:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_ui			w3d_drawshade(t_ui c, t_v3f nor)
{
	t_rgba		col;

	col = *((t_rgba *)(&c));
	if (nor.y < 0.0)
		col = (t_rgba){.r = (t_uc)(col.r * 0.8f), .g = (t_uc)(col.g * 0.8f),
			.b = (t_uc)(col.b * 0.8f), .a = col.a};
	if (nor.x < 0.0)
		col = (t_rgba){.r = (t_uc)(col.r * 0.65f), .g = (t_uc)(col.g * 0.65f),
			.b = (t_uc)(col.b * 0.65f), .a = col.a};
	if ((nor.y > 0.0) || (nor.z < 0.0))
		col = (t_rgba){.r = (t_uc)(col.r * 0.55f), .g = (t_uc)(col.g * 0.55f),
			.b = (t_uc)(col.b * 0.55f), .a = col.a};
	return (*((t_ui *)(&col)));
}
