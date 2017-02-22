/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filename_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 00:04:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/15 02:03:21 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "libft_printf.h"

size_t	ft_filename_ext(char *buf, const char *path, const char *ext, size_t l)
{
	size_t		i;

	if (!l)
		return (0);
	i = l;
	while ((*path) && (i--))
		*(buf++) = *(path++);
	if (ext)
	{
		while ((*ext) && (i--))
			*(buf++) = *(ext++);
	}
	if (!i)
		buf--;
	*buf = '\0';
	return (l - i);
}
