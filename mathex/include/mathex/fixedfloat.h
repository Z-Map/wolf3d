/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixedfloat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 04:01:53 by qloubier          #+#    #+#             */
/*   Updated: 2016/02/21 03:45:24 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_H
# define FLOAT_H

# define FIF_SIZE sizeof(int) * 8
# ifndef FIF_PRECISION
#  define FIF_PRECISION 0
# endif

/*
**
** Declare Fixed Floating point types
**
*/

# define LOW_SIZE FIF_SIZE / 4
# define MID_SIZE FIF_SIZE / 2
# define HIGH_SIZE 3 * LOW_SIZE

# define NOR_SIZE FIF_SIZE - 2

typedef struct					s_fixed_low
{
	unsigned int				fract:LOW_SIZE;
	int							integ:HIGH_SIZE;
}								t_fixl;

typedef struct					s_fixed_medium
{
	unsigned int				fract:MID_SIZE;
	int							integ:MID_SIZE;
}								t_fixm;

typedef struct					s_fixed_high
{
	unsigned int				fract:HIGH_SIZE;
	int							integ:LOW_SIZE;
}								t_fixh;

typedef struct					s_fixed_nor
{
	unsigned int				fract:NOR_SIZE;
	int							integ:2;
}								t_fix_nor;

# if FIF_PRECISION < 0
typedef struct s_fixed_low		t_fix;
#  define FIF_INTSHIFT LOW_SIZE
# elif FIF_PRECISION == 0
typedef struct s_fixed_medium	t_fix;
#  define FIF_INTSHIFT MID_SIZE
# else
typedef struct s_fixed_high		t_fix;
#  define FIF_INTSHIFT HIGH_SIZE
# endif

# define FIF_ROUNDMASK 1 << (FIF_INTSHIFT - 1)
# define FIF_MIN (float)(1.0f / FIF_INTSHIFT)
# define FIF_FRACPOW 0xffffffff >> (FIF_SIZE - FIF_INTSHIFT)
# define FIF_INTMASK 0xffffffff ^ FIF_FRACPOW

int								toifix(t_fix fixed);
t_fix							tofix(int num);
t_fix							itofix(int num);
int								itoifix(int num);
int								fixtoi(const void *fixed);
t_fix							ftofix(float num);
int								ftoifix(float num);
float							fixtof(const void *fixed);
int								roundfix(const void *fixed);

#endif
