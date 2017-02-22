/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:28:03 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/18 13:33:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void		*ft_memswp(void *ping, void *pong, size_t len)
{
	register char	c;
	register char	*a;
	register char	*b;

	a = ping;
	b = pong;
	while (len--)
	{
		c = a[len];
		a[len] = b[len];
		b[len] = c;
	}
	return (ping);
}
