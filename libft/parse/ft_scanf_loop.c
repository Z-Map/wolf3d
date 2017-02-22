/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 22:13:30 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/23 01:24:28 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_parse.h"

static int			valid_str(const char *s, t_sfb *sfb, size_t *len)
{
	const char		*c;

	while (*len)
	{
		c = sfb->c + 1;
		if ((*s == ' ') && ((c = ft_strpskp(sfb->c, FT_WHITESPACE)) == sfb->c))
			return (0);
		else if (*s != *(sfb->c))
			return (0);
		sfb->c = c;
		++s;
		--(*len);
	}
	return (1);
}

int					ft_scanf_loop(const char *fstr, t_sfb *sfb)
{
	const char		*c;
	size_t			len;

	while ((fstr) && (c = ft_forf(fstr, "%", &len)))
	{
		if (!valid_str(fstr, sfb, &len))
			break ;
		if (sfb->arglen < 0)
			sfb->arglen = 0;
		fstr = ft_scanf_parse(c + 1, sfb);
	}
	return (0);
}
