/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 00:06:38 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 04:19:40 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/utils.h"

unsigned int		mxmaxu(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned int		mxminu(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}
