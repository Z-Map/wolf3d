/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:48:03 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/10 16:14:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_lstadd(t_list **alst, t_list *elem)
{
	if (!elem || !alst)
		return ;
	elem->next = *alst;
	*alst = elem;
}
