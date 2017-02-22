/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 01:22:08 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/10 04:41:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	ft_bzero(void *s, size_t n)
{
	register size_t		aln;

	if (!n)
		return ;
	aln = n % sizeof(long);
	while (aln-- && n--)
		((char *)s)[n] = 0;
	aln = n / sizeof(long);
	while (aln--)
		((unsigned long *)s)[aln] = 0;
}
