/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buftoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:00:11 by map               #+#    #+#             */
/*   Updated: 2016/11/09 14:55:54 by map              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

unsigned long			ft_buftoul(const char **str, int len, t_cmap cm)
{
	unsigned long	ret;

	*str = ft_parse_cmap(*str, &ret, cm, len);
	return (ret);
}
