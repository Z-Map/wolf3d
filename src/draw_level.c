/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:55:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/20 04:27:41 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_ui		get_texpx(t_v2f pos, float height, mglimg *tex)
{
	pos = (t_v2f){mxfracf(0.5f * (pos.x + pos.y)) * (tex->x - 1),
		roundf(height * (tex->y - 1)) * tex->x};
	return (((t_ui *)(tex->pixels))[(int)roundf(pos.x) + (int)pos.y]);
}

float			w3d_drawplane(t_w3d *w3d, t_w3dlvl *lvl, t_v2i *px, t_v2f l)
{
	float		dist;
	t_v2f		pos;
	t_v2i		idx;
	t_w3dbox	*bloc;
	int			i;

	i = px->x + px->y * w3d->screen->x;
	dist =  mxabsf(w3d->render.hdist[px->y]) / w3d->render.wdist[px->x].x;
	pos.x = lvl->player.position.x + (dist * l.x);
	pos.y = lvl->player.position.y + (dist * l.y);
	dist = w3d->render.hdist[px->y];
	idx = (t_v2i){(int)pos.x, (int)pos.y};
	if ((!idx.x && (pos.x < 0.0)) || (!idx.y && (pos.y < 0.0)) ||
		!(bloc = w3dlvl_getbox_vi(&(lvl->lvl_data[lvl->active_lvl]), idx, 0)))
		((t_ui *)w3d->screen->pixels)[i] = 0xff000000;
	else if (((dist < 0.0) && bloc->gtex) || ((dist >= 0.0) && bloc->rtex))
		((t_ui *)w3d->screen->pixels)[i] = w3d_drawshade(get_texpx(
				(t_v2f){mxabsf(pos.x) + 1.0f, 0.0f}, mxfracf(0.5f *
				mxabsf(pos.y) + 0.5f), (dist < 0.0) ? bloc->gtex : bloc->rtex),
				(t_v3f){0.0f, 0.0f, (dist < 0.0) ? 1.0f : -1.0f});
	else
		((t_ui *)w3d->screen->pixels)[i] =
			*((t_ui *)&(bloc->color));
	return (1.0f);
}

float			w3d_drawwall(mglimg *scr, t_v2i *px, int height, t_ray *ray)
{
	const float	h = (float)height;
	t_ui		*pxs;

	if (height > px->y)
		height -= (height - px->y) / 2;
	if (px->y == (int)scr->y)
		px->y--;
	if (ray->normale.x)
		ray->end = (t_v2f){ray->end.y, ray->end.x};
	pxs = (t_ui *)scr->pixels;
	if (!ray->bloc)
		while (height-- && (px->y >= 0))
			pxs[px->x + px->y-- * scr->x] = 0xff000000;
	else if ((ray->bloc) && (ray->bloc->wtex))
		while (height-- && (px->y >= 0))
			pxs[px->x + px->y-- * scr->x] = w3d_drawshade(get_texpx(ray->end,
				(float)height / h, ray->bloc->wtex), ray->normale);
	else
		while (height-- && (px->y >= 0))
			pxs[px->x + px->y-- * scr->x] = w3d_drawshade(
				*((t_ui *)&(ray->bloc->color)), ray->normale);
	if (px->y > 0)
		px->y++;
	return (h);
}

void			w3d_drawcol(t_w3dlvl *lvl, t_w3dthr *ctx, t_ray *ray)
{
	t_v2i		px;
	int			height;
	int			offset;
	t_v2f		look;

	px = (t_v2i){ctx->x, ctx->w3d->screen->y};
	look = (t_v2f){ray->dir.x, ray->dir.y};
	height = ceilf(((lvl->lvl_data[lvl->active_lvl].height.y
		- lvl->lvl_data[lvl->active_lvl].height.x)
		* (float)(ctx->w3d->screen->y)) / ray->distance);
	if (height >= px.y)
		w3d_drawwall(ctx->w3d->screen, &px, height, ray);
	else
		offset = ceilf((float)(px.y - height) / 2.0f);
	while (px.y-- > 0)
	{
		if (!(offset--))
			w3d_drawwall(ctx->w3d->screen, &px, height, ray);
		else
			w3d_drawplane(ctx->w3d, lvl, &px, look);
	}
}

#include <stdio.h>
static void		w3d_drawminimap(t_w3dlvl *lvl, t_w3d *w3d)
{
	t_v2i		p;
	t_v2i		t;
	t_w3dmap	*map;
	t_w3dbox	*bloc;

	map = &(lvl->lvl_data[lvl->active_lvl]);
	t = (t_v2i){mxmin((int)map->size.x * 6, w3d->screen->x),
		mxmin((int)map->size.y * 6, w3d->screen->y - 1)};
	p = (t_v2i){w3d->screen->x, t.y};
	while (p.x-- > 0 && t.x-- >= 0)
		((t_ui *)(w3d->gui->pixels))[p.x + (p.y * w3d->gui->x)] = 0xff000000;
	while (p.y-- > 0)
	{
		t.y--;
		p.x = w3d->screen->x;
		t.x = mxmin((int)map->size.x * 6, w3d->screen->x);
		while ((p.x-- > 0) && (t.x > 0))
		{
			bloc = w3dlvl_getbox(map, --t.x / 6, t.y / 6, 0);
			if (bloc && (((map->grid)[t.y / 6][t.x / 6].flags) & W3D_BLOC_VISITED))
				((t_ui *)(w3d->gui->pixels))[p.x + (p.y * w3d->gui->x)]
					= *((t_ui *)&(bloc->color));
			else
				((t_ui *)(w3d->gui->pixels))[p.x + (p.y * w3d->gui->x)] = 0xd0000000;
			if (((t.y / 6) == (int)(lvl->player.position.y)) &&
				((t.x / 6) == (int)(lvl->player.position.x)))
				((t_ui *)(w3d->gui->pixels))[p.x + (p.y * w3d->gui->x)] = 0xffffffff;
		}
		if (p.x >= 0)
			((t_ui *)(w3d->gui->pixels))[p.x + (p.y * w3d->gui->x)] = 0xff000000;
	}
}

int				w3d_draw_lvl(t_w3dl *lay, t_w3d *w3d)
{
	t_v2f		*xv;
	t_v2f		start;
	t_v2f		look;
	int			x;
	// test var
	// t_ray		*ray;
	// t_w3dthr	ctx;

	xv = w3d->render.wdist;
	w3d_update_player(w3d, &(lay->level));
	x = w3d->screen->x;
	look = v4to2f(lay->level.player.rotations);
	start = v3to2f(lay->level.player.position);
	while (x--)
	{
		w3d->render.rays[x] = w3d_mkray(start,
			(t_v2f){look.x * xv[x].x + xv[x].y * look.y,
			-look.x * xv[x].y + look.y * xv[x].x}, 0, -1.0f);
		// Test part
		// ctx = (t_w3dthr){ .x = x, .xfix = xv[x].x, .w3d = w3d, .lay = lay};
		// ray = &(w3d->render.rays[x]);
		// w3d_raycast(lay->level.lvl_data, ray);
		// ray->distance *= xv[x].x;
		// w3d_drawcol(&(lay->level), &ctx, ray);
	}
	w3d_start_renderthreads(lay, w3d);
	w3d_drawminimap(&(lay->level), w3d);
	return (0);
}
