/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8wcsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 01:34:50 by map               #+#    #+#             */
/*   Updated: 2016/10/06 01:47:21 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unicode.h"

int				ft_utf8wcsize(const wchar_t c)
{
	if (c < 0)
		return (0);
	else if (c > 0xFFFF)
		return (4);
	else if (c > 0x7FF)
		return (3);
	else if (c > 0x7F)
		return (2);
	return (1);
}
