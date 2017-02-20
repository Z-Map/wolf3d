/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:53:51 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/20 05:26:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"

static int		store_texture(t_w3d *w3d, t_w3dtex *ntex)
{
	t_w3dtex	*tex;

	tex = w3d->textures;
	if (!tex)
		w3d->textures = ntex;
	else
	{
		while (tex->next)
			tex = tex->next;
		tex->next = ntex;
	}
	return (1);
}

static t_w3dtex	*get_texfromlist(t_w3d *w3d, const char *path)
{
	t_w3dtex	*tex;

	tex = w3d->textures;
	while (tex && ft_strcmp(tex->path, path))
		tex = tex->next;
	if (tex)
		tex->uses += 1;
	return (tex);
}

mglimg			*w3d_loadtex(t_w3d *w3d, const char *path)
{
	t_w3dtex	tex;

	if (!path)
		return (NULL);
	if ((path[0] == '@') && ft_filename_ext(w3d->paths.tex_file,
		path + 1, NULL, w3d->paths.tex_len))
		path = w3d->paths.tex_dir;
	ft_printf("tex path : %s\n", path);
	if ((tex.next = get_texfromlist(w3d, path)))
		return (tex.next->img);
	if (!(tex.img = mglw_loadimage(path, 0, 4)))
		return (NULL);
	if (!(tex.next = malloc(sizeof(t_w3dtex) + ft_strlen(path) + 1)))
	{
		mglw_rmimg(tex.img);
		return (NULL);
	}
	*(tex.next) = (t_w3dtex){.flags = 0, .uses = 1, .path = (char *)tex.next
		+ sizeof(t_w3dtex), .img = tex.img, .next = NULL};
	ft_strcpy(tex.next->path, path);
	store_texture(w3d, tex.next);
	return (tex.img);
}

int				w3d_unloadtex(t_w3d *w3d, mglimg *img)
{
	t_w3dtex	*tex;
	t_w3dtex	*btex;

	if (!img)
		return (0);
	btex = (t_w3dtex *)w3d;
	while (btex->next && (btex->next->img != img))
		btex = btex->next;
	tex = btex->next;
	if (tex)
	{
		tex->uses -= 1;
		if (!tex->uses)
		{
			btex->next = tex->next;
			mglw_rmimg(tex->img);
			free(tex);
			return (1);
		}
	}
	return (0);
}
