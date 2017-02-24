/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:03:59 by map               #+#    #+#             */
/*   Updated: 2017/02/24 16:20:08 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static void		init_scanf(t_sfb *buf, const char *str, const char *fstr)
{
	buf->arglen = -1;
	buf->src = str;
	buf->c = str;
	buf->ref = fstr;
}

int				ft_sscanf(const char *str, const char *fstr, ...)
{
	t_sfb		buf;

	if (!fstr)
		return (-1);
	init_scanf(&buf, str, fstr);
	va_start(buf.ap, fstr);
	ft_scanf_loop(fstr, &buf);
	va_end(buf.ap);
	return (buf.arglen);
}
