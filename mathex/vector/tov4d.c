/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tov4d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 01:37:48 by qloubier          #+#    #+#             */
/*   Updated: 2016/06/26 21:47:01 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/vector.h"

t_v4d					nv4d(double i)
{
	return ((t_v4d){i, i, i, i});
}