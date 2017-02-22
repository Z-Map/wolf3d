/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfbuftofarg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:29:36 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/24 00:57:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_parse.h"

int				ft_sfbuftofarg(t_sfb *b, t_sfc *arg, t_cmap cm)
{
	const int	len = arg->maxwidth;

	if (arg->flag & SFF_IGNORE)
		ft_bufskipf(&(b->c), len, cm);
	else if (arg->flag & SFF_LONG_LONG)
		*(long double *)(arg->arg) = ft_buftold(&(b->c), len, cm);
	else if (arg->flag & (SFF_LONG | SFF_CAPITAL))
		*(double *)(arg->arg) = ft_buftod(&(b->c), len, cm);
	else
		*(float *)(arg->arg) = ft_buftof(&(b->c), len, cm);
	return (0);
}
