/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:08:22 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/06 17:53:18 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "wolf3d.h"

static struct			s_testdata
{
	t_w3dlvl			testlvl;
	int					leveldata[10][10];
	t_w3dl				layers[10];
}						G_TESTDATA = {
	.testlvl = {
		(t_w3dlay){ W3D_LVL, 0, &w3d_draw_lvl, &w3d_event_process_lvl },
		(t_v2ui){10, 10}, (t_v2f){1.0f, 1.0f}, NULL, NULL
	},
	.leveldata = {
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, 0, 1, 0, 1, 2, 0, 0, 0, -1 },
		{ -1, 0, 1, 0, 1, 0, 0, 1, 1, -1 },
		{ -1, 0, 0, 0, 1, 0, 0, 0, 0, -1 },
		{ -1, 0, 1, 0, 0, 0, 0, 0, 0, -1 },
		{ -1, 1, 1, 0, 0, 0, 0, 0, 0, -1 },
		{ -1, 0, 1, 0, 0, 0, 1, 0, 0, -1 },
		{ -1, 0, 1, 0, 0, 0, 0, 0, 0, -1 },
		{ -1, 0, 0, 0, 0, 0, 0, 0, 0, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }
	}
};

static void		init_testdata(t_w3d *w3d)
{
	G_TESTDATA.testlvl.lvl_data = (int **)G_TESTDATA.leveldata;
	G_TESTDATA.layers[0].level = G_TESTDATA.testlvl;
	w3d->layers = G_TESTDATA.layers;
	w3d->active_layers[0] = G_TESTDATA.layers;
	w3d->laynum = 1;
	w3d->active_laynum = 1;

}
