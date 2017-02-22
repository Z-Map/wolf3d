/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 17:12:38 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 07:30:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_format.h"

size_t					ft_snbrlen(short nbr)
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
	return (len + 5);
}
