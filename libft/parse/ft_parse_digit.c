/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 03:53:28 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/09 13:51:48 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_parse.h"

const char			*ft_parse_digit(const char *str, unsigned int *num)
{
	*num = 0;
	while (ft_isdigit((int)(*str)))
		*num = ((*num * 10) + (unsigned int)(*(str++) - '0'));
	return (str);
}
