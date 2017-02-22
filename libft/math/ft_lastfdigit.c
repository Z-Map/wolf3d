/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastfdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:34:22 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/21 04:42:17 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

int					ft_lastfdigit(double d)
{
	const unsigned long	l = *((const unsigned long *)(&d));
	long				ld;
	unsigned long		msk;
	int					i;

	ld = ((l & FT_D_EXP) >> 52) - 1023;
	if (ld < 0)
		return (0);
	i = ft_lastpow2digit((unsigned long)ld);
	msk = 1ul << 52;
	while ((msk >>= 1) && --ld > 0)
		if (msk & l)
			i += ft_lastpow2digit((unsigned long)ld);
	return (i % 10);
}
