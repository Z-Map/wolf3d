/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfconv_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:45:33 by map               #+#    #+#             */
/*   Updated: 2016/11/24 01:03:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static int			valid_num(char c, const char *s, int len)
{
	if ((len > 1) && ((*s == '+') || (*s == '-')))
		++s;
	if (((c == 'x') && !ft_strchr(FT_DIGIT_L, (int)(*s))) ||
		((c == 'X') && !ft_strchr(FT_DIGIT, (int)(*s))) ||
		(((c == 'o') || (c == 'O')) && !ft_strchr(FT_DIGIT_L, (int)(*s))) ||
		!ft_strchr(FT_DECIMAL_DIGIT, (int)*s))
		return (0);
	return (1);
}

int					ft_sfconv_u(const char **c, t_sfb *b, t_sfc *arg)
{
	b->c = ft_strpskp(b->c, FT_WHITESPACE);
	if (!valid_num(**c, b->c, arg->maxwidth))
		return (-1);
	else if (!(arg->flag & SFF_IGNORE))
		arg->arg = va_arg(b->ap, void *);
	if ((**c == 'o') || (**c == 'O'))
		ft_sfbuftouarg(b, arg, g_cmapup[6]);
	if ((**c == 'x') || (**c == 'X'))
	{
		arg->flag &= ~SFF_CAPITAL;
		if ((b->c[0] == 0) && (b->c[1] == **c) && (arg->maxwidth > 1))
		{
			b->c += 2;
			arg->maxwidth -= 2;
		}
		ft_sfbuftouarg(b, arg, (**c == 'x') ? g_cmaplow[14] : g_cmapup[14]);
	}
	else
		ft_sfbuftouarg(b, arg, g_cmapup[8]);
	(*c)++;
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}
