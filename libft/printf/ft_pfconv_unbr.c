/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_unbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:54:57 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 22:56:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void			ft_pfconv_unbr(t_pfb *b, t_pfc *arg, size_t len)
{
	int			i;

	if ((arg->type == PFT_HEXA) && (arg->flag & PFF_ALTERNTE)
		&& (arg->arg || arg->flag & PFF_PTR))
		len -= (size_t)ft_printf_bwrite(b,
			((arg->flag & PFF_CAPITAL) ? "0X" : "0x"), 2);
	i = (int)len - (int)(arg->b_len);
	if (i > 0)
		ft_printf_bwritec(b, '0', (size_t)i);
	ft_printf_bwrite(b, arg->tmpb, (size_t)(arg->b_len));
}
