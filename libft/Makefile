# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qloubier <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 15:33:48 by qloubier          #+#    #+#              #
#    Updated: 2017/02/22 15:33:48 by qloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-Wextra -Werror -Weverything
CFLAGS_OBJ=
INCFLAGS=-Iinclude -Iincludes 
LIBFLAGS=   
OBJ=ft_bzero.o \
ft_memalign.o \
ft_memalloc.o \
ft_memccpy.o \
ft_memchr.o \
ft_memcmp.o \
ft_memcpy.o \
ft_memdel.o \
ft_memdup.o \
ft_memmove.o \
ft_memset.o \
ft_memswp.o \
ft_ptabdel.o \
ft_blstfree.o \
ft_blstget.o \
ft_blstiter.o \
ft_blstlen.o \
ft_blstnew.o \
ft_blststart.o \
ft_blststore.o \
ft_blsttotab.o \
ft_cbufnew.o \
ft_lstadd.o \
ft_lstcfree.o \
ft_lstdel.o \
ft_lstdelone.o \
ft_lstiter.o \
ft_lstlast.o \
ft_lstlen.o \
ft_lstmap.o \
ft_lstnew.o \
ft_lstpush.o \
ft_lstpushback.o \
ft_lsttotab.o \
ft_isalnum.o \
ft_isalpha.o \
ft_isascii.o \
ft_isdigit.o \
ft_islower.o \
ft_isprint.o \
ft_isupper.o \
ft_strcat.o \
ft_strchr.o \
ft_strchrnot.o \
ft_strchrnul.o \
ft_strclr.o \
ft_strcmp.o \
ft_strcpy.o \
ft_strcspn.o \
ft_strdel.o \
ft_strdup.o \
ft_strequ.o \
ft_stridx.o \
ft_striter.o \
ft_striteri.o \
ft_strjoin.o \
ft_strlcat.o \
ft_strlen.o \
ft_strmap.o \
ft_strmapi.o \
ft_strncat.o \
ft_strnchr.o \
ft_strncmp.o \
ft_strncpy.o \
ft_strnequ.o \
ft_strnew.o \
ft_strnidx.o \
ft_strnstr.o \
ft_strparse.o \
ft_strpbrk.o \
ft_strpbrknul.o \
ft_strpskp.o \
ft_strrchr.o \
ft_strsplit.o \
ft_strspn.o \
ft_strstr.o \
ft_strsub.o \
ft_strtrim.o \
ft_tolower.o \
ft_toupper.o \
ft_wrdcount.o \
ft_dtoa.o \
ft_floatlen.o \
ft_ftoa.o \
ft_itoa.o \
ft_jdigitlen.o \
ft_jnbrlen.o \
ft_lnbrlen.o \
ft_nbrlen.o \
ft_nbrlen_base.o \
ft_snbrlen.o \
ft_ujdigitlen.o \
ft_ujfillbuf.o \
ft_ujfillbufbase.o \
ft_ujnbrlen.o \
ft_ujtobuf.o \
ft_atoi.o \
ft_bufskip.o \
ft_bufskipf.o \
ft_buftod.o \
ft_buftof.o \
ft_buftoi.o \
ft_buftoj.o \
ft_buftol.o \
ft_buftold.o \
ft_buftoui.o \
ft_buftouj.o \
ft_buftoul.o \
ft_forf.o \
ft_parse_assign.o \
ft_parse_cmap.o \
ft_parse_digit.o \
ft_parsef.o \
ft_parsej_cmap.o \
ft_parseld.o \
ft_scanf_loop.o \
ft_scanf_parse.o \
ft_sfbuftoarg.o \
ft_sfbuftofarg.o \
ft_sfbuftouarg.o \
ft_sfconv_c.o \
ft_sfconv_d.o \
ft_sfconv_f.o \
ft_sfconv_i.o \
ft_sfconv_n.o \
ft_sfconv_s.o \
ft_sfconv_u.o \
ft_sfflag_h.o \
ft_sfflag_j.o \
ft_sfflag_l.o \
ft_sfflag_nc.o \
ft_sfflag_width.o \
ft_sfflag_z.o \
ft_sscanf.o \
ft_filename_ext.o \
ft_get_line.o \
ft_putchar.o \
ft_putchar_fd.o \
ft_putendl.o \
ft_putendl_fd.o \
ft_putnbr.o \
ft_putnbr_fd.o \
ft_putstr.o \
ft_putstr_fd.o \
ft_wcslen.o \
ft_utf8fromwc.o \
ft_utf8wcsalign.o \
ft_utf8wcsize.o \
ft_utf8wcslen.o \
ft_dprintf.o \
ft_pfarg_bin.o \
ft_pfarg_char.o \
ft_pfarg_float.o \
ft_pfarg_hex.o \
ft_pfarg_n.o \
ft_pfarg_nbr.o \
ft_pfarg_oct.o \
ft_pfarg_ptr.o \
ft_pfarg_spc.o \
ft_pfarg_str.o \
ft_pfarg_unbr.o \
ft_pfarg_wstr.o \
ft_pfconv_char.o \
ft_pfconv_float.o \
ft_pfconv_n.o \
ft_pfconv_nbr.o \
ft_pfconv_str.o \
ft_pfconv_unbr.o \
ft_pfflag_alt.o \
ft_pfflag_dot.o \
ft_pfflag_h.o \
ft_pfflag_j.o \
ft_pfflag_l.o \
ft_pfflag_less.o \
ft_pfflag_more.o \
ft_pfflag_space.o \
ft_pfflag_width.o \
ft_pfflag_z.o \
ft_pfflag_zero.o \
ft_pflen_char.o \
ft_pflen_float.o \
ft_pflen_n.o \
ft_pflen_nbr.o \
ft_pflen_str.o \
ft_pflen_unbr.o \
ft_printf.o \
ft_printf_bflush.o \
ft_printf_bwrite.o \
ft_printf_bwritec.o \
ft_printf_bwritew.o \
ft_printf_convert.o \
ft_printf_loop.o \
ft_printf_parse.o \
ft_fround.o \
ft_ftrunc.o \
ft_lastfdigit.o \
ft_lastpow2digit.o \


.PHONY: clean fclean re all
	$(MAKE) clean

all: $(NAME)

ft_bzero.o: mem/ft_bzero.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memalign.o: mem/ft_memalign.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memalloc.o: mem/ft_memalloc.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memccpy.o: mem/ft_memccpy.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memchr.o: mem/ft_memchr.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memcmp.o: mem/ft_memcmp.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memcpy.o: mem/ft_memcpy.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memdel.o: mem/ft_memdel.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memdup.o: mem/ft_memdup.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memmove.o: mem/ft_memmove.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memset.o: mem/ft_memset.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_memswp.o: mem/ft_memswp.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_ptabdel.o: mem/ft_ptabdel.c include/libft_memory.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_blstfree.o: lst/ft_blstfree.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_blstget.o: lst/ft_blstget.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_blstiter.o: lst/ft_blstiter.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_blstlen.o: lst/ft_blstlen.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_blstnew.o: lst/ft_blstnew.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_blststart.o: lst/ft_blststart.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_blststore.o: lst/ft_blststore.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_blsttotab.o: lst/ft_blsttotab.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_cbufnew.o: lst/ft_cbufnew.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstadd.o: lst/ft_lstadd.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstcfree.o: lst/ft_lstcfree.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstdel.o: lst/ft_lstdel.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstdelone.o: lst/ft_lstdelone.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstiter.o: lst/ft_lstiter.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstlast.o: lst/ft_lstlast.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstlen.o: lst/ft_lstlen.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstmap.o: lst/ft_lstmap.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstnew.o: lst/ft_lstnew.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstpush.o: lst/ft_lstpush.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lstpushback.o: lst/ft_lstpushback.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lsttotab.o: lst/ft_lsttotab.c include/libft_list.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_isalnum.o: str/ft_isalnum.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_isalpha.o: str/ft_isalpha.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_isascii.o: str/ft_isascii.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_isdigit.o: str/ft_isdigit.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_islower.o: str/ft_islower.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_isprint.o: str/ft_isprint.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_isupper.o: str/ft_isupper.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strcat.o: str/ft_strcat.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strchr.o: str/ft_strchr.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strchrnot.o: str/ft_strchrnot.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strchrnul.o: str/ft_strchrnul.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strclr.o: str/ft_strclr.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strcmp.o: str/ft_strcmp.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strcpy.o: str/ft_strcpy.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strcspn.o: str/ft_strcspn.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strdel.o: str/ft_strdel.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strdup.o: str/ft_strdup.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strequ.o: str/ft_strequ.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_stridx.o: str/ft_stridx.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_striter.o: str/ft_striter.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_striteri.o: str/ft_striteri.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strjoin.o: str/ft_strjoin.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strlcat.o: str/ft_strlcat.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strlen.o: str/ft_strlen.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strmap.o: str/ft_strmap.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strmapi.o: str/ft_strmapi.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strncat.o: str/ft_strncat.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strnchr.o: str/ft_strnchr.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strncmp.o: str/ft_strncmp.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strncpy.o: str/ft_strncpy.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strnequ.o: str/ft_strnequ.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strnew.o: str/ft_strnew.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strnidx.o: str/ft_strnidx.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strnstr.o: str/ft_strnstr.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strparse.o: str/ft_strparse.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strpbrk.o: str/ft_strpbrk.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strpbrknul.o: str/ft_strpbrknul.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strpskp.o: str/ft_strpskp.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strrchr.o: str/ft_strrchr.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strsplit.o: str/ft_strsplit.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strspn.o: str/ft_strspn.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strstr.o: str/ft_strstr.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strsub.o: str/ft_strsub.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_strtrim.o: str/ft_strtrim.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_tolower.o: str/ft_tolower.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_toupper.o: str/ft_toupper.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_wrdcount.o: str/ft_wrdcount.c include/libft_string.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_dtoa.o: format/ft_dtoa.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_floatlen.o: format/ft_floatlen.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_ftoa.o: format/ft_ftoa.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_itoa.o: format/ft_itoa.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_jdigitlen.o: format/ft_jdigitlen.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_jnbrlen.o: format/ft_jnbrlen.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lnbrlen.o: format/ft_lnbrlen.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_nbrlen.o: format/ft_nbrlen.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_nbrlen_base.o: format/ft_nbrlen_base.c include/libft_format.h \
  include/ft.h include/libft_parse.h include/libft_string.h \
  include/libft_memory.h include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_snbrlen.o: format/ft_snbrlen.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_ujdigitlen.o: format/ft_ujdigitlen.c include/libft_format.h \
  include/ft.h include/libft_parse.h include/libft_string.h \
  include/libft_memory.h include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_ujfillbuf.o: format/ft_ujfillbuf.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_ujfillbufbase.o: format/ft_ujfillbufbase.c include/libft_format.h \
  include/ft.h include/libft_parse.h include/libft_string.h \
  include/libft_memory.h include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_ujnbrlen.o: format/ft_ujnbrlen.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_ujtobuf.o: format/ft_ujtobuf.c include/libft_format.h include/ft.h \
  include/libft_parse.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_atoi.o: parse/ft_atoi.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_bufskip.o: parse/ft_bufskip.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_bufskipf.o: parse/ft_bufskipf.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_buftod.o: parse/ft_buftod.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_buftof.o: parse/ft_buftof.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_buftoi.o: parse/ft_buftoi.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_buftoj.o: parse/ft_buftoj.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_buftol.o: parse/ft_buftol.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_buftold.o: parse/ft_buftold.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_buftoui.o: parse/ft_buftoui.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_buftouj.o: parse/ft_buftouj.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_buftoul.o: parse/ft_buftoul.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_forf.o: parse/ft_forf.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_parse_assign.o: parse/ft_parse_assign.c include/libft_parse.h \
  include/ft.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h include/libft_printf.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_parse_cmap.o: parse/ft_parse_cmap.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_parse_digit.o: parse/ft_parse_digit.c include/libft_parse.h \
  include/ft.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_parsef.o: parse/ft_parsef.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_parsej_cmap.o: parse/ft_parsej_cmap.c include/libft_parse.h \
  include/ft.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_parseld.o: parse/ft_parseld.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_scanf_loop.o: parse/ft_scanf_loop.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_scanf_parse.o: parse/ft_scanf_parse.c include/libft_parse.h \
  include/ft.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfbuftoarg.o: parse/ft_sfbuftoarg.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfbuftofarg.o: parse/ft_sfbuftofarg.c include/libft_parse.h \
  include/ft.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfbuftouarg.o: parse/ft_sfbuftouarg.c include/libft_parse.h \
  include/ft.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfconv_c.o: parse/ft_sfconv_c.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfconv_d.o: parse/ft_sfconv_d.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfconv_f.o: parse/ft_sfconv_f.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfconv_i.o: parse/ft_sfconv_i.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfconv_n.o: parse/ft_sfconv_n.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfconv_s.o: parse/ft_sfconv_s.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfconv_u.o: parse/ft_sfconv_u.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfflag_h.o: parse/ft_sfflag_h.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfflag_j.o: parse/ft_sfflag_j.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfflag_l.o: parse/ft_sfflag_l.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfflag_nc.o: parse/ft_sfflag_nc.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfflag_width.o: parse/ft_sfflag_width.c include/libft_parse.h \
  include/ft.h include/libft_string.h include/libft_memory.h \
  include/libft_math.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sfflag_z.o: parse/ft_sfflag_z.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_sscanf.o: parse/ft_sscanf.c include/libft_parse.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_math.h \
  include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_filename_ext.o: io/ft_filename_ext.c include/libft_io.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_list.h \
  include/libft_printf.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_get_line.o: io/ft_get_line.c include/libft_io.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_putchar.o: io/ft_putchar.c include/libft_io.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_putchar_fd.o: io/ft_putchar_fd.c include/libft_io.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_putendl.o: io/ft_putendl.c include/libft_io.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_putendl_fd.o: io/ft_putendl_fd.c include/libft_io.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_putnbr.o: io/ft_putnbr.c include/libft_io.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_putnbr_fd.o: io/ft_putnbr_fd.c include/libft_io.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_putstr.o: io/ft_putstr.c include/libft_io.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_putstr_fd.o: io/ft_putstr_fd.c include/libft_io.h include/ft.h \
  include/libft_string.h include/libft_memory.h include/libft_list.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_wcslen.o: wstr/ft_wcslen.c include/libft_wstring.h include/ft.h \
  include/libft_memory.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_utf8fromwc.o: unicode/ft_utf8fromwc.c include/libft_unicode.h \
  include/ft.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_utf8wcsalign.o: unicode/ft_utf8wcsalign.c include/libft_unicode.h \
  include/ft.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_utf8wcsize.o: unicode/ft_utf8wcsize.c include/libft_unicode.h \
  include/ft.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_utf8wcslen.o: unicode/ft_utf8wcslen.c include/libft_unicode.h \
  include/ft.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_dprintf.o: printf/ft_dprintf.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_bin.o: printf/ft_pfarg_bin.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_char.o: printf/ft_pfarg_char.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_float.o: printf/ft_pfarg_float.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_hex.o: printf/ft_pfarg_hex.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_n.o: printf/ft_pfarg_n.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_nbr.o: printf/ft_pfarg_nbr.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_oct.o: printf/ft_pfarg_oct.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_ptr.o: printf/ft_pfarg_ptr.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_spc.o: printf/ft_pfarg_spc.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_str.o: printf/ft_pfarg_str.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_unbr.o: printf/ft_pfarg_unbr.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfarg_wstr.o: printf/ft_pfarg_wstr.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfconv_char.o: printf/ft_pfconv_char.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfconv_float.o: printf/ft_pfconv_float.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfconv_n.o: printf/ft_pfconv_n.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfconv_nbr.o: printf/ft_pfconv_nbr.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfconv_str.o: printf/ft_pfconv_str.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfconv_unbr.o: printf/ft_pfconv_unbr.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_alt.o: printf/ft_pfflag_alt.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_dot.o: printf/ft_pfflag_dot.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_h.o: printf/ft_pfflag_h.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_j.o: printf/ft_pfflag_j.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_l.o: printf/ft_pfflag_l.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_less.o: printf/ft_pfflag_less.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_more.o: printf/ft_pfflag_more.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_space.o: printf/ft_pfflag_space.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_width.o: printf/ft_pfflag_width.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_z.o: printf/ft_pfflag_z.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pfflag_zero.o: printf/ft_pfflag_zero.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pflen_char.o: printf/ft_pflen_char.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pflen_float.o: printf/ft_pflen_float.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pflen_n.o: printf/ft_pflen_n.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pflen_nbr.o: printf/ft_pflen_nbr.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pflen_str.o: printf/ft_pflen_str.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_pflen_unbr.o: printf/ft_pflen_unbr.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_printf.o: printf/ft_printf.c include/libft_printf.h include/ft.h \
  include/libft_list.h include/libft_memory.h include/libft_string.h \
  include/libft_wstring.h include/libft_unicode.h include/libft_parse.h \
  include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_printf_bflush.o: printf/ft_printf_bflush.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_printf_bwrite.o: printf/ft_printf_bwrite.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_printf_bwritec.o: printf/ft_printf_bwritec.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_printf_bwritew.o: printf/ft_printf_bwritew.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_printf_convert.o: printf/ft_printf_convert.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_printf_loop.o: printf/ft_printf_loop.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_printf_parse.o: printf/ft_printf_parse.c include/libft_printf.h \
  include/ft.h include/libft_list.h include/libft_memory.h \
  include/libft_string.h include/libft_wstring.h include/libft_unicode.h \
  include/libft_parse.h include/libft_math.h include/libft_format.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_fround.o: math/ft_fround.c include/libft_math.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_ftrunc.o: math/ft_ftrunc.c include/libft_math.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lastfdigit.o: math/ft_lastfdigit.c include/libft_math.h include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 
ft_lastpow2digit.o: math/ft_lastpow2digit.c include/libft_math.h \
  include/ft.h
	$(CC) -o $@ -c $< $(CFLAGS) $(CFLAGS_OBJ) $(INCFLAGS) 

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

