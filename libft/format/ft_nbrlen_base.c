/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:02:47 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 07:29:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

size_t		ft_nbrlen_base(register long i, char base)
{
	register size_t	len;

	len = (i < 0) ? 2 : 1;
	while ((i /= base) != 0)
		++len;
	return (len);
}
