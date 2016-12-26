/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:32:53 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/23 19:13:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "wolf3d.h"

static int		init_wolf3d(t_w3d *w3d, int ac, char **av)
{
	if ((!mglw_init()) ||
		(!(w3d->win = mglw_openwin(
			mglw_mkwin(MGLW_LEGACY_MODE, MGLW_2DLAYER),
			800, 600, "~*( Wolf3D )*~"))))
		return (-1);
	mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	// mglw_setkcb(win, 1, &keypress, &ctx);
	// mglw_setkcb(win, 0, &keyrelease, &ctx);
	w3d->screen = (mglimg *)mglw_get2dlayer(w3d->win);
	(void)ac;
	(void)av;
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
		nanosleep(&t, NULL);
	}
	mglw_close();
	return (0);
}
