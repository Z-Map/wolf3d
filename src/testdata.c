/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:08:22 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/28 12:36:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "wolf3d.h"

static struct			s_testdata
{
	t_w3dlvl			testlvl;
	t_w3dmap			maps[5];
	int					leveldata[20][20];
	int					*leveldataptr[20];
	t_w3dl				layers[10];
	mglimg				*textures[10];
}						G_TESTDATA = {
	.testlvl = {
		.layer = (t_w3dlay){ W3D_LVL, W3DLAY_PRESSINPUT | W3DLAY_RELEASEINPUT,
			&w3d_draw_lvl, &w3d_event_process_lvl },
		.size = (t_v2ui){20, 20}, .height = (t_v2f){0.0f, 2.0f},
		.level_num = 1, .padding = 0,
		.player = (t_w3dpc){ .movkey = 0, .flags = 0,
			.position = (t_v3f){ 10.5f, 10.5f, 0.5f}, .speed = 0.05f,
			.movement = (t_v3f){ 0.0f, 0.0f, 0.0f},
			.eyes = (t_v3f){ 0.0f, 0.0f, 0.0f}, .look = (t_v2f){0.0f, 0.0f}},
		.lvl_data = NULL, .octree = NULL
	},
	.maps = {
		(t_w3dmap){
			.bloclen = 4, .flags = 0,
			.position = (t_v2ui){0, 0},
			.size = (t_v2ui){20, 20},
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
				(t_w3dbox){ .flags = W3D_BLOC_WALL | W3D_BLOC_COLLIDER,
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
		{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 3 },
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 3 },
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3 },
		{ 3, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3 },
		{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 }
	},
	.leveldataptr = { NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL}
};

static void		init_testdata(t_w3d *w3d)
{
	G_TESTDATA.testlvl.lvl_data = G_TESTDATA.maps;
	G_TESTDATA.leveldataptr[0] = G_TESTDATA.leveldata[0];
	G_TESTDATA.leveldataptr[1] = G_TESTDATA.leveldata[1];
	G_TESTDATA.leveldataptr[2] = G_TESTDATA.leveldata[2];
	G_TESTDATA.leveldataptr[3] = G_TESTDATA.leveldata[3];
	G_TESTDATA.leveldataptr[4] = G_TESTDATA.leveldata[4];
	G_TESTDATA.leveldataptr[5] = G_TESTDATA.leveldata[5];
	G_TESTDATA.leveldataptr[6] = G_TESTDATA.leveldata[6];
	G_TESTDATA.leveldataptr[7] = G_TESTDATA.leveldata[7];
	G_TESTDATA.leveldataptr[8] = G_TESTDATA.leveldata[8];
	G_TESTDATA.leveldataptr[9] = G_TESTDATA.leveldata[9];
	G_TESTDATA.leveldataptr[10] = G_TESTDATA.leveldata[10];
	G_TESTDATA.leveldataptr[11] = G_TESTDATA.leveldata[11];
	G_TESTDATA.leveldataptr[12] = G_TESTDATA.leveldata[12];
	G_TESTDATA.leveldataptr[13] = G_TESTDATA.leveldata[13];
	G_TESTDATA.leveldataptr[14] = G_TESTDATA.leveldata[14];
	G_TESTDATA.leveldataptr[15] = G_TESTDATA.leveldata[15];
	G_TESTDATA.leveldataptr[16] = G_TESTDATA.leveldata[16];
	G_TESTDATA.leveldataptr[17] = G_TESTDATA.leveldata[17];
	G_TESTDATA.leveldataptr[18] = G_TESTDATA.leveldata[18];
	G_TESTDATA.leveldataptr[19] = G_TESTDATA.leveldata[19];
	G_TESTDATA.testlvl.lvl_data->grid = G_TESTDATA.leveldataptr;
	G_TESTDATA.layers[0].level = G_TESTDATA.testlvl;
	G_TESTDATA.textures[0] = mglw_loadimage("walltex.png", 0, 4);
	G_TESTDATA.maps->blocs[1].flags |= W3D_BLOC_TEX;
	G_TESTDATA.maps->blocs[1].tex = G_TESTDATA.textures[0];
	G_TESTDATA.textures[1] = mglw_loadimage("greenwalltex.png", 0, 4);
	G_TESTDATA.maps->blocs[2].flags |= W3D_BLOC_TEX;
	G_TESTDATA.maps->blocs[2].tex = G_TESTDATA.textures[1];
	G_TESTDATA.textures[2] = mglw_loadimage("limitwall.png", 0, 4);
	G_TESTDATA.maps->blocs[3].flags |= W3D_BLOC_TEX;
	G_TESTDATA.maps->blocs[3].tex = G_TESTDATA.textures[2];
	w3d->layers = G_TESTDATA.layers;
	w3d->active_layers[0] = G_TESTDATA.layers;
	w3d->laynum = 1;
	w3d->active_laynum = 1;

}
