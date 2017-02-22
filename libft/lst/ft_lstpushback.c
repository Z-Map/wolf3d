/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:27:29 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/10 16:14:29 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_lstpushback(t_list **alst, t_list *elem)
{
	if (*alst)
		ft_lstlast(*alst)->next = elem;
	else
		*alst = elem;
}
