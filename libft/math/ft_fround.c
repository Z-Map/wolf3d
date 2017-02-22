/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fround.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 04:19:35 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/21 04:46:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

double					ft_fround(const double *d)
{
	const unsigned long	ld = *((const unsigned long *)(d));
	unsigned long		l;
	double				od;

	l = (ld & FT_D_EXP) >> 52;
	if ((l > 1022) && (l < 1076))
	{
		l = FT_D_MAN >> (l - 1023);
		od = ((ld & (l & (~l >> 1))) ? 1.0 : 0.0);
		l = ld & (~l);
		return (*((double *)&l) + od);
	}
	else if (l > 1076)
		return (*d);
	else if (l == 1022)
		return (1.0);
	return (0.0);
}
