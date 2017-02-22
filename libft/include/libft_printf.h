/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <map@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 05:51:14 by map               #+#    #+#             */
/*   Updated: 2017/02/16 16:54:35 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <unistd.h>
# include "ft.h"
# include "libft_list.h"
# include "libft_string.h"
# include "libft_wstring.h"
# include "libft_unicode.h"
# include "libft_parse.h"
# include "libft_format.h"
# include "libft_math.h"

# ifndef FT_PF_BUFSIZE
#  define FT_PF_BUFSIZE 8192 * 8
# endif
# define PF_BUFSIZE (FT_PF_BUFSIZE + 1 + (8 - ((FT_PF_BUFSIZE + 1) % 8)))

# define PF_TYPE_STR "sdiuxcbDXUp%SCoOfFn"
# define PF_FLAG_STR "#+0- .hljz*"

# define PF_UCHAR 0xFF
# define PF_UPFF_SHORT 0xFFFF

# define PF_COUCOU_LA_NORME ((arg->flag & PFF_CAPITAL) ? g_cmapup : g_cmaplow)

enum					e_pf_flag
{
	PFF_NONE = 0,
	PFF_ALTERNTE = 1,
	PFF_FORCE_SIGN = 1 << 1,
	PFF_ZERO_FILL = 1 << 2,
	PFF_LEFT_ALIGN = 1 << 3,
	PFF_SPACE = 1 << 4,
	PFF_SHORT_SHORT = 1 << 10,
	PFF_SHORT = 1 << 11,
	PFF_LONG = 1 << 12,
	PFF_LONG_LONG = 1 << 13,
	PFF_INTMAX = 1 << 14,
	PFF_SIZE_T = 1 << 15,
	PFF_CAPITAL = 1 << 16,
	PFF_PREC_SET = 1 << 17,
	PFF_MNW_SET = 1 << 18,
	PFF_PTR = 1 << 19,
	PFF_NEG = 1 << 20,
	PFF_PTRSET = PFF_LONG | PFF_ALTERNTE | PFF_PTR,
	PFF_END = (int)(1u << 30)
};

enum					e_pf_type
{
	PFT_NONE = 0,
	PFT_INT = 1,
	PFT_BIN = 2,
	PFT_OCT = 8,
	PFT_UINT = 10,
	PFT_HEXA = 16,
	PFT_CHAR = 11,
	PFT_PTR = 3,
	PFT_SPECHAR = 4,
	PFT_STR = 5,
	PFT_WSTR = 6,
	PFT_FLOAT = 7,
	PFT_N = 9
};

typedef struct			s_printf_convert
{
	enum e_pf_flag		flag;
	enum e_pf_type		type;
	t_ui				precision;
	t_ui				minwidth;
	int					b_len;
	int					padding;
	uintmax_t			arg;
	char				*tmpb;
}						t_pfc;

typedef struct			s_printf_buffer
{
	int					blen;
	int					fd;
	ssize_t				len;
	char				*c;
	va_list				ap;
	t_pfc				arg;
	char				buffer[PF_BUFSIZE];
	char				tmp[FT_MX_FLOATLEN + 2];
}						t_pfb;

typedef struct			s_printf_cftab
{
	const char			*(*flag)(const char *, t_pfb *);
	int					(*getarg)(int, va_list, t_pfc*);
	int					(*getlen)(t_pfc*);
	void				(*convert)(t_pfb*, t_pfc*, size_t);
}						t_pftab;

const char				*ft_pfflag_alt(const char *c, t_pfb *b);
const char				*ft_pfflag_zero(const char *c, t_pfb *b);
const char				*ft_pfflag_dot(const char *c, t_pfb *b);
const char				*ft_pfflag_l(const char *c, t_pfb *b);
const char				*ft_pfflag_h(const char *c, t_pfb *b);
const char				*ft_pfflag_j(const char *c, t_pfb *b);
const char				*ft_pfflag_z(const char *c, t_pfb *b);
const char				*ft_pfflag_width(const char *c, t_pfb *b);
const char				*ft_pfflag_more(const char *c, t_pfb *b);
const char				*ft_pfflag_less(const char *c, t_pfb *b);
const char				*ft_pfflag_space(const char *c, t_pfb *b);

int						ft_pfarg_nbr(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_unbr(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_oct(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_hex(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_char(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_str(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_wstr(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_float(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_ptr(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_spc(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_n(int cc, va_list ap, t_pfc *arg);
int						ft_pfarg_bin(int cc, va_list ap, t_pfc *arg);

int						ft_pflen_nbr(t_pfc *arg);
int						ft_pflen_unbr(t_pfc *arg);
int						ft_pflen_str(t_pfc *arg);
int						ft_pflen_char(t_pfc *arg);
int						ft_pflen_float(t_pfc *arg);
int						ft_pflen_n(t_pfc *arg);

void					ft_pfconv_nbr(t_pfb *b, t_pfc *arg, size_t len);
void					ft_pfconv_unbr(t_pfb *b, t_pfc *arg, size_t len);
void					ft_pfconv_str(t_pfb *b, t_pfc *arg, size_t len);
void					ft_pfconv_char(t_pfb *b, t_pfc *arg, size_t len);
void					ft_pfconv_float(t_pfb *b, t_pfc *arg, size_t len);
void					ft_pfconv_n(t_pfb *b, t_pfc *arg, size_t len);
int						ft_printf_bwrite(t_pfb *b, const char *c, size_t len);
int						ft_printf_bwritew(t_pfb *b, const wchar_t *c,
							size_t len);
int						ft_printf_bwritec(t_pfb *b, char c, size_t len);
int						ft_printf_bflush(t_pfb *b);

int						ft_printf_loop(const char *fstr, t_pfb *pfb);
const char				*ft_printf_parse(const char *fstr, t_pfb *pfb);
int						ft_printf_convert(int tid, t_pfc *arg, t_pfb *pfb);
int						ft_printf_bwrite(t_pfb *b, const char *c,
							const size_t len);
int						ft_printf_bwritew(t_pfb *b, const wchar_t *c,
							size_t len);
int						ft_printf_bwritec(t_pfb *b, char c, size_t len);
int						ft_printf_bflush(t_pfb *b);

int						ft_printf(const char *fstr, ...);
int						ft_dprintf(int fd, const char *fstr, ...);
int						ft_print_buff(const char *fstr, int len, t_list **args);

const static char		*g_pf_nullstr = "(null)";
const static char		*g_pf_floatstr = "-inf-nan";
const static t_pftab	g_pf_flag_tab[] = {
	(t_pftab){&ft_pfflag_alt, &ft_pfarg_str, &ft_pflen_str, &ft_pfconv_str},
	(t_pftab){&ft_pfflag_more, &ft_pfarg_nbr, &ft_pflen_nbr, &ft_pfconv_nbr},
	(t_pftab){&ft_pfflag_zero, &ft_pfarg_nbr, &ft_pflen_nbr, &ft_pfconv_nbr},
	(t_pftab){&ft_pfflag_less, &ft_pfarg_unbr, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){&ft_pfflag_space, &ft_pfarg_hex, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){&ft_pfflag_dot, &ft_pfarg_char, &ft_pflen_char, &ft_pfconv_char},
	(t_pftab){&ft_pfflag_h, &ft_pfarg_bin, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){&ft_pfflag_l, &ft_pfarg_nbr, &ft_pflen_nbr, &ft_pfconv_nbr},
	(t_pftab){&ft_pfflag_j, &ft_pfarg_hex, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){&ft_pfflag_z, &ft_pfarg_unbr, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){&ft_pfflag_width, &ft_pfarg_ptr, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){NULL, &ft_pfarg_spc, &ft_pflen_char, &ft_pfconv_char},
	(t_pftab){NULL, &ft_pfarg_wstr, &ft_pflen_str, &ft_pfconv_str},
	(t_pftab){NULL, &ft_pfarg_char, &ft_pflen_char, &ft_pfconv_char},
	(t_pftab){NULL, &ft_pfarg_oct, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){NULL, &ft_pfarg_oct, &ft_pflen_unbr, &ft_pfconv_unbr},
	(t_pftab){NULL, &ft_pfarg_float, &ft_pflen_float, &ft_pfconv_float},
	(t_pftab){NULL, &ft_pfarg_float, &ft_pflen_float, &ft_pfconv_float},
	(t_pftab){NULL, &ft_pfarg_n, &ft_pflen_n, &ft_pfconv_n}
};

#endif
