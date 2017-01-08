/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:07:18 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/06 17:07:34 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		w3d_layer_draw(t_w3d *w3d)
{
	t_w3dl		*lay;
	int			i;

	i = w3d->active_laynum;
	lay = NULL;
	while (i--)
	{
		lay = w3d->active_layers[i];
		lay->layer.drawer(lay, w3d);
	}
}
