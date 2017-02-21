/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_levelbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 06:09:27 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/21 17:31:48 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				w3dlvl_in(t_w3dmap *map, t_v2i idx)
{
	if ((idx.x < 0) || (idx.y < 0))
		return (0);
	else if ((idx.x < (int)map->size.x) && (idx.y < (int)map->size.y))
		return (1);
	return (0);
}

t_w3dbox		*w3dlvl_getbox(const t_w3dmap *map, int x, int y, int toggle)
{
	int			i;

	if ((x < 0) || (y < 0) ||
		(x >= (int)map->size.x) || (y >= (int)map->size.y))
		return (NULL);
	i = map->grid[y][x].id;
	if (toggle)
		map->grid[y][x].flags |= toggle;
	if (mxabs(i) >= (int)map->bloclen)
		return (NULL);
	if (i < 0)
		i += (int)map->bloclen;
	return (map->blocs + i);
}

t_w3dbox		*w3dlvl_getbox_ui(const t_w3dmap *map, t_ui x, t_ui y,
					int toggle)
{
	int			i;

	if ((x >= map->size.x) || (y >= map->size.y))
		return (NULL);
	i = map->grid[y][x].id;
	if (toggle)
		map->grid[y][x].flags |= toggle;
	if (mxabs(i) >= (int)map->bloclen)
		return (NULL);
	if (i < 0)
		i += (int)map->bloclen;
	return (map->blocs + i);
}

t_w3dbox		*w3dlvl_getbox_vi(const t_w3dmap *map, t_v2i idx, int toggle)
{
	int			i;

	if ((idx.x < 0) || (idx.y < 0) ||
		(idx.x >= (int)map->size.x) || (idx.y >= (int)map->size.y))
		return (NULL);
	i = map->grid[idx.y][idx.x].id;
	if (toggle)
		map->grid[idx.y][idx.x].flags |= toggle;
	if (mxabs(i) >= (int)map->bloclen)
		return (NULL);
	if (i < 0)
		i += (int)map->bloclen;
	return (map->blocs + i);
}

t_w3dbox		*w3dlvl_getbox_vui(const t_w3dmap *map, t_v2ui idx, int toggle)
{
	int			i;

	if ((idx.x >= map->size.x) || (idx.y >= map->size.y))
		return (NULL);
	i = map->grid[idx.y][idx.x].id;
	if (toggle)
		map->grid[idx.y][idx.x].flags |= toggle;
	if (mxabs(i) >= (int)map->bloclen)
		return (NULL);
	if (i < 0)
		i += (int)map->bloclen;
	return (map->blocs + i);
}
