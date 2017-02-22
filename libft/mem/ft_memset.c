/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:01:53 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/10 04:41:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

static inline unsigned long		extchartolong(unsigned long c)
{
	return ((c << 56) | (c << 48) | (c << 40)
		| (c << 32) | (c << 24) | (c << 16) | (c << 8) | c);
}

void							*ft_memset(void *b, int c, size_t len)
{
	register const unsigned long	ul = extchartolong((unsigned char)c);
	register size_t					aln;

	aln = len % sizeof(long);
	while (aln-- && len--)
		((unsigned char *)b)[len] = (unsigned char)c;
	aln = len / sizeof(long);
	while (aln--)
		((unsigned long *)b)[aln] = ul;
	return (b);
}
