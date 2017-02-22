/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 05:17:31 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/07 04:52:57 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int				ft_printf_convert(int tid, t_pfc *arg, t_pfb *pfb)
{
	int			len;
	int			i;

	len = g_pf_flag_tab[tid].getlen(arg);
	i = (int)(arg->minwidth) - len;
	if (!(arg->flag & PFF_LEFT_ALIGN) && (i > 0))
		ft_printf_bwritec(pfb, ' ', (size_t)i);
	g_pf_flag_tab[tid].convert(pfb, arg, (size_t)len);
	if ((arg->flag & PFF_LEFT_ALIGN) && (i > 0))
		ft_printf_bwritec(pfb, ' ', (size_t)i);
	return (0);
}
