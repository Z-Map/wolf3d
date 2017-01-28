/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_levelbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 06:09:27 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/23 06:30:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_w3dbox		*w3dlvl_getbox(t_w3dmap *map, int x, int y)
{
	int			i;

	if ((x < 0) || (y < 0) ||
		(x >= (int)map->size.x) || (y >= (int)map->size.y))
		return (NULL);
	i = map->grid[y][x];
	if (mxabs(i) >= (int)map->bloclen)
		return (NULL);
	if (i < 0)
		i += (int)map->bloclen;
	return (map->blocs + i);
}

t_w3dbox		*w3dlvl_getbox_ui(t_w3dmap *map, t_ui x, t_ui y)
{
	int			i;

	if ((x >= map->size.x) || (y >= map->size.y))
		return (NULL);
	i = map->grid[y][x];
	if (mxabs(i) >= (int)map->bloclen)
		return (NULL);
	if (i < 0)
		i += (int)map->bloclen;
	return (map->blocs + i);
}

t_w3dbox		*w3dlvl_getbox_vi(t_w3dmap *map, t_v2i idx)
{
	int			i;

	if ((idx.x < 0) || (idx.y < 0) ||
		(idx.x >= (int)map->size.x) || (idx.y >= (int)map->size.y))
		return (NULL);
	i = map->grid[idx.y][idx.x];
	if (mxabs(i) >= (int)map->bloclen)
		return (NULL);
	if (i < 0)
		i += (int)map->bloclen;
	return (map->blocs + i);
}

t_w3dbox		*w3dlvl_getbox_vui(t_w3dmap *map, t_v2ui idx)
{
	int			i;

	if ((idx.x >= map->size.x) || (idx.y >= map->size.y))
		return (NULL);
	i = map->grid[idx.y][idx.x];
	if (mxabs(i) >= (int)map->bloclen)
		return (NULL);
	if (i < 0)
		i += (int)map->bloclen;
	return (map->blocs + i);
}
