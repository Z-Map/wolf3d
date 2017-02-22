/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsej_cmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:19:18 by map               #+#    #+#             */
/*   Updated: 2016/11/23 15:40:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

const char	*ft_parsej_cmap(const char *str, uintmax_t *num, t_cmap cm,
				int len)
{
	register int	i;

	*num = 0;
	i = 0;
	while ((*str) && (len-- > 0) &&
		((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
	{
		*num = (*num * (uintmax_t)cm.base) + (uintmax_t)(i);
		str++;
	}
	return (str);
}
