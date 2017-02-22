/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnidx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 05:04:09 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/09 13:46:07 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int		ft_strnidx(const char *s, int c, size_t n)
{
	register int	i;
	register char	ch;

	i = 0;
	ch = (char)c;
	while ((s[i]) && (n--))
	{
		if (s[i] == ch)
			return (i);
		++i;
	}
	return ((c || s[i]) ? -1 : i);
}
