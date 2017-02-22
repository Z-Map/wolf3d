/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:30:06 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/22 18:17:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strchrnot(const char *s, int c)
{
	while (*s && *s == (char)c)
		s++;
	return ((*s && c) ? (char *)(unsigned long)s : NULL);
}
