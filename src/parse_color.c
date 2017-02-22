/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:02:18 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 13:06:58 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		get_hexchar(char c)
{
	if (c >= 0 && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (10 + (c - 'a'));
	else if (c >= 'A' && c <= 'F')
		return (10 + (c - 'A'));
	return (-1);
}

static t_rgba	parse_hexcol(const char **c)
{
	unsigned int	col;

	if (**c == '#')
		(*c)++;
	if (!ft_strncmp(*c, "0x", 2))
		*c += 2;
	col = 0xFF000000;
	while (**c && (get_hexchar(**c) >= 0))
		col = (col * 16) + get_hexchar(*((*c)++));
	return ((t_rgba){.r = (0xFF & col), .g = ((0xFF00 & col) >> 8),
		.b = ((0xFF0000 & col) >> 16), .a = ((0xFF000000 & col) >> 24)});
}

static int		get_val(const char **c)
{
	int			ret;

	ret = 255;
	if (!ft_strncmp(*c, "0.", 2))
		ret = round(ft_buftof(c, 20, g_cmapup[8]) * 255.0f);
	else if (!ft_strncmp(*c, "1.", 2))
		ft_buftof(c, 20, g_cmapup[8]);
	else
		ret = ft_buftoi(c, 20, g_cmapup[8]);
	if (**c == ',')
		(*c)++;
	*c = ft_strpskp(*c, FT_WHITESPACE);
	return (ret);
}

static t_rgba	parse_vcol(const char **buf)
{
	const char	*c;
	t_rgba		col;

	col = (t_rgba){.r=0, .g=0, .b=0, .a=255};
	if (!(c = ft_strnchr(*buf, (int)'(', 5)))
		return (col);
	c++;
	if (*((*buf)++) == 'r')
		col.r = (t_uc)get_val(&c);
	if (*((*buf)++) == 'g')
		col.g = (t_uc)get_val(&c);
	if (*((*buf)++) == 'b')
		col.b = (t_uc)get_val(&c);
	if (*((*buf)++) == 'a')
		col.a = (t_uc)get_val(&c);
	*buf = c;
	return (col);
}

t_rgba			w3d_parsecolor(const char **buf)
{
	if ((**buf == '#') || !ft_strncmp(*buf, "0x", 2))
		return (parse_hexcol(buf));
	else if (**buf == 'r')
		return (parse_vcol(buf));
	return ((t_rgba){.r=0, .g=0, .b=0, .a=255});
}
