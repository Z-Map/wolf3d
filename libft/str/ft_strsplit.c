/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 01:21:18 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 21:52:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	**split;
	char	*cur;

	if (!s)
		return (NULL);
	i = 0;
	s = (char const *)ft_strchrnot(s, (int)c);
	len = (s) ? ft_wrdcount(s, c) : 0;
	if (!(split = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		cur = ft_strchr(s, (int)c);
		cur = (cur) ? cur : ft_strchr(s, 0);
		if (!(split[i] = ft_strnew((size_t)(cur - s))))
			break ;
		split[i] = ft_strncpy(split[i], s, (size_t)(cur - s));
		++i;
		s = (char const *)(ft_strchrnot(cur, (int)c));
	}
	if (i != len)
		ft_ptabdel((void ***)(&split));
	return (split);
}
