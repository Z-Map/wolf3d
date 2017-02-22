/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfbuftoarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:29:36 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/24 00:57:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_parse.h"

int				ft_sfbuftoarg(t_sfb *b, t_sfc *arg, t_cmap cm)
{
	const int	len = arg->maxwidth;

	if (arg->flag & SFF_IGNORE)
		ft_bufskip(&(b->c), len, cm);
	else if (arg->flag & SFF_INTMAX)
		*(intmax_t *)(arg->arg) = ft_buftoj(&(b->c), len, cm);
	else if (arg->flag & SFF_SIZE_T)
		*(ssize_t *)(arg->arg) = (ssize_t)ft_buftoj(&(b->c), len, cm);
	else if (arg->flag & SFF_LONG_LONG)
		*(long long *)(arg->arg) = (long long)ft_buftoj(&(b->c), len, cm);
	else if (arg->flag & (SFF_LONG | SFF_CAPITAL))
		*(long *)(arg->arg) = ft_buftol(&(b->c), len, cm);
	else if (arg->flag & SFF_SHORT)
		*(short *)(arg->arg) = (short)ft_buftoi(&(b->c), len, cm);
	else if (arg->flag & SFF_SHORT_SHORT)
		*(char *)(arg->arg) = (char)ft_buftoi(&(b->c), len, cm);
	else
		*(int *)(arg->arg) = ft_buftoi(&(b->c), len, cm);
	return (0);
}
