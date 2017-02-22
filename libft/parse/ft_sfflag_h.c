/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfflag_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:24:20 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/10 15:31:01 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char			*ft_sfflag_h(const char *c, t_sfb *b)
{
	if (c[1] == 'h')
	{
		b->arg.flag |= SFF_SHORT_SHORT;
		++c;
	}
	else
		b->arg.flag |= SFF_SHORT;
	return (c + 1);
}
