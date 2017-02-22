/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 19:28:46 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/07 00:15:52 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

# include "ft.h"
# include "libft_string.h"
# include "libft_memory.h"
# include "libft_list.h"
# ifndef BUFF_SIZE
#  define BUFF_SIZE 80
# endif

# if BUFF_SIZE < 64
#  define GROW_SIZE 64
# else
#  define GROW_SIZE BUFF_SIZE
# endif
# if BUFF_SIZE > 128
#  define START_SIZE BUFF_SIZE
# else
#  define START_SIZE 128
# endif

typedef struct		s_gnl_buffer
{
	int				fd;
	t_idx			buf_size;
	t_idx			cursor;
	int				padding;
	char			*strb;
}					t_gnlb;

int					ft_get_line(int const fd, char **line);
void				ft_putchar (char c);
void				ft_putstr (char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_filename_ext(char *buf, const char *path,
						const char *ext, size_t len);

/*
** TO DO
*/

void				ft_putull(unsigned long long n);
void				ft_putfloat(float nb);
void				ft_putptr(void *ptr);
void				ft_putstab(const char **tab);
void				ft_putbits(void *data, size_t size);
void				ft_putmem(void *data, size_t size);
void				ft_puthex(void *data, size_t size);

#endif
