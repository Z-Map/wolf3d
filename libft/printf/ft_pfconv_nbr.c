/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:54:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 22:12:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void			ft_pfconv_nbr(t_pfb *b, t_pfc *arg, size_t len)
{
	int			i;

	if ((intmax_t)(arg->arg) < 0)
	{
		len -= (size_t)ft_printf_bwritec(b, '-', 1);
		arg->arg = (uintmax_t)(-(intmax_t)(arg->arg));
	}
	else if ((arg->flag & PFF_FORCE_SIGN))
		len -= (size_t)ft_printf_bwritec(b, '+', 1);
	else if ((arg->flag & PFF_SPACE))
		len -= (size_t)ft_printf_bwritec(b, ' ', 1);
	i = (int)len - (int)(arg->b_len);
	if (i > 0)
		ft_printf_bwritec(b, '0', (size_t)i);
	ft_printf_bwrite(b, arg->tmpb, (size_t)(arg->b_len));
}
