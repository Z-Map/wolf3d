/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:20 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/07 01:00:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define FT_DIGIT "0123456789ABCDEF"
# define FT_DIGIT_L "0123456789abcdef"
# define FT_DECIMAL_DIGIT "0123456789"
# define FT_DECIMAL_C "+-0123456789"
# define FT_OCTAL_C "01234567"
# define FT_HEXA_C "+-0123456789ABCDEF"
# define FT_HEXA_C_L "+-0123456789abcdef"

# define FT_WHITESPACE " \t\n\r\v\f"

# define FT_MX_FLOATLEN 310

typedef unsigned int	t_idx;
typedef unsigned char	t_uc;
typedef unsigned short	t_us;
typedef unsigned int	t_ui;
typedef unsigned long	t_ul;
typedef unsigned long	t_np;

typedef const struct	s_char_map
{
	t_ui				base;
	int					padding;
	const char			*cmap;
}						t_cmap;

static const char		g_digitupmap[] = FT_DIGIT;
static const char		g_digitlowmap[] = FT_DIGIT_L;
static t_cmap		g_cmapup[] = {
	(t_cmap){2, 0, g_digitupmap},
	(t_cmap){3, 0, g_digitupmap},
	(t_cmap){4, 0, g_digitupmap},
	(t_cmap){5, 0, g_digitupmap},
	(t_cmap){6, 0, g_digitupmap},
	(t_cmap){7, 0, g_digitupmap},
	(t_cmap){8, 0, g_digitupmap},
	(t_cmap){9, 0, g_digitupmap},
	(t_cmap){10, 0, g_digitupmap},
	(t_cmap){11, 0, g_digitupmap},
	(t_cmap){12, 0, g_digitupmap},
	(t_cmap){13, 0, g_digitupmap},
	(t_cmap){14, 0, g_digitupmap},
	(t_cmap){15, 0, g_digitupmap},
	(t_cmap){16, 0, g_digitupmap},
};
static t_cmap		g_cmaplow[] = {
	(t_cmap){2, 0, g_digitlowmap},
	(t_cmap){3, 0, g_digitlowmap},
	(t_cmap){4, 0, g_digitlowmap},
	(t_cmap){5, 0, g_digitlowmap},
	(t_cmap){6, 0, g_digitlowmap},
	(t_cmap){7, 0, g_digitlowmap},
	(t_cmap){8, 0, g_digitlowmap},
	(t_cmap){9, 0, g_digitlowmap},
	(t_cmap){10, 0, g_digitlowmap},
	(t_cmap){11, 0, g_digitlowmap},
	(t_cmap){12, 0, g_digitlowmap},
	(t_cmap){13, 0, g_digitlowmap},
	(t_cmap){14, 0, g_digitlowmap},
	(t_cmap){15, 0, g_digitlowmap},
	(t_cmap){16, 0, g_digitlowmap},
};
#endif
