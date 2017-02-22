/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:51:04 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 07:29:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

size_t		ft_nbrlen(int nbr)
{
	register size_t			len;
	register unsigned int	i;

	len = (nbr < 0) ? 1 : 0;
	i = (unsigned int)((nbr < 0) ? -nbr : nbr);
	if (i < 10)
		return (len + 1);
	else if (i < 100)
		return (len + 2);
	else if (i < 1000)
		return (len + 3);
	else if (i < 10000)
		return (len + 4);
	else if (i < 100000)
		return (len + 5);
	else if (i < 1000000)
		return (len + 6);
	else if (i < 10000000)
		return (len + 7);
	else if (i < 100000000)
		return (len + 8);
	else if (i < 1000000000)
		return (len + 9);
	return (len + 10);
}
