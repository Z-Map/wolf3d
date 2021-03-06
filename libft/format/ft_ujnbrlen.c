/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ujnbrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:51:15 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/04 13:07:38 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

size_t		ft_ujnbrlen(uintmax_t i, unsigned int base)
{
	register size_t	len;

	len = (base == 8) ? 2 : 1;
	len = (base == 16) ? 3 : len;
	while ((i /= base) != 0)
		++len;
	return (len);
}
