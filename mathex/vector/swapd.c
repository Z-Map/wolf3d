/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 22:18:09 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 05:15:00 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/vector.h"

void			swapv2d(t_v2d *a, t_v2d *b)
{
	t_v2d	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			swapv3d(t_v3d *a, t_v3d *b)
{
	t_v3d	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			swapv4d(t_v4d *a, t_v4d *b)
{
	t_v4d	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
