/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 01:09:51 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/11 00:35:37 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_wstring.h"

size_t	ft_wcslen(const wchar_t *s)
{
	size_t len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}
