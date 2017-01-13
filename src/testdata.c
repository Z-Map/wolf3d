/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:08:22 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/12 22:10:45 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "wolf3d.h"

static struct			s_testdata
{
	t_w3dlvl			testlvl;
	t_w3dmap			maps[5];
	int					leveldata[10][10];
	t_w3dl				layers[10];
}						G_TESTDATA = {
	.testlvl = {
		.layer = (t_w3dlay){ W3D_LVL, 0, &w3d_draw_lvl, &w3d_event_process_lvl },
		.size = (t_v2ui){10, 10}, .height = (t_v2f){0.0f, 2.0f},
		.level_num = 1, .padding = 0,
		.player = (t_w3dpc){  },
		.lvl_data = NULL, .octree = NULL
	},
	.maps = {
		(t_w3dmap){
			.bloclen = 4, .flags = 0,
			.position = (t_v2ui){0, 0},
			.size = (t_v2ui){10, 10},
			.height = (t_v2f){0.0f, 2.0f},
			.blocs = (t_w3dbox[4]){
				(t_w3dbox){ .flags = 0, .userid = 0,
					.color = (t_rgba){255, 255, 255, 255}, .tex = NULL},
				(t_w3dbox){
					.flags = W3D_BLOC_WALL | W3D_BLOC_COLLIDER,
					.userid = 1, .color = (t_rgba){255, 255, 255, 255},
					.tex = NULL},
				(t_w3dbox){ .flags = W3D_BLOC_WALL | W3D_BLOC_COLLIDER,
					.userid = 2, .color = (t_rgba){0, 255, 127, 255},
					.tex = NULL },
				(t_w3dbox){ .flags = W3D_BLOC_COLLIDER,
					.userid = -1, .color = (t_rgba){255, 0, 0, 255},
					.tex = NULL }
			},
			.grid = NULL
		},
		(t_w3dmap){
			.bloclen = 0, .flags = 0,
			.position = (t_v2ui){0, 0},
			.size = (t_v2ui){0, 0},
			.height = (t_v2f){0.0f, 2.0f},
			.blocs = NULL, .grid = NULL
		},
		(t_w3dmap){
			.bloclen = 0, .flags = 0,
			.position = (t_v2ui){0, 0},
			.size = (t_v2ui){0, 0},
			.height = (t_v2f){0.0f, 2.0f},
			.blocs = NULL, .grid = NULL
		},
		(t_w3dmap){
			.bloclen = 0, .flags = 0,
			.position = (t_v2ui){0, 0},
			.size = (t_v2ui){0, 0},
			.height = (t_v2f){0.0f, 2.0f},
			.blocs = NULL, .grid = NULL
		},
		(t_w3dmap){
			.bloclen = 0, .flags = 0,
			.position = (t_v2ui){0, 0},
			.size = (t_v2ui){0, 0},
			.height = (t_v2f){0.0f, 2.0f},
			.blocs = NULL, .grid = NULL
		},
	},
	.leveldata = {
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, 0, 1, 0, 1, 2, 0, 0, 0, -1 },
		{ -1, 0, 1, 0, 1, 0, 0, 1, 1, -1 },
		{ -1, 0, 0, 0, 1, 0, 0, 0, 0, -1 },
		{ -1, 0, 1, 0, 0, 0, 0, 0, 0, -1 },
		{ -1, 1, 1, 0, 0, 0, 0, 0, 0, -1 },
		{ -1, 0, 1, 0, 0, 0, 1, 0, 0, -1 },
		{ -1, 0, 1, 0, 1, 0, 0, 0, 0, -1 },
		{ -1, 0, 0, 1, 1, 2, 2, 0, 0, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }
	}
};

static void		init_testdata(t_w3d *w3d)
{
	G_TESTDATA.testlvl.lvl_data = G_TESTDATA.maps;
	G_TESTDATA.testlvl.lvl_data->grid = (int **)G_TESTDATA.leveldata;
	G_TESTDATA.layers[0].level = G_TESTDATA.testlvl;
	w3d->layers = G_TESTDATA.layers;
	w3d->active_layers[0] = G_TESTDATA.layers;
	w3d->laynum = 1;
	w3d->active_laynum = 1;

}
