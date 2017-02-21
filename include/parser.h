/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:26:17 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/21 18:15:36 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <sys/stat.h>
# include <fcntl.h>
# include "wolf3d.h"

# define PBUFS 2048

typedef struct		s_parsedata
{
	int				error;
	int				fd;
	size_t			cursor;
	char			*c;
	char			buf[PBUFS + 2];
	void			*data[16];
	t_blst			*blist[16];
	size_t			len[16];
	int				ret[16];
}					t_pdata;

void		w3dp_parsedat_init(t_pdata *dat);

int			w3dp_nextline(t_pdata *dat);
void		w3d_parse_bloc(t_pdata *dat, char *buf);
int			w3dp_find_blocid(t_blst *blocs);
int			w3dp_getbloc(t_blst *blocs, int id, t_w3dbox **bloc);
void		w3dp_blocprop(char *line, t_w3dbox *bloc);
t_w3dbox	w3d_mkbox(int userid);

int			w3dp_newmap(t_w3d *w3d, t_pdata *dat, const char *line);
int			w3dp_mapline(t_w3d *w3d, t_pdata *dat);
int			w3dp_rendermap(t_pdata *dat);

int			w3dp_bloc_col(const char *name, const char *val, void *bloc);
int			w3dp_bloc_type(const char *name, const char *val, void *bloc);
int			w3dp_bloc_layer(const char *name, const char *val, void *bloc);
int			w3dp_bloc_tex(const char *name, const char *val, void *arg);

t_rgba		w3d_parsecolor(const char **buf);

#endif
