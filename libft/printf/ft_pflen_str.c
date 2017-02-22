/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 22:15:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft_printf.h"

int		ft_pflen_str(t_pfc *arg)
{
	size_t	len;

	if (arg->arg)
	{
		if (arg->type == PFT_WSTR)
			len = ft_utf8wcslen((wchar_t *)(arg->arg));
		else
			len = ft_strlen((char *)(arg->arg));
	}
	else
		len = 6;
	if ((arg->flag & PFF_PREC_SET) && (len > arg->precision))
		len = (arg->type == PFT_WSTR) ? ft_utf8wcsalign(
			(wchar_t *)(arg->arg), arg->precision) : arg->precision;
	arg->b_len = (int)len;
	if ((arg->flag & PFF_ZERO_FILL) && !(arg->flag & PFF_LEFT_ALIGN)
		&& (len < arg->minwidth))
		len = arg->minwidth;
	return ((int)len);
}
