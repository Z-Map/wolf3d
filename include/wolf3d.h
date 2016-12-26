/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:54:16 by qloubier          #+#    #+#             */
/*   Updated: 2016/12/23 19:09:10 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mglw/mglw.h"
#include "vector.h"

# define W3D_DEBUG		0x01
# define W3D_TEXTURE	0x02

typedef struct s_octree_node	t_oxn;

typedef struct s_wolf3d_main	t_w3d;
typedef struct s_wolf3d_lvl		t_w3dlvl;

typedef enum	e_wolf3d_lvl_type
{
	W3D_LVL = 0,
	W3D_ADVLVL,
	W3D_MENU,
	W3D_IG_MENU,
	W3D_MAP,
	W3D_LOADING
}				t_w3d_lt;

struct			s_octree_node
{
	t_uc		oxel;
	void		*tl;
	void		*tr;
	void		*bl;
	void		*br;
};

struct			s_wolf3d_lvl
{
	t_w3d_lt	type;
	int			flags;
};

struct			s_wolf3d_basic_lvl
{
	t_w3dlvl	lvl;
	t_v2ui		size;
	t_v2f		height;
	int			**lvl_data;
	int			**octree;
};

struct			s_wolf3d_main
{
	int			flags;
	int			padding;
	mglwin		*win;
	mglimg		*screen;
};

#endif
