/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8fromwc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <marvin@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 01:52:06 by map               #+#    #+#             */
/*   Updated: 2016/10/06 04:33:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unicode.h"

int				ft_utf8fromwc(const wchar_t c, t_ui *b)
{
	register const t_ui		i = (t_ui)(c) & U8M_MAX;

	if (i > U8L_4)
	{
		*b = ft_memalign(U8_4 | (i & U8M_1) |
			((i & U8M_2) << 2) | ((i & U8M_3) << 4) | ((i & U8M_4) << 6));
		return (4);
	}
	else if (i > U8L_3)
	{
		*b = ft_memalign(U8_3 | ((i & U8M_1) << 8) |
			((i & U8M_2) << 10) | ((i & U8M_3) << 12));
		return (3);
	}
	else if (i > U8L_2)
	{
		*b = ft_memalign(U8_2 | ((i & U8M_1) << 16) | ((i & U8M_2) << 18));
		return (2);
	}
	else
	{
		*b = ft_memalign(U8_1 | ((i & U8L_2) << 24));
		return (1);
	}
}
