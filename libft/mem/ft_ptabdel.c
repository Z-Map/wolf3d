/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptabdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 13:02:07 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/24 14:31:03 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_memory.h"

void	ft_ptabdel(void ***tptr)
{
	void	**tmpptr;

	if (!tptr || !(*tptr))
		return ;
	tmpptr = *tptr;
	while (*tmpptr)
		free(*(tmpptr++));
	free(*tptr);
	*tptr = NULL;
}
