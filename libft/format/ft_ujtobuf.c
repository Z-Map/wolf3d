/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ujtobuf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:38:32 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/07 04:26:53 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

char			*ft_ujtobuf(uintmax_t n, char *b)
{
	uintmax_t	tn;
	size_t		len;

	len = 0;
	tn = n;
	while ((tn /= 10))
		len++;
	tn = n;
	b[--len] = '0' + (char)(tn % 10);
	while ((tn /= 10))
		b[--len] = '0' + (char)(tn % 10);
	return (b);
}
