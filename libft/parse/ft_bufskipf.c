/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufskipf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:00:11 by map               #+#    #+#             */
/*   Updated: 2016/11/24 00:55:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

void			ft_bufskipf(const char **str, int len, t_cmap cm)
{
	const char	*c;

	c = *str;
	if ((*c == '+') || (*c == '-'))
	{
		(c)++;
		len--;
	}
	while ((*c) && (len-- > 0) &&
		(ft_strnidx(cm.cmap, (int)*c, (size_t)cm.base) >= 0))
		++c;
	if ((*c == '.') && (len-- > 0))
	{
		++c;
		while (*c && (len-- > 0) &&
			(ft_strnidx(cm.cmap, (int)*c, (size_t)cm.base) >= 0))
			++c;
	}
	*str = c;
}
