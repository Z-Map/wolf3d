/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 10:32:33 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/22 15:28:22 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FORMAT_H
# define LIBFT_FORMAT_H
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <unistd.h>
# include "ft.h"
# include "libft_parse.h"
# include "libft_math.h"

/*
**	Declare public format function
*/

size_t					ft_snbrlen(short nbr);
size_t					ft_nbrlen(int nbr);
size_t					ft_lnbrlen(long nbr);
size_t					ft_jnbrlen(intmax_t nbr);
size_t					ft_jdigitlen(intmax_t i);
size_t					ft_nbrlen_base(register long i, char base);
size_t					ft_ujnbrlen(uintmax_t nbr, unsigned int base);
size_t					ft_ujdigitlen(uintmax_t i, unsigned int base);
size_t					ft_floatlen(double i, t_ui pre);

char					*ft_itoa(int n);
char					*ft_ujtobuf(uintmax_t n, char *b);
char					*ft_ujfillbuf(uintmax_t n, char *b, int *len);
char					*ft_ujfillbufbase(uintmax_t n, t_cmap cm, char *b,
							int *len);

char					*ft_dtoa(double n, t_ui prec);
char					*ft_ftoa(float n, t_ui prec);

/*
**	TO DO
*/

#endif
