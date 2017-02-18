/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:10:34 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/18 14:01:23 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		w3d_getblocfromid(t_w3dmap *map, int id)
{
	int			i;

	i = (int)map->bloclen - 1;
	while ((i >= 0) && (map->blocs[i].userid != id))
		--i;
	return (i);
}
