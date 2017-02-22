/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floattrunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:34:44 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/21 16:36:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

double			ft_ftrunc(const double *d)
{
	const unsigned long	ld = *((const unsigned long *)(d));
	unsigned long		l;

	l = (ld & FT_D_EXP) >> 52;
	if ((l > 1022) && (l < 1076))
	{
		l = FT_D_MAN >> (l - 1023);
		l = ld & (~l);
		return (*((double *)&l));
	}
	else if (l > 1076)
	{
		l = (ld & ~FT_D_MAN) | ((ld & FT_D_MAN) - 1);
		return (*((double *)&l));
	}
	return (0.0);
}
