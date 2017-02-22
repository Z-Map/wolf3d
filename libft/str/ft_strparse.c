/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 23:47:10 by qloubier          #+#    #+#             */
/*   Updated: 2016/05/22 07:28:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int			ft_strparse(char *str, char s, int (**parser)(char *, void *),
				void *param)
{
	int		ret;

	ret = 0;
	while (*str && *str != s)
		++str;
	if (*(str++) == s)
		while ((ret = parser[(int)(*(str))](str, param)) > 0)
			++str;
	return (ret);
}
