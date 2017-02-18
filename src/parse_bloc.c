/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:54:15 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/18 21:17:56 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			w3dp_bloc_col(const char *name, const char *val, void *arg)
{
	t_w3dbox		*bloc;

	bloc = (t_w3dbox *)arg;
	(void)name;
	bloc->color = w3d_parsecolor(&val);
	return (1);
}

static int	bloc_type_parse(const char *val, t_w3dbox *bloc)
{
	int		ret;

	if (!ft_strncmp(val, "wall", 4) && (ret = 4))
		bloc->flags |= W3D_BLOC_WALL;
	if (!ft_strncmp(val, "physic", 6) && (ret =6))
		bloc->flags |= W3D_BLOC_COLLIDER;
	if (!ft_strncmp(val, "actor", 5) && (ret = 5))
		bloc->flags |= W3D_BLOC_ACTIVATOR;
	if (!ft_strncmp(val, "player", 6) && (ret = 6))
		bloc->flags |= W3D_BLOC_PLAYER;
	return (ret);
}

int			w3dp_bloc_type(const char *name, const char *val, void *arg)
{
	t_w3dbox		*bloc;
	bloc = (t_w3dbox *)arg;

	(void)name;
	while (*val)
	{
		val += bloc_type_parse(val, bloc);
		if (*val != '|')
			break;
		while (*val == '|')
			val++;
	}
	return (1);
}

int			w3dp_bloc_layer(const char *name, const char *val, void *arg)
{
	int		ret;
	t_w3dbox		*bloc;

	bloc = (t_w3dbox *)arg;
	(void)name;
	bloc->layer = 0;
	while (ft_isdigit(*val))
	{
		if ((ret = (int)ft_buftoui(&val, 3, g_cmapup[8])) <= 64 && ret)
			bloc->layer |= 1 << (ret - 1);
		if (*val != '|')
			break;
		while (*val == '|')
			val++;
	}
	if (!bloc->layer)
		bloc->layer = 1;
	return (1);
}

int			w3dp_bloc_tex(const char *name, const char *val, void *arg)
{
	static t_w3d	*w3d = NULL;
	char			*path;
	char			*c;
	t_w3dbox		*bloc;

	if (!name || !val)
	{
		w3d = (t_w3d *)arg;
		return (1);
	}
	bloc = (t_w3dbox *)arg;
	path = (char *)val;
	if (*path == '"')
		path++;
	c = ft_strchrnul(path, (*val == '"') ? '"' : ' ');
	*c = '\0';
	if (*name == 'w')
		ft_printf("Try to load %s at %s %s\n", name, path,
		((bloc->wtex = w3d_loadtex(w3d, path))) ? "ok" : "fail");
	else if (*name == 'g')
		ft_printf("Try to load %s at %s %s\n", name, path,
		((bloc->gtex = w3d_loadtex(w3d, path))) ? "ok" : "fail");
	else if (*name == 'r')
		ft_printf("Try to load %s at %s %s\n", name, path,
		((bloc->rtex = w3d_loadtex(w3d, path))) ? "ok" : "fail");
	*c = (*val == '"') ? '"' : ' ';
	return (1);
}
