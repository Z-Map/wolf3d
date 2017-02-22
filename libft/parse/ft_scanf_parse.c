/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 05:19:52 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 15:31:20 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static void			init_sfarg(t_sfc *arg)
{
	arg->arg = NULL;
	arg->maxwidth = (int)(~FT_SM_I);
	arg->flag = SFF_NONE;
}

const char			*ft_scanf_parse(const char *fstr, t_sfb *sfb)
{
	const char		*c;
	int				i;
	int				ret;

	i = 0;
	c = fstr;
	init_sfarg(&(sfb->arg));
	while ((*c) && ((i = ft_stridx(SF_TYPE_STR, (int)(*c))) == -1))
	{
		if ((i = ft_stridx(SF_FLAG_STR, (int)(*c))) >= 0)
			c = g_sf_flag_tab[i].flag(c, sfb);
		else if (ft_isdigit((int)(*c)))
			c = ft_sfflag_width(c, sfb);
		else
			break ;
	}
	if ((!*c) || (i == -1))
		return (NULL);
	if (ft_isupper((int)(*c)))
		sfb->arg.flag |= SFF_CAPITAL;
	ret = g_sf_flag_tab[i].convert(&c, sfb, &(sfb->arg));
	if (ret < 0)
		return (NULL);
	sfb->arglen += ret;
	return (c);
}
