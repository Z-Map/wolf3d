/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buftoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:00:11 by map               #+#    #+#             */
/*   Updated: 2016/11/09 16:02:00 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

int					ft_buftoi(const char **str, int len, t_cmap cm)
{
	unsigned long	ret;
	char			sig;

	sig = (**str == '-') ? 0 : 1;
	if (**str == '+' || **str == '-')
	{
		(*str)++;
		len--;
	}
	*str = ft_parse_cmap(*str, &ret, cm, len);
	return ((int)(sig ? ret : 0xFFFFFFFFu - (unsigned int)(ret - 1)));
}
