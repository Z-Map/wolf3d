/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:43:05 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/15 13:09:15 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"

int				w3d_init_rdrdata(t_w3d *w3d)
{
	w3d->render.rays = (t_ray *)malloc(sizeof(t_ray) * w3d->screen->x);
	w3d->render.wdist = (t_v2f *)malloc(sizeof(t_v2f) * w3d->screen->x);
	w3d->render.hdist = (float *)malloc(sizeof(float) * w3d->screen->y);
	w3d->render.ratio.x = (float)w3d->screen->y / (float)w3d->screen->x;
	w3d->render.ratio.y = (float)w3d->screen->x / (float)w3d->screen->y;
	w3d->render.fov = (t_v2f){0.8f * w3d->render.ratio.y, 1.047197551f};
	if (!w3d->render.rays || !w3d->render.wdist || !w3d->render.hdist)
		return (0);
	return(1);
}

void			w3d_update_rdrdata(t_w3drdr rdr, int w, int h)
{
	const t_v2f	dim = (t_v2f){cos(rdr.fov.x / 2.0f), cosf(rdr.fov.y / 2.0f)};
	float		val;
	float		step;

	val = -sin(rdr.fov.x / 2.0f);
	step = (val * -2.0f) / (float)w;
	while (w--)
	{
		rdr.wdist[w] = normalize2f((t_v2f){dim.x, val});
		val += step;
	}
	val = -sin(rdr.fov.y / 2.0f);
	step = (val * -2.0f) / (float)h;
	while (h--)
	{
		if (val == 0.0f)
			rdr.hdist[h] = (dim.y * 1.155f) / step * 0.5f;
		else
			rdr.hdist[h] = (dim.y * 1.155f) / val;
		val += step;
	}
}

int				w3d_free_rdrdata(t_w3d *w3d)
{
	int		ret;

	ret = 0;
	if (!w3d->render.rays)
		ret = 1;
	free(w3d->render.rays);
	w3d->render.rays = NULL;
	if (!w3d->render.wdist)
		ret = 1;
	free(w3d->render.wdist);
	w3d->render.wdist = NULL;
	if (!w3d->render.hdist)
		ret = 1;
	free(w3d->render.hdist);
	w3d->render.hdist = NULL;
	return (ret);
}
