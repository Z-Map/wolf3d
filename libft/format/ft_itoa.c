/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 05:22:56 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 21:59:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

char	*ft_itoa(int n)
{
	unsigned int	absn;
	size_t			len;
	char			*buf;

	len = (n < 0) ? 2 : 1;
	absn = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;
	while ((absn /= 10))
		len++;
	buf = ft_strnew(len--);
	if (!buf)
		return (NULL);
	*buf = '-';
	absn = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;
	buf[len--] = '0' + (char)(absn % 10);
	while ((absn /= 10))
		buf[len--] = '0' + (char)(absn % 10);
	return (buf);
}
