/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 15:32:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int					ft_pflen_unbr(t_pfc *arg)
{
	const t_cmap	cm = PF_COUCOU_LA_NORME[arg->type - 2];
	t_ui			len;

	len = FT_MX_FLOATLEN;
	if ((arg->flag & PFF_PREC_SET) && (!arg->precision) && (!arg->arg))
		len = 0;
	else
		arg->tmpb = ft_ujfillbufbase(arg->arg, cm, arg->tmpb, (int *)&len);
	arg->b_len = (int)len;
	if (arg->type == PFT_BIN)
		len = ((len >> 2) + ((len % 4) ? 1 : 0)) << 2;
	if ((arg->flag & PFF_PREC_SET) && (len < arg->precision))
		len = arg->precision;
	else if ((arg->flag & PFF_ALTERNTE) && (arg->type == PFT_OCT)
		&& (arg->arg || !len))
		len += 1;
	if ((arg->flag & PFF_PTR) ||
		((arg->flag & PFF_ALTERNTE) && (arg->type == PFT_HEXA) && arg->arg))
		len += 2;
	if ((arg->flag & PFF_ZERO_FILL)
		&& !(arg->flag & (PFF_LEFT_ALIGN | PFF_PREC_SET))
		&& (len < arg->minwidth))
		len = arg->minwidth;
	return ((int)len);
}
