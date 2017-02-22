/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:19:18 by map               #+#    #+#             */
/*   Updated: 2016/11/09 14:39:55 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char	*ft_parsef(const char *str, double *num, t_cmap cm, int len)
{
	register int	i;
	double			d;

	*num = 0.0;
	i = 0;
	while ((*str) && (len-- > 0) &&
		((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
	{
		*num = (*num * (double)cm.base) + (double)(i);
		str++;
	}
	if ((*str == '.') && (len-- > 0))
	{
		str++;
		d = (double)cm.base;
		while ((*str) && (len-- > 0) &&
			((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
		{
			*num += (double)(i) / d;
			d *= (double)cm.base;
			str++;
		}
	}
	return (str);
}
