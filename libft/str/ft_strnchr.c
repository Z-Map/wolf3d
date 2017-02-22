/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:52:23 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/22 18:04:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strnchr(const char *s, int c, size_t n)
{
	while ((*s) && (n--))
		if (*(s++) == (char)c)
			return ((char *)(unsigned long)(--s));
	return (((c) || (*s)) ? NULL : (char *)(unsigned long)s);
}
