/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:20:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/03/07 15:39:42 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "wolf3d.h"

static void			*render_thread(void *arg)
{
	t_w3dthr		*ctx;
	int				x;
	float			dist;
	t_ray			*ray;

	ctx = (t_w3dthr *)arg;
	x = ctx->x;
	while (x >= 0)
	{
		ctx->x = x;
		ray = &(ctx->w3d->render.rays[x]);
		dist = ctx->w3d->render.wdist[x].x;
		ctx->xfix = dist;
		dist *= w3d_raycast(
			&(ctx->lay->level.lvl_data[ctx->lay->level.active_lvl]), ray);
		ray->distance = dist;
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
