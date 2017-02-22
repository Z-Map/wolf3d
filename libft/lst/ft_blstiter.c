/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:21:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/15 00:57:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void			*ft_blstiter(t_blit *iterator)
{
	t_blst		*blst;
	size_t		i;

	i = iterator->idx;
	blst = iterator->bloc;
	if (!blst || (i >= blst->len))
		return (NULL);
	++iterator->idx;
	if (iterator->idx >= blst->len)
	{
		iterator->idx = 0;
		iterator->bloc = blst->next;
	}
	return ((void *)((unsigned long)(blst->data) + (blst->csize * i)));
}
