/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsfrac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 18:28:39 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/28 18:40:02 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathex/utils.h"

float				mxfracf(register float d)
{
	return (d - (float)(int)d);
}

double				mxfrac(register double d)
{
	return (d - (double)(long)d);
}
