/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 02:37:49 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 22:16:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void		init_printf(t_pfb *buf)
{
	buf->len = 0;
	buf->blen = 0;
	buf->fd = 1;
	buf->c = buf->buffer;
	(buf->c)[0] = '\0';
	(buf->c)[FT_PF_BUFSIZE] = '\0';
}

int				ft_printf(const char *fstr, ...)
{
	t_pfb		buf;

	if (!fstr)
		return (-1);
	init_printf(&buf);
	va_start(buf.ap, fstr);
	ft_printf_loop(fstr, &buf);
	va_end(buf.ap);
	return ((int)buf.len);
}
