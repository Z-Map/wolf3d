/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfflag_j.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 02:24:34 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/10 15:30:55 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char			*ft_sfflag_j(const char *c, t_sfb *b)
{
	b->arg.flag |= SFF_INTMAX;
	return (c + 1);
}