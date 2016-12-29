/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:32:53 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/29 04:11:31 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include "wolf3d.h"
#define STB_TRUETYPE_IMPLEMENTATION
#include "../mglw/src/include/hlib/stb_truetype.h"

static int		init_wolf3d(t_w3d *w3d, int ac, char **av)
{
	unsigned char	fbuf[1<<18];
	stbtt_fontinfo	font;
	FILE			*file;
	int				i;

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
	file = fopen("font.ttf", "rb");
	fread(fbuf, 1, 1<<18, file);
	for (i = 0; i < (800 * 600); i++)
		((unsigned int *)(w3d->screen->pixels))[i] = 0xff;
	stbtt_InitFont(&font, fbuf, stbtt_GetFontOffsetForIndex(fbuf,0));
	stbtt_MakeCodepointBitmap(&font, w3d->screen->pixels, 800 * 4, 600 * 4, 1, 1.0f, 20.0f, (int)'A');
	/*
	int				x,y,w,h,j;
	unsigned char	*bitmap;
	bitmap = stbtt_GetCodepointBitmap(&font,
		0,stbtt_ScaleForPixelHeight(&font, 20), (int)'A', &w, &h, 0,0);
	y = 1;
	for (j=0; j < h; ++j)
	{
		x = 4;
		for (i=0; i < w; ++i)
		{
			w3d->screen->pixels[(y * 800 * 4) + (x++)] = bitmap[(j * w) + i];
			w3d->screen->pixels[(y * 800 * 4) + (x++)] = bitmap[(j * w) + i];
			w3d->screen->pixels[(y * 800 * 4) + (x++)] = bitmap[(j * w) + i];
			w3d->screen->pixels[(y * 800 * 4) + (x++)] = 0xff;
			printf("%3i-%3i,%3i|", bitmap[j * w + i], x, y);
		}
		++y;
		putchar('\n');
	}
	free(bitmap);
	//*/
	fclose(file);
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
