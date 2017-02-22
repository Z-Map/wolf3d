/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfconv_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 23:01:47 by map               #+#    #+#             */
/*   Updated: 2016/10/21 18:09:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void			ft_pfconv_float(t_pfb *b, t_pfc *arg, size_t len)
{
	double					d;
	const unsigned long		*l = (unsigned long *)&d;
	int						i;

	d = *((double *)(&(arg->arg)));
	ft_printf_bwrite(b, arg->tmpb, (size_t)(arg->b_len));
	len = (size_t)arg->precision;
	i = 0;
	if (!len)
		return ;
	while ((d < 1.0) && (++i < (int)len))
		d *= 10.0;
	i -= (i) ? 1 : 0;
	ft_printf_bwritec(b, '0', (size_t)i);
	len -= (size_t)i;
	while ((((*l & FT_D_EXP) >> 52) < 1075) && --len)
		d *= 10.0;
	i = FT_MX_FLOATLEN;
	arg->tmpb = ft_ujfillbuf((unsigned long)(ft_fround(&d)), b->tmp, &i);
	ft_printf_bwrite(b, arg->tmpb, (size_t)(i));
	if (len)
		ft_printf_bwritec(b, '0', len);
}
