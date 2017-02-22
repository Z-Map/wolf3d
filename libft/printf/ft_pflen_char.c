/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflen_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:43:11 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 22:13:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int		ft_pflen_char(t_pfc *arg)
{
	if (arg->flag & (PFF_LONG | PFF_LONG_LONG | PFF_CAPITAL))
		arg->b_len = ft_utf8wcsize((wchar_t)arg->arg);
	else
		arg->b_len = 1;
	if ((arg->flag & PFF_ZERO_FILL) && !(arg->flag & PFF_LEFT_ALIGN)
		&& (arg->minwidth))
		return ((int)arg->minwidth);
	return (1);
}
