/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:52:23 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/22 18:32:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strchrnul(const char *s, int c)
{
	while (*s)
		if (*(s++) == (char)c)
			return ((char *)(unsigned long)(--s));
	return ((char *)(unsigned long)s);
}
