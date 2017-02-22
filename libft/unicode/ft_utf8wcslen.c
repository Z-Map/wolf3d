/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8wcslen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 01:31:57 by map               #+#    #+#             */
/*   Updated: 2016/10/09 22:34:02 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unicode.h"

size_t		ft_utf8wcslen(const wchar_t *s)
{
	size_t len;

	len = 0;
	while (*s)
		len += (size_t)ft_utf8wcsize(*(s++));
	return (len);
}
