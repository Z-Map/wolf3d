/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_wstring.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:34:07 by qloubier          #+#    #+#             */
/*   Updated: 2016/10/06 23:57:14 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_WSTRING_H
# define LIBFT_WSTRING_H
# include <wchar.h>
# include "ft.h"
# include "libft_memory.h"

size_t				ft_wcslen (const wchar_t *s);

/*
** TO DO
*/
char				*ft_wcsdup (const char *s1);
char				*ft_wcscpy (char *dst, const char *src);
char				*ft_wcsncpy (char *dst, const char *src, size_t n);
char				*ft_wcscat (char *s1, const char *s2);
char				*ft_wcsncat (char *s1, const char *s2, size_t n);
size_t				ft_wcslcat (char *dst, const char *src, size_t size);
char				*ft_wcschr (const char *s, int c);
char				*ft_wcsrchr (const char *s, int c);
char				*ft_wcschrnot (const char *s, int c);
char				*ft_wcschranpy (const char *s, const char *clst, char end);
int					ft_wcsidx(const char *s, int c);
char				*ft_wcsstr (const char *s1, const char *s2);
char				*ft_wcsnstr (const char *s1, const char *s2, size_t n);
int					ft_wcscmp (const char *s1, const char *s2);
int					ft_wcsncmp (const char *s1, const char *s2, size_t n);
char				*ft_wcsnew (size_t size);
void				ft_wcsdel (char **as);
void				ft_wcsclr (char *s);
void				ft_wcsiter(char *s, void (*f)(char *));
void				ft_wcsiteri(char *s, void (*f)(unsigned int, char *));
char				*ft_wcsmap(char const *s, char (*f)(char));
char				*ft_wcsmapi(char const *s, char (*f)(unsigned int, char));
int					ft_wcsequ(char const *s1, char const *s2);
int					ft_wcsnequ(char const *s1, char const *s2, size_t n);
char				*ft_wcssub(char const *s, unsigned int start, size_t len);
char				*ft_wcsjoin(char const *s1, char const *s2);
char				*ft_wcstrim(char const *s);
char				**ft_wcssplit(char const *s, char c);
int					ft_wisalnum(int c);
int					ft_wisalpha(int c);
int					ft_wisdigit(int c);
int					ft_wisascii(int c);
int					ft_wisprint(int c);
int					ft_wtolower(int c);
int					ft_wtoupper(int c);
int					ft_wislower(int c);
int					ft_wisupper(int c);
size_t				ft_wwrdcount(char const *s, int c);
char				*ft_wcsunsplit(const char **tab, char separator);
char				*ft_wcsmjoin(const size_t n, ...);
char				*ft_wcsreplace(char *s, char what, char by);
size_t				ft_wcscount(const char *str, char c);
int					ft_wcsncount(char *str, char c, unsigned int n);
char				*ft_wcsrev(char *str);
char				*ft_wcsnrev(char *str, size_t n);
char				*ft_wcsup(char *s);
char				*ft_wcsupdup(const char *s);
char				*ft_wcslow(char *s);
char				*ft_wcslowdup(const char *s);

#endif
