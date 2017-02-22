/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tofixed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 04:03:29 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 04:36:25 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/fixedfloat.h"
#include "mathex/mask.h"

t_fix		tofix(int num)
{
	return (*((t_fix *)(&num)));
}

t_fix		itofix(int num)
{
	t_fix	ret;

	if (num < 0)
		ret.integ = -num;
	ret.integ = num;
	ret.fract = 0;
	return (ret);
}

t_fix		ftofix(float num)
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
	return (*((t_fix *)(&ret)));
}
