/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfflag_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:23:55 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/24 01:00:57 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char			*ft_sfflag_l(const char *c, t_sfb *b)
{
	if (c[1] == 'l')
	{
		b->arg.flag |= SFF_LONG_LONG;
		++c;
	}
	else if (*c == 'L')
		b->arg.flag |= SFF_LONG_LONG;
	else
		b->arg.flag |= SFF_LONG;
	return (c + 1);
}
