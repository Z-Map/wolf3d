/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 01:40:58 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/10 04:40:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	register size_t		aln;

	aln = n % sizeof(long);
	while (aln-- && n--)
		((char *)dst)[n] = ((const char *)src)[n];
	aln = n / sizeof(long);
	while (aln--)
		((unsigned long *)dst)[aln] = ((const unsigned long *)src)[aln];
	return (dst);
}
