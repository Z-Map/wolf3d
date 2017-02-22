/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 22:56:02 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int					ft_pflen_nbr(t_pfc *arg)
{
	const int		neg = (arg->arg & (1ul << 63)) ? 1 : 0;
	const uintmax_t	n = (neg) ? (uintmax_t)(-(intmax_t)arg->arg) : arg->arg;
	t_ui			len;

	len = FT_MX_FLOATLEN;
	if ((arg->flag & PFF_PREC_SET) && (!arg->precision) && (!arg->arg))
		len = 0;
	else
		arg->tmpb = ft_ujfillbuf(n, arg->tmpb, (int *)&len);
	arg->b_len = (int)len;
	if ((arg->flag & PFF_PREC_SET) && (len < arg->precision))
		len = arg->precision;
	if ((arg->flag & (PFF_FORCE_SIGN | PFF_SPACE)) || (neg))
		len++;
	if ((arg->flag & PFF_ZERO_FILL)
		&& !(arg->flag & (PFF_LEFT_ALIGN | PFF_PREC_SET))
		&& (len < arg->minwidth))
		len = arg->minwidth;
	return ((int)len);
}
