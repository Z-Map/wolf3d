/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:10:34 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/20 05:32:47 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"

int		w3d_getblocfromid(t_w3dmap *map, int id)
{
	int			i;

	// ft_printf("Call find bloc : %u, %i\n", map->bloclen, id);
	i = (int)map->bloclen - 1;
	while ((i >= 0) && (map->blocs[i].userid != id))
		--i;
	return (i);
}

int		w3d_allkeyfound(t_w3dmap *map)
{
	t_v2i		i;
	t_w3dbox	*bloc;

	i = (t_v2i){(int)map->size.x, (int)map->size.y};
	while (i.y-- > 0)
	{
		i.x = (int)map->size.x;
		while (i.x-- > 0)
		{
			bloc = w3dlvl_getbox_vi(map, i, 0);
			if ((bloc->flags & W3D_BLOC_KEY) &&
				!(map->grid[i.y][i.x].flags & W3D_BLOC_VISITED))
				return (0);
		}
	}
	return (1);
}

void			w3dlvl_free(t_w3dlvl *lvl, t_w3d *w3d)
{
	int			i;
	t_w3dmap	*map;

	i = lvl->level_num;
	while (i--)
	{
		map = lvl->lvl_data + i;
		if (map->grid)
			free(map->grid);
		if (map->bloclen)
			w3d_rmlayout(w3d, map);
	}
	free(lvl->lvl_data);
}
