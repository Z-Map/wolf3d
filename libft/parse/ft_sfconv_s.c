/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfconv_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:15:29 by map               #+#    #+#             */
/*   Updated: 2017/02/15 01:19:51 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int					ft_sfconv_s(const char **c, t_sfb *b, t_sfc *arg)
{
	char			*buf;
	int				len;

	b->c = ft_strpskp(b->c, FT_WHITESPACE);
	len = ft_strcspn(b->c, FT_WHITESPACE);
	if (!len)
		return (-1);
	len = (len > arg->maxwidth) ? arg->maxwidth : len;
	if (!(arg->flag & SFF_IGNORE))
	{
		buf = va_arg(b->ap, char *);
		ft_strncpy(buf, b->c, (size_t)len);
		buf[len] = '\0';
	}
	b->c += len;
	(*c)++;
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}
