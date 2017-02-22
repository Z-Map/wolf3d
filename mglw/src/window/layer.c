/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:59:43 by map               #+#    #+#             */
/*   Updated: 2016/12/21 15:31:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mglw_intern/window.h"
#include "mglw_intern/image.h"

mgltex		*mglw_get2dlayer(mglwin *win)
{
	if ((win) && (win->data->state & 1) && (win->flags & MGLW_2DLAYER))
		return (win->data->layer2D);
	return (NULL);
}
