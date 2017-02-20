# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/23 00:32:16 by qloubier          #+#    #+#              #
#    Updated: 2017/02/20 04:59:26 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPSYS		= $(shell uname -s)
NAME		= wolf3d
PROJECTNAME	= wolf3d
LIBS		= ../libft/libft.a mathex/libmathex.a ../mglw/libmglw.a
LIBFLAGS	= -lm
INCDIR		= -Iinclude
CFLAGS		= -Wall -Wextra -Werror

ifndef CC
  CC=clang
endif

ifndef config
  config=release
endif
ifeq ($(config),debug)
  CFLAGS+=-O1 -g -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif
ifeq ($(config),release)
  CFLAGS+=-Ofast
endif

SILENT		= @
BUILDDIR	= build
SRCDIR		= src
SRCS		= main.c\
			draw.c\
			draw_level.c\
			draw_thread.c\
			draw_tools.c\
			render_data.c\
			events.c\
			event_level.c\
			raycast.c\
			menu.c\
			map.c\
			config.c\
			textures.c\
			error.c\
			player.c\
			parser.c\
			parse_menu.c\
			parse_bloc.c\
			parse_level.c\
			parse_map.c\
			parse_map_rdr.c\
			parse_config.c\
			parse_color.c\
			utils_levelbox.c\
			utils_raycast.c\
			utils_ray.c

OBJ			= $(subst /,~,$(SRCS:%.c=%.o))

LIBDIRS		= $(shell for lib in $(LIBS); do dirname "$$lib"; done)
INCDIR		+= $(LIBDIRS:%=-I%/include)#-Imglw/include -Imathex/include -Ilibft/include
LIBFLAGS	+= $(LIBDIRS:%=-L%) $(shell basename -as .a $(LIBS) | sed -e "s/lib/-l/g")
INTERN_SRCS	= $(SRCS:%=$(SRCDIR)/%)
INTERN_OBJ	= $(OBJ:%=$(BUILDDIR)/%)
INTERN_DEP	= $(INTERN_OBJ:%.o=%.d)
BOBJ_GUARD	= $(shell if [ -d $(BUILDDIR) ]; then printf "on"; else printf "off"; fi)
ALLOBJ		= $(INTERN_OBJ)
OSXLIBS		= -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

.PHONY: all clean fclean re $(TESTSRC) $(INTERN_DEP)

all: $(NAME)

$(LIBS):
	$(SILENT)$(MAKE) -C $(shell dirname $@)

$(BUILDDIR):
	$(SILENT)mkdir -p $(BUILDDIR)

$(NAME): $(BUILDDIR) $(LIBS) $(INTERN_OBJ)
ifeq ($(BOBJ_GUARD),off)
	$(SILENT)$(MAKE) -s $(NAME) BOBJ_GUARD=on
else
	@printf "\e[33mCompile $@\e[31m\e[80D"
ifeq ($(OPSYS),Linux)
	$(SILENT)$(CC) $(CFLAGS) $(INCDIR) -o $@ $(INTERN_OBJ) $(LIBFLAGS) -lGL $(shell pkg-config --static --libs mglw/mglw.pc)
else
	$(SILENT)$(CC) $(CFLAGS) $(INCDIR) -o $@ $(INTERN_OBJ) $(LIBFLAGS) $(OSXLIBS)
endif
	@printf "\e[m[\e[32mok\e[m] \e[35m$@\e[m compiled !\e(B\e[m\n"
endif

$(INTERN_OBJ):
ifeq ($(BOBJ_GUARD),on)
	@printf "\e[33mCompile $@\e[31m\e[80D"
	$(SILENT)$(CC) -MMD -MP $(CFLAGS) $(INCDIR) -o $@ -c $(subst ~,/,$(@:$(BUILDDIR)/%.o=$(SRCDIR)/%.c))
	@printf "\e[m[\e[32mok\e[m] \e[35m$@\e[m compiled !\e(B\e[m\n"
else
	@echo "$<"
endif

-include $(INTERN_DEP)

clean:
	@printf "\e[31mCleaning compile files ...\e(B\e[m\n"
	$(SILENT)rm -f $(INTERN_OBJ) $(INTERN_DEP)

fclean: clean
	@printf "\e[31mCleaning $(NAME) ...\e(B\e[m\n"
	$(SILENT)rm -f $(NAME)

re: fclean all
