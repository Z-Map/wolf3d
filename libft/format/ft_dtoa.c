/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 01:18:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 15:30:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_format.h"

static char				*is_special(double d)
{
	const unsigned long	*l = (unsigned long *)&d;

	if ((*l & (~FT_SM_L)) == FT_D_EXP)
		return (ft_strdup((*l & FT_SM_L) ? "-inf" : "inf"));
	else if ((*l & FT_D_EXP) == FT_D_EXP)
		return (ft_strdup((*l & FT_SM_L) ? "-nan" : "nan"));
	return (NULL);
}

static char				*alloc_and_fill(double d, char *tb, int len, t_ui prec)
{
	const unsigned long	*l = (unsigned long *)&d;
	char				*c;
	int					i;

	if (!(c = (char *)malloc(sizeof(char) * ((t_ui)len + prec + 1u))))
		return (NULL);
	ft_memcpy(c, tb, (size_t)len);
	i = 0;
	while (prec--)
	{
		d *= 10.0;
		if (d < 1.0)
			c[len++] = '0';
		else if (!prec || (((*l & FT_D_EXP) >> 52) > 1075))
		{
			++i;
			ft_ujfillbuf((unsigned long)(ft_fround(&d)), c + len, &i);
			len += i;
			d = 0.0;
		}
		else
			++i;
	}
	c[len] = '\0';
	return (c);
}

char					*ft_dtoa(double n, t_ui prec)
{
	char				buf[FT_MX_FLOATLEN + 2];
	char				*c;
	int					len;
	int					i;

	if ((c = is_special(n)))
		return (c);
	len = FT_MX_FLOATLEN;
	c = buf + FT_MX_FLOATLEN;
	ft_memcpy(c, ".", (size_t)2);
	while ((n > 18446744073709551615.0) && --len)
	{
		*(--c) = '0' + (char)ft_lastfdigit(n);
		n /= 10.0;
	}
	i = len;
	c = ft_ujfillbuf((unsigned long)((n < 0.0) ? -n : n), buf, &i);
	if (n < 0.0)
	{
		*(--c) = '-';
		n = -n;
		--len;
	}
	return (alloc_and_fill(n - (double)(unsigned long)n,
		c, (FT_MX_FLOATLEN - (len - i)) + 1, prec));
}
