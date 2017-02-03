/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:39:15 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/03 17:07:04 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			w3d_error_mgr(t_w3d *w3d, int error, const char *message)
{
	if (error)
		ft_printf("Error[%i] : %s", error, message);
	else
		ft_printf("Error : %s", message);
	return (error);
}

static char	*free_basedata(t_w3d *w3d, const char **msg)
{
	if (!w3d->cbuffer)
		return ("Failed to allocate global char buffer");
	free(w3d->cbuffer);
	if (!w3d->paths.data_dir)
		return ("Failed to allocate path buffer");
	free(w3d->paths.data_dir);
	if (!w3d->default_cfg.bloclen)
		return ("Failed to load default level layout");
	return ("Uknown error");
}

static void	quit_mglw(t_w3d *w3d, const char **msg)
{
	if (!w3d->win)
		*msg = "Window opening failed";
	mglw_close();
}

int			w3d_nicequit(t_w3d *w3d, int ret)
{
	const char	**msg;

	*msg = free_basedata(w3d, msg);
	if (ret > -121)
		quit_mglw(w3d, msg);
	if (ret > -120)
		free_init_data(w3d, msg);
	return (ret);
}
