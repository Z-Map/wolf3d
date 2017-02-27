/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfproto.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:21:10 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/27 19:24:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLFPROTO_H
# define WOLFPROTO_H

typedef struct s_octree_node		t_oxn;
typedef struct s_ray				t_ray;

typedef struct s_wolf3d_main		t_w3d;
typedef struct s_wolf3d_lvlrender	t_w3drdr;
typedef struct s_wolf3d_threadrdr	t_w3dthr;
typedef struct s_wolf3d_event		t_w3devt;
typedef struct s_wolf3d_player		t_w3dpc;
typedef struct s_wolf3d_box			t_w3dbox;
typedef struct s_wolf3d_map			t_w3dmap;
typedef struct s_wolf3d_mapbloc		t_w3dmb;
typedef struct s_texture			t_w3dtex;

typedef union u_wolf3d_layers		t_w3dl;
typedef struct s_wolf3d_layer		t_w3dlay;
typedef struct s_wolf3d_basic_lvl	t_w3dlvl;
typedef struct s_wolf3d_gui_page	t_w3dgp;
typedef struct s_wolf3d_gui_element	t_w3dge;
typedef struct s_wolf3d_menu		t_w3dgui;

#endif
