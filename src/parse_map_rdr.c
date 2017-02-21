/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_rdr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:19:04 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/21 22:22:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

static void		linecpy(t_w3dmap *map, t_blit *it_line, size_t len, size_t ln)
{
	t_w3dmb		mbd;
	size_t		i;
	size_t		lid;

	mbd = (t_w3dmb){ .id = w3d_getblocfromid(map, -1), .flags = 0,
		.sub_data = NULL};
	lid = map->size.y;
	i = 0;
	map->grid[lid] = (t_w3dmb *)((size_t)(map->grid) + (ln * sizeof(void *))
		+ (map->size.x * lid * sizeof(t_w3dmb)));
	while (i < len)
		map->grid[lid][i++] = *((t_w3dmb *)ft_blstiter(it_line));
	while (i < map->size.x)
		map->grid[lid][i++] = mbd;
	if (lid < ln)
		map->size.y++;
}

int				w3dp_rendermap(t_pdata *dat)
{
	t_blit		it_line;
	t_blit		it_len;
	t_w3dmap	*map;
	size_t		*ls;

	map = dat->data[1];
	if (map && dat->len[2] && dat->blist[1] && dat->blist[2] &&
		(map->grid = malloc((dat->len[2] * dat->len[3] * sizeof(t_w3dmb)) +
			(dat->len[2] * sizeof(void *)))))
	{
		it_line = (t_blit){dat->blist[1], 0};
		it_len = (t_blit){dat->blist[2], 0};
		map->size = (t_v2ui){(t_ui)dat->len[3], 0};
		while ((ls = ft_blstiter(&it_len)))
			linecpy(map, &it_line, *ls, dat->len[2]);
		if (!dat->ret[15] && (map->blocs == ((t_w3dmap *)dat->data[0])->blocs))
			dat->ret[15] = 1;
	}
	if (dat->blist[1])
		ft_blstfree(&(dat->blist[1]));
	if (dat->blist[2])
		ft_blstfree(&(dat->blist[2]));
	dat->len[2] = 0;
	dat->len[3] = 0;
	return ((map && map->grid) ? 1 : 0);
}
