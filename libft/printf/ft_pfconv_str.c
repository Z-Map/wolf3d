/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:44:05 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/09 22:12:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void			ft_pfconv_str(t_pfb *b, t_pfc *arg, size_t len)
{
	int			i;

	i = (int)len - arg->b_len;
	if (i > 0)
		ft_printf_bwritec(b, '0', (size_t)i);
	if (arg->arg)
	{
		if (arg->type == PFT_STR)
			ft_printf_bwrite(b, (char *)(arg->arg), (size_t)arg->b_len);
		else
			ft_printf_bwritew(b, (wchar_t *)(arg->arg), (size_t)arg->b_len);
	}
	else
		ft_printf_bwrite(b, g_pf_nullstr, (size_t)arg->b_len);
}
