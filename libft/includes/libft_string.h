/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:34:07 by qloubier          #+#    #+#             */
/*   Updated: 2016/11/22 19:21:32 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H
# include "ft.h"
# include "libft_memory.h"

size_t				ft_strlen (const char *s);
char				*ft_strdup (const char *s1);
char				*ft_strcpy (char *dst, const char *src);
char				*ft_strncpy (char *dst, const char *src, size_t n);
char				*ft_strcat (char *s1, const char *s2);
char				*ft_strncat (char *s1, const char *s2, size_t n);
size_t				ft_strlcat (char *dst, const char *src, size_t size);
char				*ft_strchr (const char *s, int c);
char				*ft_strchrnul (const char *s, int c);
char				*ft_strrchr (const char *s, int c);
char				*ft_strnchr(const char *s, int c, size_t n);
char				*ft_strchrnot (const char *s, int c);
int					ft_strspn(const char *s, const char *skipset);
int					ft_strcspn(const char *s, const char *stop);
char				*ft_strpskp(const char *s, const char *skipset);
char				*ft_strpbrk(const char *s, const char *stopset);
char				*ft_strpbrknul(const char *s, const char *stopset);
int					ft_stridx(const char *s, int c);
int					ft_strnidx(const char *s, int c, size_t n);
char				*ft_strstr (const char *s1, const char *s2);
char				*ft_strnstr (const char *s1, const char *s2, size_t n);
int					ft_strcmp (const char *s1, const char *s2);
int					ft_strncmp (const char *s1, const char *s2, size_t n);
char				*ft_strnew (size_t size);
void				ft_strdel (char **as);
void				ft_strclr (char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
size_t				ft_wrdcount(char const *s, int c);
int					ft_strparse(char *str, char s,
						int (**parser)(char *, void *), void *param);

/*
** TO DO
*/

char				*ft_strunsplit(const char **tab, char separator);
char				*ft_strmjoin(const size_t n, ...);
char				*ft_strreplace(char *s, char what, char by);
size_t				ft_strcount(const char *str, char c);
size_t				ft_strncount(const char *str, char c, unsigned int n);
char				*ft_strrev(char *str);
char				*ft_strnrev(char *str, size_t n);
char				*ft_strup(char *s);
char				*ft_strupdup(const char *s);
char				*ft_strlow(char *s);
char				*ft_strlowdup(const char *s);

#endif
