/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ujfillbufbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:38:32 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 18:37:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

char			*ft_ujfillbufbase(uintmax_t n, t_cmap cm, char *b, int *len)
{
	register const int		ln = *len;
	register const t_ui		base = cm.base;
	int						l;

	b += ln - 1;
	*b = cm.cmap[n % base];
	l = 1;
	while ((n /= base) && (l < ln))
	{
		*(--b) = cm.cmap[n % base];
		++l;
	}
	*len = l;
	return (b);
}
