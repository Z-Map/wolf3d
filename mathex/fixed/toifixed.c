/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toifixed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 04:03:42 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 04:38:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/fixedfloat.h"
#include "mathex/mask.h"

int			toifix(t_fix fixed)
{
	return (*((int *)(&fixed)));
}

int			itoifix(int num)
{
	if (num < 0)
		return ((int)((MSIGN) | (unsigned int)(-num << FIF_INTSHIFT)));
	return ((int)((MUSIGN) & (unsigned int)(num << FIF_INTSHIFT)));
}

int			ftoifix(float num)
{
	unsigned int	ret;

	ret = 0;
	if (num < 0)
	{
		ret |= MSIGN;
		num = -num;
	}
	ret |= (((unsigned int)num) << FIF_INTSHIFT) & ~MSIGN;
	num = (float)(num - (int)num) * (float)(FIF_FRACPOW);
	ret |= (unsigned int)num;
	num -= (int)num;
	if (num >= 0.5f)
		ret += 1;
	return ((int)ret);
}
