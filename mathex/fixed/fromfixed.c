/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fromfixed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 04:03:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 04:32:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/fixedfloat.h"
#include "mathex/mask.h"

int		fixtoi(const void *fixed)
{
	return (*((const int *)fixed) >> FIF_INTSHIFT);
}

int		roundfix(const void *fixed)
{
	int		i;

	i = *((const int *)fixed);
	return ((i & FIF_ROUNDMASK ? 1 : 0) + (i >> FIF_INTSHIFT));
}

float	fixtof(const void *fixed)
{
	unsigned int	num;
	float			ret;

	num = *((const unsigned int *)fixed);
	ret = (float)((num & MUSIGN) >> FIF_INTSHIFT);
	ret += (float)(num & FIF_FRACPOW) / (float)(FIF_FRACPOW);
	if (num & MSIGN)
		ret = -ret;
	return (ret);
}
