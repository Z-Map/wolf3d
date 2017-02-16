/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:45:56 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/15 21:43:30 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

static int		parse_init(t_w3d *w3d, t_pdata *dat)
{
	int			ret;

	if (((ret = (int)read(dat->fd, dat->buf, PBUFS)) < 5) ||
		(ft_strncmp(dat->buf, "#cfg", 4)))
		return (0);
	dat->buf[ret] = '\0';
	dat->buf[PBUFS] = '\0';
	dat->buf[PBUFS + 1] = (ret < PBUFS) ? 0 : 1;
	dat->c = dat->buf + 4;
	dat->cursor = 4;
	dat->blist[0] = ft_blstnew(sizeof(t_w3dbox), 32);
	dat->len[0] = 0;
	ret = 0;
	while (ret < (int)w3d->default_cfg.bloclen)
		ft_blststore(dat->blist[0], &(w3d->default_cfg.blocs[ret++]));
	return (1);
}


static int		parse_loop(t_pdata *dat)
{
	char		sav;
	int			ret;
	int			bid;
	t_w3dbox	*bloc;

	sav = '\n';
	bloc = NULL;
	while ((ret = w3dp_nextline(dat)) >= 0)
	{
		if (!dat->c[ret])
			sav = '\0';
		dat->c[ret] = '\0';
		if (dat->c[0] == '[')
		{
			if (!ft_sscanf(dat->c, "[%*s %i]", &bid))
			{
				ft_printf("call find_blocid on \"%s\"\n", dat->c);
				bid = w3dp_find_blocid(dat->blist[0]);
			}
			if (w3dp_getbloc(dat->blist[0], bid, &bloc) < 0)
				return (0);
		}
		else
			w3dp_blocprop(dat->c, bloc);
		dat->c[ret] = sav;
	}
	return (1);
}

int				w3d_parse_cfg(t_w3d *w3d, const char *path, t_w3dmap *map)
{
	t_pdata		dat;

	dat.buf[PBUFS] = '\0';
	dat.cursor = 0;
	if (path && (path[0] == '@') && ft_filename_ext(w3d->paths.cfg_file,
		path + 1, ".w3dc", w3d->paths.cfg_len))
		path = w3d->paths.cfg_dir;
	if (!path || (dat.fd = open(path, O_RDONLY)) < 0)
		return (0);
	if ((dat.error = parse_init(w3d, &dat)))
	{
		if ((dat.error = parse_loop(&dat)))
			map->blocs = ft_blsttotab(dat.blist[0], dat.len);
		map->bloclen = *dat.len;
		ft_blstfree(&(dat.blist[0]));
	}
	close(dat.fd);
	return (dat.error);
}
