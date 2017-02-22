/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:55:55 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 13:04:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			w3d_layer_evt_process(t_w3d *w3d, t_w3devt evt, int flag)
{
	t_w3dl		*lay;
	int			i;

	i = 0;
	lay = *(w3d->active_layers);
	while ((i++ < w3d->active_laynum) && (!(lay->layer.evt_process) ||
		!(lay->layer.flags & flag) ||
		!(lay->layer.evt_process(lay, w3d, evt))))
		lay = w3d->active_layers[i];
}

int				w3d_keypress(void *root, int k)
{
	t_w3d		*w3d;
	t_w3devt	evt;

	w3d = (t_w3d *)root;
	evt = (t_w3devt){ k, 2, 0, 0};
	if (w3d->flags & W3D_WIN)
		mglwin_stop(w3d->win);
	else
		w3d_layer_evt_process(w3d, evt, W3DLAY_PRESSINPUT);
	return (0);
}

int				w3d_keyrepeate(void *root, int k)
{
	t_w3d		*w3d;
	t_w3devt	evt;

	w3d = (t_w3d *)root;
	evt = (t_w3devt){ k, 1, 0, 0};
	w3d_layer_evt_process(w3d, evt, W3DLAY_REPEATINPUT);
	return (0);
}

int				w3d_keyrelease(void *root, int k)
{
	t_w3d		*w3d;
	t_w3devt	evt;

	w3d = (t_w3d *)root;
	evt = (t_w3devt){ k, 0, 0, 0};
	if (!(w3d->flags & W3D_WIN))
		w3d_layer_evt_process(w3d, evt, W3DLAY_RELEASEINPUT);
	if (k == MGLW_KEY_F)
		mglwin_togglefullscreen(w3d->win, 1);
	return (0);
}
