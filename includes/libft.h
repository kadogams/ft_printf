/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:57:35 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/25 15:12:12 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "get_next_line.h"

# define intmax_t __intmax_t
# define uintmax_t __uintmax_t

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_dlist
{
	void			*content;
	struct s_dlist	*previous;
	struct s_dlist	*next;
}				t_dlist;

int				ft_abs(int n);
int				ft_atoi(const char *str);
int				ft_atoi_base(const char *str, int base);
intmax_t		ft_atoimax_base(const char *str, int base);
void			ft_bzero(void *s, size_t n);
void			ft_dlstadd(t_dlist **alst, t_dlist *new);
void			ft_dlstaddback(t_dlist **alst, t_dlist *new);
void			ft_dlstdel(t_dlist **alst);
void			ft_dlstdelone(t_dlist **alst);
t_dlist			*ft_dlstnew(void);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, int base, int hi_lo);
char			*ft_jtoa_base(intmax_t j, int base, int hi_lo);
char			*ft_jutoa_base(uintmax_t ju, int base, int hi_lo);
char			*ft_lltoa_base(long long ll, int base, int hi_lo);
char			*ft_llutoa_base(unsigned long long llu, int base, int hi_lo);
void			ft_lstadd(t_list **alst, t_list *new_lst);
void			ft_lstaddback(t_list **alst, t_list *new_lst);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel2(t_list **alst);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone2(t_list **alst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t			ft_lstlen(t_list *lst);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
char			*ft_ltoa_base(long l, int base, int hi_lo);
char			*ft_lutoa_base(unsigned long lu, int base, int hi_lo);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp_zero(const void *s, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy_back(void *dst, const void *src, size_t dst_len,\
					size_t src_len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memset_back(void *b, int c, size_t len, size_t n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
float			ft_sqrt(float x);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_strchr2(const char *str, int c);
void			ft_strclr(char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin_free_s1(char *s1, char const *s2);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *haystack, const char *needle,\
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *str);
char			**ft_strsplit(const char *s, char c);
size_t			ft_strspn(const char *s, const char *charset);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_utoa_base(unsigned int u, int base, int hi_lo);
int				ft_wstrlen(const wchar_t *ws);

#endif
