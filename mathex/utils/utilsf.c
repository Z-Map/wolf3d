/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 09:54:44 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 04:30:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/utils.h"

float		mxabsf(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

float		mxmaxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float		mxminf(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

void		swapf(float *a, float *b)
{
	register float	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
