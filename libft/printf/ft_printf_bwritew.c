/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bwritew.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:52:14 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 22:24:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_printf.h"

static int		ft_pf_buffer_to_small(t_pfb *b, const wchar_t *c, size_t len)
{
	ssize_t		i;
	int			cl;
	t_ui		cb;

	if (ft_printf_bflush(b) < 0)
		return (-1);
	i = (int)len;
	while (len)
	{
		cl = ft_utf8fromwc(*c, &cb);
		if ((t_ui)cl > len)
			break ;
		++c;
		len -= (t_ui)cl;
		cl = (int)write(b->fd, &cb, (size_t)cl);
		if (cl < 0)
			return (-1);
		b->len += cl;
	}
	return ((int)i - (int)len);
}

int				ft_printf_bwritew(t_pfb *b, const wchar_t *c, size_t len)
{
	ssize_t		i;
	t_ui		cl;
	t_ui		cb;

	if (!len)
		return (0);
	if (len >= FT_PF_BUFSIZE)
		return (ft_pf_buffer_to_small(b, c, len));
	i = (int)len;
	while (len)
	{
		cl = (t_ui)ft_utf8fromwc(*c, &cb);
		if (cl > len)
			break ;
		if ((b->blen + (int)cl) > FT_PF_BUFSIZE)
			ft_printf_bflush(b);
		ft_memcpy(b->c, &cb, (size_t)cl);
		b->c += cl;
		b->blen += cl;
		++c;
		len -= cl;
	}
	return ((int)i - (int)len);
}
