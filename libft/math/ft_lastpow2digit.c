/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastpow2digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:58:13 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/21 04:33:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

int			ft_lastpow2digit(unsigned long num)
{
	int				i;

	if (!num)
		return (0);
	i = 1;
	if (num & 1u)
		i *= 2;
	if (num & 2u)
		i *= 4;
	if (num & ~3ul)
		i *= 6;
	return (i % 10);
}
