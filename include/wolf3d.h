/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:54:16 by qloubier          #+#    #+#             */
/*   Updated: 2017/01/27 20:36:23 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define BUFF_SIZE 0x1000
# include "libft.h"
#include <math.h>
# include "mglw/mglw.h"
# include "mathex/vector.h"
# include "mathex/utils.h"

# define W3D_DEBUG		0x01
# define W3D_TEXTURE	0x02
# define W3D_MINIMAP	0x04

typedef struct s_octree_node		t_oxn;
typedef struct s_ray				t_ray;

typedef struct s_wolf3d_main		t_w3d;
typedef struct s_wolf3d_lvlrender	t_w3drdr;
typedef struct s_wolf3d_event		t_w3devt;
typedef struct s_wolf3d_player		t_w3dpc;
typedef struct s_wolf3d_box			t_w3dbox;
typedef struct s_wolf3d_map			t_w3dmap;

typedef union u_wolf3d_layers		t_w3dl;
typedef struct s_wolf3d_layer		t_w3dlay;
typedef struct s_wolf3d_basic_lvl	t_w3dlvl;
typedef struct s_wolf3d_gui_page	t_w3dgp;
typedef struct s_wolf3d_gui_element	t_w3dge;
typedef struct s_wolf3d_menu		t_w3dgui;

struct			s_octree_node
{
	t_uc		oxel;
	void		*tl;
	void		*tr;
	void		*bl;
	void		*br;
};

struct			s_ray
{
	t_v2f		start;
	t_v2f		dir;
	t_v2f		end;
	t_v2ui		grid_id;
	t_v3f		normale;
	float		distance;
	t_w3dbox	*bloc;
};

struct			s_wolf3d_event
{
	int			keycode;
	int			status;
	int			x;
	int			y;
};

# define W3D_PCK_FW		0x1
# define W3D_PCK_BW		0x2
# define W3D_PCK_LE		0x4
# define W3D_PCK_RI		0x8
# define W3D_PCK_LLE	0x10
# define W3D_PCK_LRI	0x20

struct			s_wolf3d_player
{
	t_ui		movkey;
	t_ui		flags;
	t_v3f		position;
	float		speed;
	t_v3f		movement;
	t_v3f		eyes;
	t_v2f		look;
};

# define W3D_BLOC_WALL		0x1
# define W3D_BLOC_COLLIDER	0x2
# define W3D_BLOC_TEX		0x4
# define W3D_BLOC_ACTIVATOR	0x8

struct			s_wolf3d_box
{
	t_ui		flags;
	int			userid;
	t_ul		layer;
	t_rgba		color;
	mglimg		*tex;
};

struct			s_wolf3d_map
{
	t_ui		bloclen;
	int			flags;
	t_v2ui		position;
	t_v2ui		size;
	t_v2f		height;
	t_w3dbox	*blocs;
	int			**grid;
};

# define W3D_LAYERTYPENUM 6

typedef enum	e_wolf3d_layer_type
{
	W3D_ERROR = 0,
	W3D_LVL,
	W3D_ADVLVL,
	W3D_MENU,
	W3D_IG_MENU,
	W3D_MAP,
	W3D_LOADING,
}				t_w3dlty;

# define W3DLAY_PRESSINPUT		0x1
# define W3DLAY_REPEATINPUT		0x2
# define W3DLAY_RELEASEINPUT	0x4

struct			s_wolf3d_layer
{
	t_w3dlty	type;
	int			flags;
	int			(*drawer)(t_w3dl *lay, t_w3d *w3d);
	int			(*evt_process)(t_w3dl *lay, t_w3d *w3d, t_w3devt evt);
};

struct			s_wolf3d_basic_lvl
{
	t_w3dlay	layer;
	t_v2ui		size;
	t_v2f		height;
	int			level_num;
	int			padding;
	t_w3dpc		player;
	t_w3dmap	*lvl_data;
	int			***octree;
};

typedef enum	e_wolf3d_gui_element_type
{
	W3DGUI_BUTTON = 0,
	W3DGUI_BOX,
	W3DGUI_TEXT,
	W3DGUI_TEXTINPUT
}				t_w3dguit;

# define W3DGUI_ALPHA		0x1
# define W3DGUI_ANIMATED	0x2

struct			s_wolf3d_gui_element
{
	t_w3dguit	type;
	int			flags;
	t_v2i		position;
	t_v2i		size;
	mglimg		*gdata;
	t_v4ui		sprite;
	t_v2ui		numbers;
};

# define W3DGUI_BUFFER		0x100
# define W3DGUI_INTERACTIVE	0x200

struct			s_wolf3d_gui_page
{
	int			length;
	int			flags;
	t_w3dge		*elements;
};

struct			s_wolf3d_menu
{
	t_w3dlay	layer;
	int			glen;
	int			plen;
	int			elen;
	mglimg		**gdata;
	t_w3dgp		**pages;
	t_w3dge		**elements;
};

union			u_wolf3d_layers
{
	t_w3dlay	layer;
	t_w3dlvl	level;
	t_w3dgui	gui;
};

struct			s_wolf3d_lvlrender
{
	int			flags;
	int			xlen;
	t_ray		*rays;
};

struct			s_wolf3d_main
{
	int			flags;
	int			padding;
	mglwin		*win;
	mglimg		*screen;
	t_w3drdr	render;
	int			laynum;
	int			active_laynum;
	t_w3dl		*layers;
	t_w3dl		*active_layers[32];
};

t_w3dl			w3d_parse(t_w3d *w3d, const char *path);

int				w3d_keypress(void *root, int k);
int				w3d_keyrepeate(void *root, int k);
int				w3d_keyrelease(void *root, int k);
void			w3d_layer_evt_process(t_w3d *w3d, t_w3devt evt, int flag);
void			w3d_set_evtflags(t_ui *flags, t_w3devt evt, t_ui flag);

void			w3d_layer_draw(t_w3d *w3d);
float			w3d_rayboxstep(const t_ray *ray, t_v2i *idx);
float			w3d_raycast(t_w3dmap *map, t_ray *ray);

int				w3d_error_mgr(t_w3d *w3d, int error, const char *message);

t_w3dl			w3d_create_lvl(t_w3d *w3d);
int				w3d_draw_lvl(t_w3dl *lay, t_w3d *w3d);
int				w3d_event_process_lvl(t_w3dl *lay, t_w3d *w3d, t_w3devt evt);
t_w3dl			w3d_parse_lvl(t_w3d *w3d, const char *path, t_w3dl layer);
t_w3dl			w3d_delete_lvl(void);
void			w3d_process_mov(t_w3dpc *player);

t_w3dbox		*w3dlvl_getbox(t_w3dmap *map, int x, int y);
t_w3dbox		*w3dlvl_getbox_ui(t_w3dmap *map, t_ui x, t_ui y);
t_w3dbox		*w3dlvl_getbox_vi(t_w3dmap *map, t_v2i idx);
t_w3dbox		*w3dlvl_getbox_vui(t_w3dmap *map, t_v2ui idx);

t_w3dl			w3d_create_gui(t_w3d *w3d);
int				w3d_draw_gui(t_w3dl *lay, t_w3d *w3d);
int				w3d_event_process_gui(t_w3dl *lay, t_w3d *w3d, t_w3devt evt);
t_w3dl			w3d_parse_gui(t_w3d *w3d, const char *path, t_w3dl layer);
t_w3dl			w3d_delete_gui(void);

#endif
