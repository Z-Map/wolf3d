/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:32:53 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/13 20:19:05 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include "wolf3d.h"

#include "testdata.c"

static int		init_wolf3d(t_w3d *w3d, int ac, char **av)
{
	if ((!mglw_init()) ||
		(!(w3d->win = mglw_openwin(
			mglw_mkwin(MGLW_LEGACY_MODE, MGLW_2DLAYER),
			800, 600, "~*( Wolf3D )*~"))))
		return (-1);
	mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	mglw_setkcb(w3d->win, 1, &w3d_keypress, w3d);
	mglw_setkcb(w3d->win, 2, &w3d_keyrepeate, w3d);
	mglw_setkcb(w3d->win, 0, &w3d_keyrelease, w3d);
	w3d->screen = (mglimg *)mglw_get2dlayer(w3d->win);
	(void)ac;
	(void)av;
	init_testdata(w3d);
	return (0);
}

int				main(int argc, char **argv)
{
	t_w3d					w3d;
	const struct timespec	t = (struct timespec){0, 12000000L};

	if (init_wolf3d(&w3d, argc, argv))
		return (-1);
	while (mglwin_run(w3d.win))
	{
		w3d_layer_draw(&w3d);
		nanosleep(&t, NULL);
	}
	mglw_close();
	return (0);
}
