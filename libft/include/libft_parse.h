/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 19:48:04 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 15:28:16 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PARSE_H
# define LIBFT_PARSE_H

# include <inttypes.h>
# include <string.h>
# include <stdarg.h>
# include "ft.h"
# include "libft_string.h"
# include "libft_memory.h"
# include "libft_math.h"
# include "libft_list.h"

# define SF_TYPE_STR "idfxXusc%onN"
# define SF_FLAG_STR "*hljz"

enum					e_sf_flag
{
	SFF_NONE = 0,
	SFF_IGNORE = 1,
	SFF_SHORT_SHORT = 1 << 10,
	SFF_SHORT = 1 << 11,
	SFF_LONG = 1 << 12,
	SFF_LONG_LONG = 1 << 13,
	SFF_INTMAX = 1 << 14,
	SFF_SIZE_T = 1 << 15,
	SFF_CAPITAL = 1 << 16,
	SFF_MXW_SET = 1 << 18,
	SFF_END = (int)(1u << 30)
};

typedef struct			s_scanf_convert
{
	int					flag;
	int					maxwidth;
	void				*arg;
}						t_sfc;

typedef struct			s_scanf_buffer
{
	int					arglen;
	int					padding;
	const char			*src;
	const char			*c;
	const char			*ref;
	va_list				ap;
	t_sfc				arg;
}						t_sfb;

typedef struct			s_scanf_cftab
{
	const char			*(*flag)(const char *, t_sfb *);
	int					(*convert)(const char **, t_sfb*, t_sfc*);
}						t_sftab;

typedef struct			s_key_func
{
	const char			*key;
	int					(*func)(const char *, const char *, void *);
}						t_kf;

int						ft_parse_assign(const t_kf *a_table, const char *str,
							void *arg);

const char				*ft_parse_digit(const char *str, unsigned int *num);
const char				*ft_parse_cmap(const char *str, unsigned long *num,
							t_cmap cm, int len);
const char				*ft_parsej_cmap(const char *str, uintmax_t *num,
							t_cmap cm, int len);
const char				*ft_parsef(const char *str, double *num,
							t_cmap cm, int len);
const char				*ft_parseld(const char *str, long double *num,
							t_cmap cm, int len);
void					ft_bufskip(const char **str, int len, t_cmap cm);
void					ft_bufskipf(const char **str, int len, t_cmap cm);
int						ft_atoi(const char *str);
long					ft_atol(const char *str);
unsigned int			ft_atoui(const char *str);
unsigned long			ft_atoul(const char *str);
float					ft_atof(const char *str);
double					ft_atod(const char *str);
int						ft_buftoi(const char **str, int len, t_cmap cm);
long					ft_buftol(const char **str, int len, t_cmap cm);
intmax_t				ft_buftoj(const char **str, int len, t_cmap cm);
unsigned int			ft_buftoui(const char **str, int len, t_cmap cm);
unsigned long			ft_buftoul(const char **str, int len, t_cmap cm);
uintmax_t				ft_buftouj(const char **str, int len, t_cmap cm);
float					ft_buftof(const char **str, int len, t_cmap cm);
double					ft_buftod(const char **str, int len, t_cmap cm);
long double				ft_buftold(const char **str, int len, t_cmap cm);
const char				*ft_forf(const char *c, const char *s, size_t *len);

const char				*ft_sfflag_j(const char *c, t_sfb *b);
const char				*ft_sfflag_h(const char *c, t_sfb *b);
const char				*ft_sfflag_l(const char *c, t_sfb *b);
const char				*ft_sfflag_z(const char *c, t_sfb *b);
const char				*ft_sfflag_width(const char *c, t_sfb *b);
const char				*ft_sfflag_nc(const char *c, t_sfb *b);

int						ft_sfconv_d(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_i(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_u(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_f(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_s(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_c(const char **c, t_sfb *b, t_sfc *arg);
int						ft_sfconv_n(const char **c, t_sfb *b, t_sfc *arg);

int						ft_sfbuftoarg(t_sfb *b, t_sfc *arg, t_cmap cm);
int						ft_sfbuftouarg(t_sfb *b, t_sfc *arg, t_cmap cm);
int						ft_sfbuftofarg(t_sfb *b, t_sfc *arg, t_cmap cm);
int						ft_scanf_loop(const char *fstr, t_sfb *sfb);
const char				*ft_scanf_parse(const char *fstr, t_sfb *sfb);
const char				*ft_scanf_convert(const char *fstr, int i, t_sfb *sfb);

int						ft_sscanf(const char *str, const char *fstr, ...);

const static t_sftab	g_sf_flag_tab[] = {
	(t_sftab){&ft_sfflag_nc, &ft_sfconv_i},
	(t_sftab){&ft_sfflag_h, &ft_sfconv_d},
	(t_sftab){&ft_sfflag_l, &ft_sfconv_f},
	(t_sftab){&ft_sfflag_j, &ft_sfconv_u},
	(t_sftab){&ft_sfflag_z, &ft_sfconv_u},
	(t_sftab){NULL, &ft_sfconv_u},
	(t_sftab){NULL, &ft_sfconv_s},
	(t_sftab){NULL, &ft_sfconv_c},
	(t_sftab){NULL, &ft_sfconv_n},
	(t_sftab){NULL, &ft_sfconv_u},
	(t_sftab){NULL, &ft_sfconv_n},
	(t_sftab){NULL, &ft_sfconv_n},
	(t_sftab){NULL, NULL}
};

/*
** TO DO
*/

#endif
