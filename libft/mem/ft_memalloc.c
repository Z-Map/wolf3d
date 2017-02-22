/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:51:16 by qloubier          #+#    #+#             */
/*   Updated: 2016/07/09 19:33:26 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_memory.h"

void	*ft_memalloc(size_t size)
{
	void	*memptr;

	memptr = malloc(size);
	if (memptr)
		ft_bzero(memptr, size);
	return (memptr);
}
