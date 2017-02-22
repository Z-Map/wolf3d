# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 18:39:00 by qloubier          #+#    #+#              #
#    Updated: 2017/01/28 18:40:14 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPSYS=$(shell uname -s)
CC=clang
CFLAGS=-Wall -Werror -Wextra -Weverything
ifdef DEBUG
	CFLAGS+=-g
endif
ifdef OPTI
	CFLAGS+=-Ofast
endif
CHECK_MODE=off
NAME=libmathex.a
INCDIR=-I./include
ifeq ($(OPSYS),Linux)
	CFLAGS+=-Wno-strict-aliasing
endif
OBJ=utils/utils.o\
	utils/utilsf.o\
	utils/utilsfrac.o\
	utils/utilsu.o\
	binary/bitaprox.o\
	fixed/fromfixed.o\
	fixed/tofixed.o\
	fixed/toifixed.o\
	transform/matf_multiply.o\
	transform/matf_project.o\
	transform/matf_invert.o\
	transform/matf_rot.o\
	transform/matf_rotx.o\
	transform/matf_roty.o\
	transform/matf_rotz.o\
	transform/matf_scale.o\
	transform/matf_scalv.o\
	transform/matf_trans.o\
	transform/matf_utils.o\
	transform/matd_multiply.o\
	transform/matd_invert.o\
	transform/matd_rot.o\
	transform/matd_rotx.o\
	transform/matd_roty.o\
	transform/matd_rotz.o\
	transform/matd_scale.o\
	transform/matd_scalv.o\
	transform/matd_trans.o\
	transform/matd_utils.o\
	vector/normalize.o\
	vector/swapf.o\
	vector/swapd.o\
	vector/swapi.o\
	vector/tov4f.o\
	vector/tov4d.o\
	vector/tov4i.o\
	vector/vec2d/add2i.o\
	vector/vec2d/sub2i.o\
	vector/vec2d/tov2f.o\
	vector/vec2d/tov2d.o\
	vector/vec2d/tov2i.o\
	vector/vec3d/add3f.o\
	vector/vec3d/add3d.o\
	vector/vec3d/add3i.o\
	vector/vec3d/div3f.o\
	vector/vec3d/div3d.o\
	vector/vec3d/div3i.o\
	vector/vec3d/mul3f.o\
	vector/vec3d/mul3d.o\
	vector/vec3d/mul3i.o\
	vector/vec3d/sub3f.o\
	vector/vec3d/sub3d.o\
	vector/vec3d/sub3i.o\
	vector/vec3d/tov3f.o\
	vector/vec3d/tov3d.o\
	vector/vec3d/tov3i.o

all: $(NAME)

ifeq ($(CHECK_MODE),on)

$(NAME): $(OBJ)
	rm -rf $(NAME)

%.o: %.c
	rm -f $@

else

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)

endif

.PHONY: clean fclean re
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
