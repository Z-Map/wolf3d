/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:22:15 by qloubier          #+#    #+#             */
/*   Updated: 2016/09/30 04:31:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int		ft_atoi(const char *str)
{
	unsigned int	ret;
	char			sig;

	while (ft_strchr(" \f\n\r\t\v", (int)(*str)) != NULL)
		str++;
	sig = (*str == '-') ? '-' : '+';
	if (*str == '+' || *str == '-')
		str++;
	ft_parse_digit(str, &ret);
	return ((int)(sig == '+' ? ret : 4294967296 - ret));
}
