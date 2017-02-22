/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfbuftouarg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:29:36 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/24 00:57:08 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_parse.h"

int				ft_sfbuftouarg(t_sfb *b, t_sfc *arg, t_cmap cm)
{
	const int	len = arg->maxwidth;

	if (arg->flag & SFF_IGNORE)
		ft_bufskip(&(b->c), len, cm);
	else if (arg->flag & SFF_INTMAX)
		*(uintmax_t *)(arg->arg) = ft_buftouj(&(b->c), len, cm);
	else if (arg->flag & SFF_SIZE_T)
		*(size_t *)(arg->arg) = (size_t)ft_buftouj(&(b->c), len, cm);
	else if (arg->flag & SFF_LONG_LONG)
		*(unsigned long long *)(arg->arg) = (unsigned long long)ft_buftouj(
			&(b->c), len, cm);
	else if (arg->flag & (SFF_LONG | SFF_CAPITAL))
		*(t_ul *)(arg->arg) = ft_buftoul(&(b->c), len, cm);
	else if (arg->flag & SFF_SHORT)
		*(t_us *)(arg->arg) = (t_us)ft_buftoui(&(b->c), len, cm);
	else if (arg->flag & SFF_SHORT_SHORT)
		*(t_uc *)(arg->arg) = (t_uc)ft_buftoui(&(b->c), len, cm);
	else
		*(t_ui *)(arg->arg) = ft_buftoui(&(b->c), len, cm);
	return (0);
}
