/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:22:27 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/08 03:06:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

const char			*ft_pfflag_dot(const char *c, t_pfb *b)
{
	int				i;

	i = 0;
	if (c[1] == '*')
	{
		i = va_arg(b->ap, int);
		b->arg.precision = (t_ui)((i < 0) ? 0 : i);
		c += 2;
	}
	else
		c = ft_parse_digit(c + 1, &(b->arg.precision));
	if (i >= 0)
		b->arg.flag |= PFF_PREC_SET;
	return (c);
}
