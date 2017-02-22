/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 22:13:30 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/05 01:04:02 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int					ft_printf_loop(const char *fstr, t_pfb *pfb)
{
	const char		*c;
	size_t			len;

	while ((c = ft_forf(fstr, "%", &len)))
	{
		ft_printf_bwrite(pfb, fstr, len);
		fstr = ft_printf_parse(c + 1, pfb);
	}
	if (len)
		ft_printf_bwrite(pfb, fstr, len);
	ft_printf_bflush(pfb);
	return (0);
}
