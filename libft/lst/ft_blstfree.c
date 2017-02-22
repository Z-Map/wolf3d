/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:46:18 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/18 23:01:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"

void			ft_blstfree(t_blst **blst)
{
	t_blst		*blsit;

	if (!blst || !(*blst))
		return ;
	while (blst && *blst)
	{
		blsit = (*blst)->next;
		free((void *)(*blst));
		(*blst) = blsit;
	}
	*blst = NULL;
}
