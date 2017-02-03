/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:55:59 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/03 01:16:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_ui		get_texpx(t_v2f pos, float height, mglimg *tex)
{
	pos = (t_v2f){ mxfracf(0.5f * (pos.x + pos.y)) * (tex->x - 1),
		roundf(height * (tex->y - 1)) * tex->x};
	return (((t_ui *)(tex->pixels))[(int)roundf(pos.x) + (int)pos.y]);
}

float			w3d_drawplane(mglimg *scr, t_w3dlvl *lvl, t_v2i *px, t_v4f l)
{
	const float	dimz = cosf(lvl->player.fov.y / 2.0f);
	float		dist;
	t_v2f		pos;
	t_v2i		idx;
	t_w3dbox	*bloc;

	l.x = mxabsf(l.x) + 0.0001f;
	dist = ((dimz * 1.16f) / (l.x)) / l.y;
	pos.x = lvl->player.position.x + (dist * l.z);
	pos.y = lvl->player.position.y + (dist * l.w);
	idx = (t_v2i){(int)pos.x, (int)pos.y};
	if ((l.x < 0.01f) || (!idx.x && (pos.x < 0.0)) || (!idx.y && (pos.y < 0.0))
		|| !(bloc = w3dlvl_getbox_vi(lvl->lvl_data, idx)))
		((t_ui *)scr->pixels)[px->x + px->y * scr->x] = 0xff;
	else if (bloc->tex)
		((t_ui *)scr->pixels)[px->x + px->y * scr->x] = get_texpx((t_v2f){
			mxabsf(pos.x) + 1.0f, 0.0f},
			mxfracf(0.5f * mxabsf(pos.y) + 0.5f), bloc->tex);
	else
		((t_ui *)scr->pixels)[px->x + px->y * scr->x] =
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
		while (height-- && px->y)
			pxs[px->x + px->y-- * scr->x] = 0xff;
	else if ((ray->bloc) && (ray->bloc->tex))
		while (height-- && px->y)
			pxs[px->x + px->y-- * scr->x] = get_texpx(ray->end,
				(float)height / h, ray->bloc->tex);
	else
		while (height-- && px->y)
			pxs[px->x + px->y-- * scr->x] = *((t_ui *)&(ray->bloc->color));
	if (px->y)
		px->y++;
	return (h);
}

void			w3d_drawcol(t_w3dlvl *lvl, t_w3dthr *ctx, t_ray *ray)
{
	t_v2i		px;
	int			height;
	int			offset;
	t_v4f		look;
	float		step;

	px = (t_v2i){ctx->x, ctx->w3d->screen->y};
	look = (t_v4f){-sin(lvl->player.fov.y / 2.0f), ctx->xfix, ray->dir.x, ray->dir.y};
	step = (look.x * -2.0f) / (float)px.y;
	height = round(((lvl->lvl_data->height.y - lvl->lvl_data->height.x)
		* (float)(ctx->w3d->screen->y)) / ray->distance);
	if (height >= px.y)
		w3d_drawwall(ctx->w3d->screen, &px, height, ray);
	else
		offset = (px.y - height) / 2;
	while (px.y-- > 0)
	{
		if (!(offset--))
			look.x += step * w3d_drawwall(ctx->w3d->screen, &px, height, ray);
		else
			look.x += step * w3d_drawplane(ctx->w3d->screen, lvl, &px, look);
	}
}

int				w3d_draw_lvl(t_w3dl *lay, t_w3d *w3d)
{
	const float	dimz = cos(lay->level.player.fov.x / 2.0f);
	t_v2f		start;
	t_v2f		dir;
	t_v4f		look;
	int			x;
	// test var
	// t_ray		*ray;
	// t_w3dthr	ctx;

	w3d_update_player(w3d, &(lay->level));
	x = w3d->screen->x;
	look = (t_v4f){lay->level.player.rotations.x, lay->level.player.rotations.y,
		-sin(lay->level.player.fov.x / 2.0f), 0.0f};
	look.w = (look.z * -2.0f) / (float)x;
	start = v3to2f(lay->level.player.position);
	while (x--)
	{
		dir = normalize2f((t_v2f){dimz, look.z});
		w3d->render.rays[x] = w3d_mkray(start,
			(t_v2f){look.x * dir.x + dir.y * look.y,
				-look.x * dir.y + look.y * dir.x}, 0, dir.x);
		look.z += look.w;
		// Test part
		// ctx = (t_w3dthr){ .x = x, .xfix = dir.x, .w3d = w3d, .lay = lay};
		// ray = &(w3d->render.rays[x]);
		// ray->distance = -1.0f;
		// w3d_raycast(lay->level.lvl_data, ray);
		// ray->distance *= dir.x;
		// w3d_drawcol(&(lay->level), &ctx, ray);
	}
	w3d_start_renderthreads(lay, w3d);
	return (0);
}
