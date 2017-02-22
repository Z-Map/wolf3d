/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 17:10:42 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 07:29:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

size_t					ft_lnbrlen(long nbr)
{
	register size_t	len;

	len = (nbr < 0) ? 2 : 1;
	while ((nbr /= 10) != 0)
		++len;
	return (len);
}
