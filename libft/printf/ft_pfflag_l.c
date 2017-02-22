/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:23:55 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/30 05:00:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

const char			*ft_pfflag_l(const char *c, t_pfb *b)
{
	if (c[1] == 'l')
	{
		b->arg.flag |= PFF_LONG_LONG;
		++c;
	}
	else
		b->arg.flag |= PFF_LONG;
	return (c + 1);
}
