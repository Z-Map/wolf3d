/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:45:56 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/03 16:12:07 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		w3d_parse_cfg(t_w3d *w3d, const char *path, t_w3dmap *map)
{
	t_pdata	dat;
	int		fd;

	dat.error = 1;
	if (ft_strchr(path,))
		ft_strncpy(w3d->paths.cfg_file, path, w3d->paths.cfg_len);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);

	close(fd);
	return (dat.error);
}
