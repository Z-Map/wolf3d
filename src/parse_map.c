/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:43:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/18 16:16:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		parse_value(char **c, int *num)
{
	int			i;
	int			len;

	i = -1;
	len = 0;
	if ((ft_sscanf(*c, "%i%n", &i, &len) <= 0) &&
		((*c = ft_strpskp(*c, FT_WHITESPACE)) != ','))
		i = (int)(*((*c)++));
	*c += len;
	len = 0;
	*num = 0;
	if ((ft_sscanf(*c, "*%u%n", num, &len) > 0) && (*num > 0))
		*c += len;
	else
		*num = 1;
	return (i);
}

static int		add_value(int id, int num, t_pdata *dat)
{
	t_w3dmb		bloc;

	bloc = (t_w3dmb){.id = id, .flags = 0, .sub_data = NULL};
	while (num-- && ft_blststore(dat->blist[1], &bloc))
		(dat->len[1])++;
	return ((num > 0) ? 1 : 0);
}

int				w3dp_newmap(t_pdata *dat)
{
	if (!w3dp_rendermap(dat))
		return (0);
	dat->blist[1] = ft_blstnew(sizeof(t_w3dmb), 64);
	dat->blist[2] = ft_blstnew(sizeof(size_t), 32);
	
	return (1);
}

int				w3dp_mapline(t_pdata *dat)
{
	char		*c;
	int			num;

	c = ft_strpskp(dat->c, FT_WHITESPACE);
	dat->len[1] = 0;
	while (*c)
	{
		if (num = add_value(parse_value(&c, &num), num, dat));
			break ;
		c = ft_strchrnul(c, ',');
		c += (*c) ? 1 : 0;
	}
	if (num && !(dat->len[1]))
		return (0);
	(dat->len[2])++;
	if (dat->len[1] > dat->len[3])
		dat->len[3] = dat->len[1];
	if (!ft_blststore(dat->blist[2], dat->len + 1) || (num))
		return (0);
	return (1);
}
