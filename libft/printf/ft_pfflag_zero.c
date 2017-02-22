/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:20:51 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/30 03:41:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

const char			*ft_pfflag_zero(const char *c, t_pfb *b)
{
	b->arg.flag |= PFF_ZERO_FILL;
	return (c + 1);
}
