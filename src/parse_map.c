/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:43:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/18 23:11:19 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		parse_value(char **c, int *num)
{
	int			i;
	int			len;

	ft_printf("Start value parsing : %.5s\n", *c);
	i = -1;
	len = 0;
	if ((ft_sscanf(*c, "%i%n", &i, &len) <= 0) &&
		(*(*c = ft_strpskp(*c, FT_WHITESPACE)) != ','))
		i = (int)(*((*c)++));
	*c += len;
	len = 0;
	*num = 0;
	ft_printf("caca %s\n", *c);
	if ((ft_sscanf(*c, "*%u%n", num, &len) > 0) && (*num > 0))
		*c += len;
	else
		*num = 1;
	return (i);
}

static int		add_value(int id, int num, t_pdata *dat)
{
	t_w3dmb		bloc;

	id = w3d_getblocfromid((t_w3dmap *)(dat->data[1]), id);
	bloc = (t_w3dmb){.id = id, .flags = 0, .sub_data = NULL};
	while (num-- && ft_blststore(dat->blist[1], &bloc))
		(dat->len[1])++;
	return ((num > 0) ? 1 : 0);
}

int				w3dp_newmap(t_w3d *w3d, t_pdata *dat, const char *line)
{
	char		cfg[256];
	int			ret;

	ft_printf("Create new map \n");
	if ((dat->data[1] && !w3dp_rendermap(dat)) ||
		!(dat->blist[1] = ft_blstnew(sizeof(t_w3dmb), 64)) ||
		!(dat->blist[2] = ft_blstnew(sizeof(size_t), 32)) ||
		!(dat->data[1] = ft_blststore(dat->blist[0], dat->data[0])))
		return (0);
	ft_printf("new map created\n");
	ret = 0;
	if (line && (ft_sscanf(line, "[%*s %255s]", cfg) >= 1))
		ret = w3d_parse_cfg(w3d, cfg, dat->data[1]);
	if (!ret && (dat->ret[15]))
		((t_w3dmap *)(dat->data[1]))->flags = W3D_MAP_STATIC;
	dat->len[2] = 0;
	dat->len[3] = 0;
	return (1);
}

int				w3dp_mapline(t_w3d *w3d, t_pdata *dat)
{
	char		*c;
	int			num;
	int			id;

	c = ft_strpskp(dat->c, FT_WHITESPACE);
	dat->len[1] = 0;
	if (!c || !(*c))
		return (1);
	if ((!dat->data[1]) && (!w3dp_newmap(w3d, dat, NULL)))
		return (0);
	ft_printf("Start line parsing %p %p\n", dat->blist[1], dat->blist[2]);
	while (*c)
	{
		ft_printf("Glubz !! %s\n", c);
		id = parse_value(&c, &num);
		ft_printf("Lolz !!\n");
		if ((num = add_value(id, num, dat)))
			break ;
		c = ft_strchrnul(c, ',');
		c += (*c) ? 1 : 0;
	}
	if (num && !(dat->len[1]))
		return (0);
	ft_printf("Line success\n");
	(dat->len[2])++;
	if (dat->len[1] > dat->len[3])
		dat->len[3] = dat->len[1];
	if (!ft_blststore(dat->blist[2], dat->len + 1) || (num))
		return (0);
	return (1);
}
