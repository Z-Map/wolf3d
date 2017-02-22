/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 03:13:40 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/25 14:37:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "mathex/vector.h"

typedef	struct		s_int_matrix_2d
{
	t_v2i			x;
	t_v2i			y;
}					t_mat2i;

typedef	struct		s_int_matrix_3d
{
	t_v3i			x;
	t_v3i			y;
	t_v3i			z;
}					t_mat3i;

typedef	struct		s_int_matrix_4d
{
	t_v4i			x;
	t_v4i			y;
	t_v4i			z;
	t_v4i			w;
}					t_mat4i;

typedef	struct		s_uint_matrix_2d
{
	t_v2ui			x;
	t_v2ui			y;
}					t_mat2ui;

typedef	struct		s_uint_matrix_3d
{
	t_v3ui			x;
	t_v3ui			y;
	t_v3ui			z;
}					t_mat3ui;

typedef	struct		s_uint_matrix_4d
{
	t_v4ui			x;
	t_v4ui			y;
	t_v4ui			z;
	t_v4ui			w;
}					t_mat4ui;

typedef	struct		s_float_matrix_2d
{
	t_v2f			x;
	t_v2f			y;
}					t_mat2f;

typedef	struct		s_float_matrix_3d
{
	t_v3f			x;
	t_v3f			y;
	t_v3f			z;
}					t_mat3f;

typedef	struct		s_float_matrix_4d
{
	t_v4f			x;
	t_v4f			y;
	t_v4f			z;
	t_v4f			w;
}					t_mat4f;

typedef	struct		s_double_matrix_2d
{
	t_v2d			x;
	t_v2d			y;
}					t_mat2d;

typedef	struct		s_double_matrix_3d
{
	t_v3d			x;
	t_v3d			y;
	t_v3d			z;
}					t_mat3d;

typedef	struct		s_double_matrix_4d
{
	t_v4d			x;
	t_v4d			y;
	t_v4d			z;
	t_v4d			w;
}					t_mat4d;

typedef	struct		s_float_matrix_transform
{
	t_v3f			x;
	t_v3f			y;
	t_v3f			z;
	t_v3f			offset;
	t_v4f			w;
}					t_mattf;

typedef	struct		s_double_matrix_transform
{
	t_v3d			x;
	t_v3d			y;
	t_v3d			z;
	t_v3d			offset;
	t_v4d			w;
}					t_mattd;

/*
**	Single precision matrix function
*/

t_mattf				*pmattf_trans(t_mattf *mat, t_v3f mov);
t_mattf				mattf_trans(t_mattf mat, t_v3f mov);
t_mattf				nmattf_trans(t_v3f mov);

t_mattf				*pmattf_scale(t_mattf *mat, float size);
t_mattf				mattf_scale(t_mattf mat, float size);
t_mattf				nmattf_scale(float size);
t_mattf				*pmattf_scalv(t_mattf *mat, t_v3f sizev);
t_mattf				mattf_scalv(t_mattf mat, t_v3f sizev);
t_mattf				nmattf_scalv(t_v3f sizev);

t_mattf				*pmattf_rotx(t_mattf *mat, float rad);
t_mattf				mattf_rotx(t_mattf mat, float rad);
t_mattf				nmattf_rotx(float rad);
t_mattf				*pmattf_roty(t_mattf *mat, float rad);
t_mattf				mattf_roty(t_mattf mat, float rad);
t_mattf				nmattf_roty(float rad);
t_mattf				*pmattf_rotz(t_mattf *mat, float rad);
t_mattf				mattf_rotz(t_mattf mat, float rad);
t_mattf				nmattf_rotz(float rad);

t_mattf				*pmattf_rot(t_mattf *mat, t_v3f vrad);
t_mattf				mattf_rot(t_mattf mat, t_v3f vrad);
t_mattf				nmattf_rot(t_v3f vrad);

t_mattf				*ptransformf(t_mattf *mat, t_v3f m, t_v3f r, t_v3f s);
t_mattf				transformf(t_mattf mat, t_v3f m, t_v3f r, t_v3f s);
t_mattf				ntransformf(t_v3f mov, t_v3f rot, t_v3f sca);

t_v3f				*pmattf_apply(t_v3f *v, const t_mattf *mat);
t_v3f				mattf_apply(t_v3f v, t_mattf mat);
t_v3f				*pmattf_project(t_v3f *v, const t_mattf *mat);

t_mattf				*pmattf_multiply(t_mattf *dest, const t_mattf *mat);
t_mattf				mattf_multiply(t_mattf mat1, t_mattf mat2);
t_mattf				*pmattf_invert(t_mattf *mat);
t_mattf				mattf_invert(const t_mattf *mat);

t_mattf				mattf_identity(void);
t_mattf				mattf_perspective(float fov, float ratio, t_v2f clip);
t_mattf				mattf_ortho(int w, int h, float zoom, float limit);
t_mattf				mattf_iso(void);

t_mat4f				mattf_togl(const t_mattf m);

/*
**	Double precision matrix function
*/

t_mattd				*pmattd_trans(t_mattd *mat, t_v3d mov);
t_mattd				mattd_trans(t_mattd mat, t_v3d mov);
t_mattd				nmattd_trans(t_v3d mov);

t_mattd				*pmattd_scale(t_mattd *mat, double size);
t_mattd				mattd_scale(t_mattd mat, double size);
t_mattd				nmattd_scale(double size);
t_mattd				*pmattd_scalv(t_mattd *mat, t_v3d sizev);
t_mattd				mattd_scalv(t_mattd mat, t_v3d sizev);
t_mattd				nmattd_scalv(t_v3d sizev);

t_mattd				*pmattd_rotx(t_mattd *mat, double rad);
t_mattd				mattd_rotx(t_mattd mat, double rad);
t_mattd				nmattd_rotx(double rad);
t_mattd				*pmattd_roty(t_mattd *mat, double rad);
t_mattd				mattd_roty(t_mattd mat, double rad);
t_mattd				nmattd_roty(double rad);
t_mattd				*pmattd_rotz(t_mattd *mat, double rad);
t_mattd				mattd_rotz(t_mattd mat, double rad);
t_mattd				nmattd_rotz(double rad);

t_mattd				*pmattd_rot(t_mattd *mat, t_v3d vrad);
t_mattd				mattd_rot(t_mattd mat, t_v3d vrad);
t_mattd				nmattd_rot(t_v3d vrad);

t_mattd				*ptransformd(t_mattd *mat, t_v3d m, t_v3d r, t_v3d s);
t_mattd				transformd(t_mattd mat, t_v3d m, t_v3d r, t_v3d s);
t_mattd				ntransformd(t_v3d mov, t_v3d rot, t_v3d sca);

t_v3d				*pmattd_apply(t_v3d *v, const t_mattd *mat);
t_v3d				mattd_apply(t_v3d v, t_mattd mat);

t_mattd				*pmattd_multiply(t_mattd *dest, const t_mattd *mat);
t_mattd				mattd_multiply(t_mattd mat1, t_mattd mat2);
t_mattd				*pmattd_invert(t_mattd *mat);
t_mattd				mattd_invert(const t_mattd *mat);

t_mattd				mattd_identity(void);
t_mattd				mattd_perspective(double fov, double ratio, t_v2d clip);
t_mattd				mattd_ortho(int w, int h, double zoom, double limit);
t_mattd				mattd_iso(void);

t_mat4d				mattd_togl(const t_mattd m);

#endif
