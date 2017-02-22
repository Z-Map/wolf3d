/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:17:39 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/10 16:14:24 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_lstpush(t_list **alst, t_list *elem)
{
	if (!elem || !alst)
		return ;
	elem->next = *alst;
	*alst = elem;
}
