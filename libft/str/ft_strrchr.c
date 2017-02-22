/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:03:52 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 21:50:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*as;

	as = (char *)(unsigned long)s;
	while (*as)
		(as++);
	while (as >= s)
	{
		if (*as == (char)c)
			return (as);
		as--;
	}
	return (NULL);
}
