/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:09:18 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/10 23:48:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	register const unsigned char	*ic;

	ic = (const unsigned char*)s;
	while (n--)
	{
		if (*ic == (unsigned char)c)
			return ((void *)(unsigned long)ic);
		ic++;
	}
	return (NULL);
}
