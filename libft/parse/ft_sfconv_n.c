/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfconv_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:45:33 by map               #+#    #+#             */
/*   Updated: 2016/11/23 15:51:44 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int				ft_sfconv_n(const char **c, t_sfb *b, t_sfc *arg)
{
	int			*iptr;

	if (**c == '%')
	{
		(*c)++;
		b->c = ft_strpskp(b->c, FT_WHITESPACE);
		return ((*(b->c++) == '%') ? 0 : -1);
	}
	else if ((**c == 'n') || (**c == 'N'))
	{
		iptr = va_arg(b->ap, int *);
		arg->arg = iptr;
		if (**c == 'n')
			*iptr = (int)(b->c - b->src);
		else
			*iptr = b->arglen;
		(*c)++;
	}
	return (0);
}
