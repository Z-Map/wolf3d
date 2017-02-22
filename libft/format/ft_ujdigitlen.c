/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ujdigitlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:51:15 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/04 13:05:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

size_t					ft_ujdigitlen(uintmax_t i, unsigned int base)
{
	register size_t	len;

	len = 1;
	while ((i /= base) != 0)
		++len;
	return (len);
}
