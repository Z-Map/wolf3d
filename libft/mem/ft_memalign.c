/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 03:49:44 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/06 03:57:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

t_ui				ft_memalign(t_ui i)
{
	char			*c;
	register char	tmp;

	c = (char *)(&i);
	tmp = *c;
	c[0] = c[3];
	c[3] = tmp;
	tmp = c[1];
	c[1] = c[2];
	c[2] = tmp;
	return (i);
}
