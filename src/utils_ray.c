/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 20:08:57 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/31 15:42:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_ray			w3d_mkray(t_v2f start, t_v2f dir, t_ul flags, float dist)
{
	return ((t_ray){.start = start, .dir = dir, .flags = flags,
		.end = (t_v2f){0.0f, 0.0f}, .grid_id = (t_v2ui){0, 0},
		.normale = (t_v3f){1.0f, 0.0f, 0.0f}, .distance = dist,
		.bloc = NULL});
}
