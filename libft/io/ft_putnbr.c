/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:46:41 by qloubier          #+#    #+#             */
/*   Updated: 2016/07/09 19:41:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_io.h"

void		ft_putnbr(int n)
{
	char					buffer[11];
	register unsigned int	nbr;
	register size_t			len;

	len = 1;
	nbr = (unsigned int)((n < 0) ? -n : n);
	buffer[10] = '0' + (char)(nbr % 10);
	while ((nbr /= 10))
		buffer[10 - (len++)] = '0' + (char)(nbr % 10);
	if (n < 0)
		buffer[10 - (len++)] = '-';
	write(1, (buffer + (11 - len)), len);
}
