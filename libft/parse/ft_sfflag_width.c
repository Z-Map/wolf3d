/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfflag_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:16:26 by map               #+#    #+#             */
/*   Updated: 2016/11/24 01:37:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char			*ft_sfflag_width(const char *c, t_sfb *b)
{
	c = ft_parse_digit(c, (t_ui *)&(b->arg.maxwidth));
	b->arg.flag |= SFF_MXW_SET;
	return (c);
}
