/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:03:46 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/21 18:36:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

int				w3dp_find_blocid(t_blst *blocs)
{
	t_blit		iter;
	t_w3dbox	*bloc;
	int			bid;

	bid = 1;
	iter = (t_blit){blocs, 0};
	while ((bloc = ft_blstiter(&iter)))
	{
		if (bloc->userid == bid)
		{
			iter = (t_blit){blocs, 0};
			bid++;
		}
		if (bid > 1024)
			return (1);
	}
	return (bid);
}

int				w3dp_getbloc(t_blst *blocs, int id, t_w3dbox **bloc)
{
	t_blit		iter;
	t_w3dbox	nbloc;
	int			blid;

	blid = 0;
	iter = (t_blit){blocs, 0};
	while ((*bloc = ft_blstiter(&iter)))
	{
		if ((*bloc)->userid == id)
			break;
		++blid;
	}
	if (*bloc)
		return (blid);
	if (blid >= 1024)
		return (-1);
	nbloc = (t_w3dbox){ .flags = 0, .userid = id, .layer = 1, .color =
		(t_rgba){0, 0, 0, 255}, .rtex = NULL, .gtex = NULL, .wtex = NULL};
	ft_blststore(blocs, &nbloc);
	*bloc = ft_blstget(blocs, (size_t)blid);
	return (blid);
}

void			w3dp_blocprop(char *line, t_w3dbox *bloc)
{
	const t_kf	atbl[] = {{"color", &w3dp_bloc_col},
		{"layer", &w3dp_bloc_layer}, {"type",  &w3dp_bloc_type},
		{"rtex", &w3dp_bloc_tex}, {"gtex", &w3dp_bloc_tex},
		{"wtex", &w3dp_bloc_tex}, {NULL, NULL}};

	if (!bloc)
		return ;
	ft_parse_assign(atbl, line, bloc);
}

int				w3d_rmlayout(t_w3d *w3d, t_w3dmap *map)
{
	int			i;

	if (map->flags & W3D_MAP_STATIC)
	{
		map->bloclen = 0;
		map->blocs = NULL;
		return (0);
	}
	i = (int)map->bloclen;
	while (i--)
	{
		if (map->blocs[i].wtex)
			w3d_unloadtex(w3d,map->blocs[i].wtex);
		if (map->blocs[i].gtex)
			w3d_unloadtex(w3d, map->blocs[i].gtex);
		if (map->blocs[i].rtex)
			w3d_unloadtex(w3d, map->blocs[i].rtex);
	}
	map->bloclen = 0;
	free(map->blocs);
	map->blocs = NULL;
	return (0);
}

t_w3dbox		w3d_mkbox(int userid)
{
	return ((t_w3dbox){ .flags = 0, .userid = userid, .layer = 1,
		.color = (t_rgba){0, 0, 0, 255},
		.rtex = NULL, .gtex = NULL, .wtex = NULL});
}
