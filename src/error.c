/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:39:15 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 17:46:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"

int			w3d_error_mgr(t_w3d *w3d, int error, const char *message)
{
	(void)w3d;
	if (error)
		ft_printf("Error[%i] : %s\n", error, message);
	else
		ft_printf("Error : %s\n", message);
	return (error);
}

static char	*free_basedata(t_w3d *w3d)
{
	if (!w3d->cbuffer)
		return ("Failed to allocate global char buffer");
	free(w3d->cbuffer);
	if (!w3d->paths.data_dir)
		return ("Failed to allocate path buffer");
	free(w3d->paths.data_dir);
	if (!w3d->default_cfg.bloclen)
		return ("Failed to load default level layout");
	w3d_rmlayout(w3d, &(w3d->default_cfg));
	if (mglw_geterror())
		return ("Mmglw failed to init");
	return ("Uknown error");
}

static void	quit_mglw(t_w3d *w3d, const char **msg)
{
	if (!w3d->win)
		*msg = "Window opening failed";
	mglw_close();
}

static void	free_init_data(t_w3d *w3d, const char **msg)
{
	if (w3d_free_rdrdata(w3d))
		*msg = "Error int render data";
	if (!w3d_unloadtex(w3d, w3d->helpimg) || !w3d_unloadtex(w3d, w3d->openimg)
		|| !w3d_unloadtex(w3d, w3d->winimg) || !w3d_unloadtex(w3d, w3d->skyimg))
		*msg = "Failed to load texture";
	if (!w3d->layers || (w3d->layers->layer.type == W3D_ERROR))
		*msg = "Failed to load map";
	if (w3d->layers->layer.type != W3D_ERROR)
		w3dlvl_free(&(w3d->layers->level), w3d);
	if (w3d->layers)
		free(w3d->layers);
}

int			w3d_nicequit(t_w3d *w3d, int ret)
{
	const char	*msg;

	msg = free_basedata(w3d);
	if (ret > -120)
		free_init_data(w3d, &msg);
	if (ret > -121)
		quit_mglw(w3d, &msg);
	if (ret)
		ft_printf("Error : %s\n", msg);
	return (ret);
}
