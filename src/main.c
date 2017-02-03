/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:32:53 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/03 16:05:49 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

#include "testdata.c"

static void		resize_callback(void *arg, int w, int h)
{
	t_w3d		*w3d;

	w3d = (t_w3d *)arg;
	w3d->screen = (mglimg *)mglw_get2dlayer(w3d->win);
	w3d->render.rays = (t_ray *)malloc(sizeof(t_ray) * w);
	w3d->render.ratio.x = (float)h / (float)w;
	w3d->render.ratio.y = (float)w / (float)h;
}

static int		init_data(t_w3d *w3d)
{
	int			i;

	i = 128;
	while (i--)
		w3d->strbuf[i] = (t_str){0, NULL};
	w3d->cbuffer = malloc(4096);
	w3d->paths.data_dir = malloc(CPL * 5);
	if (!w3d->cbuffer || !w3d->paths.data_dir)
		return (0);
	ft_strcnpy(w3d->paths.data_dir, "data/", CPL * 5);
	w3d->paths.data_len = CPL - 6;
	w3d->paths.cfg_dir = ft_strcpy(w3d->paths.data_dir + CPL, "data/layouts/");
	w3d->paths.cfg_len = CPL - 14;
	w3d->paths.lvl_dir = ft_strcpy(w3d->paths.cfg_dir + CPL, "data/textures/");
	w3d->paths.cfg_len = CPL - 15;
	w3d->paths.gui_dir = ft_strcpy(w3d->paths.lvl_dir + CPL, "data/gui/");
	w3d->paths.cfg_len = CPL - 10;
	w3d->paths.tex_dir = ft_strcpy(w3d->paths.gui_dir + CPL, "data/levels/");
	w3d->paths.cfg_len = CPL - 13;
	return (w3d_parse_cfg(w3d, "data/layouts/default.w3dc", &w3d->default_cfg));
}

static int		init_wolf3d(t_w3d *w3d, int ac, char **av)
{
	if (!init_data(w3d))
		return (0);
	if ((!mglw_init()) ||
		(!(w3d->win = mglw_openwin(
			mglw_mkwin(MGLW_LEGACY_MODE,
				MGLW_2DLAYER), //| MGLW_FULLSCREEN | MGLW_FULLRES),
			800, 600, "~*( Wolf3D )*~"))))
		return (-1);
	mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	mglw_setkcb(w3d->win, 1, &w3d_keypress, w3d);
	mglw_setkcb(w3d->win, 2, &w3d_keyrepeate, w3d);
	mglw_setkcb(w3d->win, 0, &w3d_keyrelease, w3d);
	mglw_setsizecb(w3d->win, &resize_callback, w3d);
	w3d->screen = (mglimg *)mglw_get2dlayer(w3d->win);
	(void)ac;
	(void)av;
	w3d->render.ratio.x = (float)w3d->screen->y / (float)w3d->screen->x;
	w3d->render.ratio.y = (float)w3d->screen->x / (float)w3d->screen->y;
	w3d->render.rays = (t_ray *)malloc(sizeof(t_ray) * w3d->screen->x);
	init_testdata(w3d);
	return (0);
}

static void		quit_wolf3d(t_w3d *w3d)
{
	free(w3d->render.rays);
}

int				main(int argc, char **argv)
{
	t_w3d				w3d;
	struct timespec		t = (struct timespec){0, 12000000L};
	clock_t				ti;
	double				timer;

	if (init_wolf3d(&w3d, argc, argv))
		return (-1);
	ti = clock();
	while (mglwin_run(w3d.win))
	{
		w3d_layer_draw(&w3d);
		ti = clock() - ti;
		timer = (double)ti / CLOCKS_PER_SEC;
		timer = (1.0 / 60.0) - timer;
		ti = clock();
		if (timer > 0.0)
		{
			t.tv_nsec = (long)(timer * 999999989L);
			// ft_printf("Sleep : % 6.4F Mx FPS : % 6.4F\e[40D", timer,
			// 	1.0 / ((1.0 / 60.0) - timer));
			nanosleep(&t, NULL);
		}
		// ft_printf("Sleep : % 6.4F Mx FPS : % 6.4F\e[38D", timer,
		// 		1.0 / ((1.0 / 60.0) - timer));
	}
	mglw_close();
	quit_wolf3d(&w3d);
	return (0);
}
