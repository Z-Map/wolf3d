/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:50:44 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/06 17:30:13 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "wolf3d.h"

t_w3dl		w3d_parse_lvl(t_w3d *w3d, const char *path, t_w3dl layer)
{
	int		fd;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (layer);
	(void)w3d;
	close(fd);
	return (layer);
}
