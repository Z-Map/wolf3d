/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_unicode.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: map <marvin@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 01:35:21 by map               #+#    #+#             */
/*   Updated: 2016/10/06 04:21:12 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UNICODE_H
# define LIBFT_UNICODE_H

# include "ft.h"
# include "libft_memory.h"
# include "libft_string.h"
# include "libft_wstring.h"

# define U8M_MAX 0x1FFFFF

# define U8_4 0xF0808080
# define U8_3 0xE0808000
# define U8_2 0xC0800000
# define U8_1 0

# define U8M_4 0x1C0000
# define U8M_3 0x3F000
# define U8M_2 0xFC0
# define U8M_1 0x3F

# define U8L_4 0xFFFF
# define U8L_3 0x7FF
# define U8L_2 0x7F
# define U8L_1 0x0

int			ft_utf8wcsize(const wchar_t c);
int			ft_utf8csize(const wchar_t c);
size_t		ft_utf8wcslen(const wchar_t *s);
size_t		ft_utf8wcsalign(const wchar_t *s, size_t mxlen);
size_t		ft_utf8strlen(const wchar_t *s);

int			ft_utf8fromwc(const wchar_t c, t_ui *b);

#endif
