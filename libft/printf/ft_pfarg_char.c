/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:56:26 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/06 04:41:00 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int			ft_pfarg_char(int cc, va_list ap, t_pfc *arg)
{
	arg->type = PFT_CHAR;
	if (arg->flag & (PFF_LONG | PFF_LONG_LONG | PFF_CAPITAL))
		arg->arg = (uintmax_t)((wchar_t)(va_arg(ap, int)));
	else
		arg->arg = (uintmax_t)((char)(va_arg(ap, int)));
	return (cc);
}
