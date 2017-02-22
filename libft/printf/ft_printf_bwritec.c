/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bwritec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:52:14 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/12 01:58:00 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_printf.h"

int				ft_printf_bwritec(t_pfb *b, char c, size_t len)
{
	ssize_t		i;

	if (!len)
		return (0);
	i = (int)len;
	if ((b->blen + i) < FT_PF_BUFSIZE)
	{
		ft_memset(b->c, (int)c, (size_t)i);
		b->blen += i;
		b->c += i;
	}
	else
	{
		ft_memset(b->c, (int)c, (size_t)(i = FT_PF_BUFSIZE - b->blen));
		ft_printf_bflush(b);
		if ((i = (int)len - i))
			ft_printf_bwritec(b, c, (size_t)i);
	}
	return ((int)len);
}
