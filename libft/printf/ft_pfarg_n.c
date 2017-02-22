/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarg_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 01:47:47 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 17:00:50 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int			ft_pfarg_n(int cc, va_list ap, t_pfc *arg)
{
	arg->type = PFT_N;
	arg->arg = (uintmax_t)va_arg(ap, void *);
	return (cc);
}
