/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:43:06 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/16 15:47:23 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			w3dp_newmap(t_pdata *dat)
{

}

int			w3dp_mapline(t_pdata *dat)
{
	char	*c;
	int		i;
	int		num;
	int		len;
	size_t	lsize;

	c = ft_strpskp(dat->c, FT_WHITESPACE);
	while (*c)
	{
		i = -1;
		len = 0;
		if ((ft_sscanf(c, "%i%n", &i, &len) <= 0) &&
			((c = ft_strpskp(c, FT_WHITESPACE)) != ','))
			i = (int)(*(c++));
		c += len;
		len = 0;
		num = 0;
		if (ft_sscanf(c, "*%u%n", &num, &len) > 0)
			
		c = ft_strchrnul(c, ',');
	}
}
