/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:45:56 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/03 16:27:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		w3d_parse_cfg(t_w3d *w3d, const char *path, t_w3dmap *map)
{
	t_pdata	dat;
	int		fd;

	dat.error = 1;
	if (path && (path[0] == '@'))
		path = ft_strncpy(w3d->paths.cfg_file, path + 1, w3d->paths.cfg_len);
	if (!path || (fd = open(path, O_RDONLY)) < 0)
		return (0);
	(void)map;
	close(fd);
	return (dat.error);
}
