/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:01:32 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/22 18:28:06 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*nstr;

	len = 0;
	if (!s)
		return (NULL);
	while (*s && ft_strchr(FT_WHITESPACE, (int)(*s)))
		s++;
	if (!(*s))
		return (ft_memalloc(1));
	len = ft_strlen(s) - 1;
	while (ft_strchr(FT_WHITESPACE, (int)(s[len])))
		--len;
	if ((nstr = ft_strnew(len + 1)))
		ft_strncpy(nstr, s, len + 1);
	return (nstr);
}
