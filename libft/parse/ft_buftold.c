/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buftold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:00:11 by map               #+#    #+#             */
/*   Updated: 2016/11/23 23:53:55 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

long double		ft_buftold(const char **str, int len, t_cmap cm)
{
	long double	d;
	char		sig;

	sig = (**str == '-') ? 0 : 1;
	if (**str == '+' || **str == '-')
	{
		(*str)++;
		len--;
	}
	d = (long double)0.0;
	if ((len >= 3))
	{
		if (!ft_strncmp(*str, "inf", 3))
			*((t_ul *)&d) = FT_D_EXP;
		else if (!ft_strncmp(*str, "nan", 3))
			*((t_ul *)&d) = FT_D_EXP + 1ul;
	}
	if (*((t_ul *)&d))
		*str += 3;
	else
		*str = ft_parseld(*str, &d, cm, len);
	return (sig ? d : -d);
}
