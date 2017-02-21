/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:32:53 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/21 23:27:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"
#include "parser.h"

static void		resize_callback(void *arg, int w, int h)
{
	t_w3d		*w3d;

	w3d = (t_w3d *)arg;
	mglw_resizeimg(w3d->screen, w, h, MGLW_TF_UNDEFINED);
	w3d->gui = (mglimg *)mglw_get2dlayer(w3d->win);
	ft_bzero(w3d->gui->pixels, w3d->gui->memlen);
	w3d_drawimg(w3d, 10, -10, w3d->helpimg);
	if (w3d_free_rdrdata(w3d) || !w3d_init_rdrdata(w3d))
		mglwin_shouldclose(w3d->win);
	w3d_update_rdrdata(w3d->render, w, h);
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
	ft_strncpy(w3d->paths.data_dir, "data/", CPL * 5);
	w3d->paths.data_len = CPL - 6;
	w3d->paths.cfg_dir = ft_strcpy(w3d->paths.data_dir + CPL, "data/layouts/");
	w3d->paths.cfg_file = w3d->paths.cfg_dir + 13;
	w3d->paths.cfg_len = CPL - 14;
	w3d->paths.lvl_dir = ft_strcpy(w3d->paths.cfg_dir + CPL, "data/levels/");
	w3d->paths.lvl_file = w3d->paths.lvl_dir + 12;
	w3d->paths.lvl_len = CPL - 13;
	w3d->paths.gui_dir = ft_strcpy(w3d->paths.lvl_dir + CPL, "data/gui/");
	w3d->paths.gui_file = w3d->paths.gui_dir + 9;
	w3d->paths.gui_len = CPL - 10;
	w3d->paths.tex_dir = ft_strcpy(w3d->paths.gui_dir + CPL, "data/textures/");
	w3d->paths.tex_file = w3d->paths.tex_dir + 14;
	w3d->paths.tex_len = CPL - 15;
	w3d->default_cfg.bloclen = 0;
	return (w3d_parse_cfg(w3d, "data/layouts/default.w3dc", &w3d->default_cfg));
}

static int		init_wolf3d_lvls(t_w3d *w3d, int ac, char **av)
{
	t_w3dl		*lay;

	ft_bzero(w3d->gui->pixels, w3d->gui->memlen);
	if (!(w3d->openimg = w3d_loadtex(w3d, "@gui/exit_open.png"))
		|| !(w3d->winimg = w3d_loadtex(w3d, "@gui/win.png"))
		|| !(w3d->helpimg = w3d_loadtex(w3d, "@gui/found_key_msg.png"))
		|| !(lay = malloc(sizeof(t_w3dl))))
		return (0);
	w3d_drawimg(w3d, 10, -10, w3d->helpimg);
	if (ac > 1)
		*lay = w3d_parse(w3d, av[1]);
	else
		*lay = w3d_parse(w3d, "data/levels/start.w3dl");
	w3d->layers = lay;
	if (lay->layer.type == W3D_ERROR)
		return (0);
	w3d->active_layers[0] = lay;
	w3d->active_laynum = 1;
	w3d->flags = W3D_MINIMAP;
	return (1);
}

static int		init_wolf3d(t_w3d *w3d, int ac, char **av)
{
	w3d->textures = NULL;
	w3d->layers = NULL;
	w3d->default_cfg.height = (t_v2f){0.0f, 2.0f};
	w3d->default_cfg.grid = NULL;
	w3dp_bloc_tex(NULL, NULL, w3d);
	if (!init_data(w3d) || !mglw_init())
		return (-121);
	if ((!(w3d->win = mglw_openwin(
			mglw_mkwin(MGLW_LEGACY_MODE,
				MGLW_2DLAYER), //| MGLW_FULLSCREEN | MGLW_FULLRES),
			1400, 900, "~*( Wolf3D )*~"))))
		return (-120);
	mglw_setsetting(MGLWS_EXITKEY, MGLW_KEY_ESCAPE);
	mglw_setkcb(w3d->win, 1, &w3d_keypress, w3d);
	mglw_setkcb(w3d->win, 2, &w3d_keyrepeate, w3d);
	mglw_setkcb(w3d->win, 0, &w3d_keyrelease, w3d);
	mglw_setsizecb(w3d->win, &resize_callback, w3d);
	w3d->screen = (mglimg *)mglw_mktexture(1400, 900, MGLW_RGBA, MGLWI_DYNAMIC);
	w3d->gui = (mglimg *)mglw_get2dlayer(w3d->win);
	if (!w3d->screen || !w3d_init_rdrdata(w3d))
		return (-119);
	w3d_update_rdrdata(w3d->render, w3d->screen->x, w3d->screen->y);
	if (!init_wolf3d_lvls(w3d, ac, av))
		return (-104);
	return (0);
}

int				main(int argc, char **argv)
{
	t_w3d				w3d;
	struct timespec		t = (struct timespec){0, 12000000L};
	clock_t				ti;
	double				timer;
	double				avg;
	int					error, i;

	srand(time(NULL));
	if ((error = init_wolf3d(&w3d, argc, argv)))
		return (w3d_nicequit(&w3d, error));
	ti = clock();
	i = 0;
	while (mglwin_run(w3d.win))
	{
		if (w3d.flags & W3D_WIN)
			mglw_draw_itow(w3d.win, w3d.winimg, 0, 0);
		else
		{
			w3d_layer_draw(&w3d);
			w3dlvl_mainloop((t_w3dlvl *)(&(w3d.layers[0].level)), &w3d);
			mglw_draw_itow(w3d.win, w3d.screen, 0, 0);
		}
		ti = clock() - ti;
		timer = (double)ti / CLOCKS_PER_SEC;
		avg += timer;
		timer = (1.0 / 60.0) - timer;
		ti = clock();
		if (timer > 0.0)
		{
			t.tv_nsec = (long)(timer * 999999989L);
			// ft_printf("Sleep : % 6.4F Mx FPS : % 6.4F\e[40D", timer,
			// 	1.0 / ((1.0 / 60.0) - timer));
			nanosleep(&t, NULL);
		}
		if (i++ >= 60)
		{
			avg /= 60.0;
			ft_printf("Mx FPS :%7.2F Average FPS :%7.2F\e[36D",
				1.0 / ((1.0 / 60.0) - timer), 1.0 / avg);
			avg = 0.0;
			i = 0;
		}
		// ft_printf("Mx FPS :% 4.2F\e[15D", 1.0 / ((1.0 / 60.0) - timer));
	}
	return (w3d_nicequit(&w3d, 0));
}
