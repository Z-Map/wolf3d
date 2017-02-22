/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jdigitlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:51:15 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/04 12:56:29 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

size_t		ft_jdigitlen(intmax_t i)
{
	register size_t	len;

	len = 1;
	while ((i /= 10) != 0)
		++len;
	return (len);
}
