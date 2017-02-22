/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:28:45 by qloubier          #+#    #+#             */
/*   Updated: 2017/02/10 16:13:11 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H
# include <stdarg.h>
# include <string.h>
# include "ft.h"
# include "libft_memory.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_static_list
{
	size_t			len;
	void			*data;
}					t_slst;

typedef struct		s_blist
{
	size_t			csize;
	size_t			bsize;
	size_t			len;
	void			*data;
	struct s_blist	*next;
}					t_blst;

typedef struct		s_blist_iter
{
	t_blst			*bloc;
	size_t			idx;
}					t_blit;

typedef struct		s_cbuf
{
	size_t			bsize;
	size_t			len;
	char			*data;
	struct s_cbuf	*next;
}					t_cbuf;

/*
**	Chained list function
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstlast(t_list *lst);
void				ft_lstpush(t_list **alst, t_list *elem);
void				ft_lstpushback(t_list **alst, t_list *elem);
size_t				ft_lstlen(t_list *lst);
void				*ft_lsttotab(t_list *node, size_t ts, size_t *len);
void				ft_lstcfree(void *vec, size_t s);

/*
**	Block List function
*/

t_blst				*ft_blstnew(size_t csize, const size_t bsize);
size_t				ft_blstlen(t_blst *blst);
void				*ft_blststore(t_blst *blst, void *data);
void				*ft_blstnstore(t_blst *blst, int n, ...);
void				*ft_blstget(t_blst *blst, size_t idx);
void				*ft_blstiter(t_blit *iterator);
t_blit				ft_blststart(t_blst *blst);
void				ft_blstfree(t_blst **blst);
void				*ft_blsttotab(t_blst *blst, size_t *len);

/*
** Character Buffer Function
*/

t_cbuf				*ft_cbufnew(size_t bsize);
int					ft_cbufpush(t_cbuf *b, char c);
int					ft_cbufspush(t_cbuf *b, const char *c);
int					ft_cbufsnpush(t_cbuf *b, const char *c, size_t n);
int					ft_cbufsbpush(t_cbuf *b, const char *c, size_t bsize);
char				ft_cbufget(t_cbuf *b, size_t idx);
int					ft_cbufwrite(t_cbuf *b, int fd);

/*
** Stack Buffer Function
*/

int					ft_sbuf(int (*cb)(t_cbuf *b, void *p), void *p);
int					ft_sbufn(int n, int (*cb)(t_cbuf *b, void *p), void *p);
int					ft_sbufpush(char c, int (*cb)(t_cbuf *b, void *p), void *p);

#endif
