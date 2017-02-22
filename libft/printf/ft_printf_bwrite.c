/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bwrite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:52:14 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/12 16:19:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_printf.h"

int				ft_printf_bwrite(t_pfb *b, const char *c, const size_t len)
{
	ssize_t		i;

	if (!len)
		return (0);
	if (len >= FT_PF_BUFSIZE)
	{
		if ((ft_printf_bflush(b) < 0) || ((i = write(b->fd, c, len)) < 0))
			return (-1);
		b->len += i;
		return ((int)len);
	}
	i = b->blen + (int)len;
	if (i > FT_PF_BUFSIZE)
	{
		ft_memcpy(b->c, c, (size_t)(FT_PF_BUFSIZE - b->blen));
		i -= FT_PF_BUFSIZE;
		ft_printf_bflush(b);
	}
	else
		i = (int)len;
	ft_memcpy(b->c, c, (size_t)i);
	b->blen += i;
	b->c += i;
	return ((int)i);
}
