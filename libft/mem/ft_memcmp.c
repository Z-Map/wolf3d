/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:34:27 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/10 23:50:37 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	register const unsigned char	*b1;
	register const unsigned char	*b2;

	if (!n)
		return (0);
	b1 = (const unsigned char *)s1;
	b2 = (const unsigned char *)s2;
	while (--n && *(b1) == *(b2))
	{
		++b1;
		++b2;
	}
	return (*b1 - *b2);
}
