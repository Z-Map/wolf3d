/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:14:54 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/21 18:19:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

int				w3dp_nextline(t_pdata *dat)
{
	size_t		l;
	int			ret;
	char		*le;

	if ((ret = ft_stridx(dat->buf + dat->cursor, (int)'\n')) < 0)
		return (-1);
	dat->cursor += ret + 1;
	dat->c = dat->buf + dat->cursor;
	le = ft_strchr(dat->c, (int)'\n');
	if (le)
		return ((int)(le - dat->c));
	l = ft_strlen(dat->c);
	if (!dat->buf[PBUFS + 1])
		return ((int)l);
	dat->c = ft_memmove(dat->buf, dat->c, l + 1) + l;
	l = PBUFS - l;
	if ((ret = read(dat->fd, dat->c, l)) < (int)l)
		dat->buf[PBUFS + 1] = 0;
	dat->c[ret] = '\0';
	le = ft_strchrnul(dat->c, (int)'\n');
	dat->c = dat->buf;
	dat->cursor = 0;
	return (le - dat->c);
}

void			w3dp_parsedat_init(t_pdata *dat)
{
	int			i;

	i = 15;
	while (i--)
	{
		dat->data[i] = NULL;
		dat->blist[i] = NULL;
		dat->ret[i] = 0;
		dat->len[i] = 0;
	}
	dat->error = 1;
	ft_bzero(dat->buf, PBUFS + 2);
	dat->buf[PBUFS] = '\0';
	dat->c = dat->buf;
	dat->cursor = 0;
	dat->fd = -1;
}
