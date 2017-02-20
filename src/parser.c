/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:14:54 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/19 04:02:54 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_w3dl			w3d_parse(t_w3d *w3d, const char *path)
{
	const size_t	len = ft_strlen(path);
	t_w3dl			ret;

	ret.layer.type = W3D_ERROR;
	if (!path)
		return (ret);
	if ((path[0] == '@') || ((len > 2) && ft_strequ(".w3dl", path + len - 5)))
		return ((t_w3dl)w3d_parse_lvl(w3d, path, ret));
	else if ((len > 2) && ft_strequ(".w3dg", path + len - 5))
		return (w3d_parse_gui(w3d, path, ret));
	else
		return (ret);
}
