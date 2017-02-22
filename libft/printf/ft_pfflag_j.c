/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfflag_j.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:24:34 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/30 05:10:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

const char			*ft_pfflag_j(const char *c, t_pfb *b)
{
	b->arg.flag |= PFF_INTMAX;
	return (c + 1);
}
