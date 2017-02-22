/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:46:41 by qloubier          #+#    #+#             */
/*   Updated: 2016/07/09 19:41:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_io.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			buffer[11];
	unsigned int	nbr;
	size_t			len;

	len = 1;
	ft_memset(buffer, (int)((n < 0) ? '-' : '+'), 11);
	nbr = (unsigned int)((n < 0) ? -n : n);
	buffer[10] = '0' + (char)(nbr % 10);
	while ((nbr /= 10) && (len < 10))
		buffer[10 - (len++)] = '0' + (char)(nbr % 10);
	if (buffer[0] == '-')
		len++;
	write(fd, (buffer + (11 - len)), len);
}
