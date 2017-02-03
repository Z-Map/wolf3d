/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:20:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/01 21:58:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "wolf3d.h"
//
// static void			draw_col(mglimg *scr, int column, int height, t_ray *ray)
// {
// 	const int		offset = ((int)scr->y - height) / 2;
// 	size_t			px;
// 	unsigned char	*pxs;
// 	unsigned int	y;
// 	int				tx, ty;
// 	float			uva, uvb;
// 	int				yt;
//
// 	if ((ray->bloc) && (ray->bloc->tex))
// 		tx = (int)((((ray->end.x  + ray->end.y) * 0.5f)
// 		- (float)(int)((ray->end.x + ray->end.y) * 0.5f)) * ray->bloc->tex->x);
// 	uva = 1.0 / (height + 1);
// 	uvb = 0.0;
// 	pxs = scr->pixels;
// 	yt = 0;
// 	y = 0;
// 	if (offset > 0)
// 		y = (unsigned int)offset;
// 	else
// 	{
// 		uvb = -offset * uva;
// 		height = (int)scr->y;
// 	}
// 	while (yt < (int)y)
// 		((unsigned int *)pxs)[column + yt++ * scr->x] = 0xff;
// 	yt = scr->y - yt;
// 	while (height--)
// 	{
// 		px = column + y * scr->x;
// 		if ((ray->bloc) && (ray->bloc->tex))
// 		{
// 			ty = (int)roundf(uvb * ray->bloc->tex->y) % ray->bloc->tex->y;
// 			((unsigned int *)pxs)[px] = ((unsigned int *)(
// 				ray->bloc->tex->pixels))[tx + (ty * ray->bloc->tex->x)];
// 			uvb += uva;
// 		}
// 		else if (ray->bloc)
// 		{
// 			pxs[px * 4] = ray->bloc->color.r;
// 			pxs[px * 4 + 1] = ray->bloc->color.g;
// 			pxs[px * 4 + 2] = ray->bloc->color.b;
// 			pxs[px * 4 + 3] = 255;
// 		}
// 		y++;
// 		yt--;
// 	}
// 	while (yt-- > 0)
// 		((unsigned int *)pxs)[column + y++ * scr->x] = 0xff;
// }

static void			*render_thread(void *arg)
{
	t_w3dthr		*ctx;
	int				x;
	float			dist;
	t_ray			*ray;

	ctx = (t_w3dthr *)arg;
	x = ctx->x;
	while (x > 0)
	{
		ctx->x = x;
		ray = &(ctx->w3d->render.rays[x]);
		dist = ray->distance;
		ctx->xfix = dist;
		ray->distance = -1.0f;
		dist *= w3d_raycast(ctx->lay->level.lvl_data, ray);
		ray->distance = dist;
		// if (dist > 0.0f)
		// 	draw_col(ctx->w3d->screen, x,
		// 		round(((2.0 * ctx->w3d->screen->y) / dist)), ray);
		// else
		// 	draw_col(ctx->w3d->screen, x, 0, ray);
		w3d_drawcol(&(ctx->lay->level), ctx, ray);
		x -= W3D_THREADNUM;
	}
	pthread_exit(NULL);
}

int					w3d_start_renderthreads(t_w3dl *lay, t_w3d *w3d)
{
	pthread_t		rdrth[W3D_THREADNUM];
	t_w3dthr		rdrtharg[W3D_THREADNUM];
	int				i;
	int				x;

	x = w3d->screen->x;
	i = W3D_THREADNUM;
	while (i--)
	{
		rdrtharg[i] = (t_w3dthr){ .x = --x, .xfix = 0.0f,
			.w3d = w3d, .lay = lay};
		pthread_create(&(rdrth[i]), NULL, &render_thread, &(rdrtharg[i]));
	}
	i = W3D_THREADNUM;
	while (i--)
		pthread_join(rdrth[i], NULL);
	return (0);
}
