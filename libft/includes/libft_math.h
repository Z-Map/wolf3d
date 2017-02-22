/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 02:13:18 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/28 18:25:46 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MATH_H
# define LIBFT_MATH_H

# include "ft.h"

# define FT_SM_C	0x80u
# define FT_SM_S	0x8000u
# define FT_SM_I	0x80000000u
# define FT_SM_L	0x8000000000000000ul

# define FT_F_EXP	0x7f800000u
# define FT_F_MAN	0x007fffffu

# define FT_D_EXP	0x7ff0000000000000ul
# define FT_D_MAN	0x000ffffffffffffful

typedef union		u_float
{
	float			num;
	unsigned int	mem;
}					t_spf;

typedef union		u_double
{
	double			num;
	unsigned long	mem;
}					t_dpf;

int					ft_lastpow2digit(unsigned long num);
int					ft_lastfdigit(double d);
double				ft_fround(const double *d);
double				ft_ftrunc(const double *d);

/*
**	TO DO
*/

float				ft_fracf(register t_spf f);
double				ft_frac(register t_dpf d);

#endif
