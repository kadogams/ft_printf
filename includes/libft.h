/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:57:35 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/14 18:23:35 by kadogams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

void			ft_bzero(void *s, size_t n);
int				ft_isalpha(int c);
char			*ft_itoa_base(int n, int base, int hi_lo);
char			*ft_jtoa_base(intmax_t j, int base, int hi_lo);
char			*ft_jutoa_base(uintmax_t ju, int base, int hi_lo);
char			*ft_lltoa_base(long long ll, int base, int hi_lo);
char			*ft_llutoa_base(unsigned long long llu, int base, int hi_lo);
void			ft_lstaddback(t_list **alst, t_list *new_lst);
t_list			*ft_lstnew(void const *content, size_t content_size);
char			*ft_ltoa_base(long l, int base, int hi_lo);
char			*ft_lutoa_base(unsigned long lu, int base, int hi_lo);
void			*ft_memalloc(size_t size);
void			*ft_memcpy_back(void *dst, const void *src, size_t dst_len,\
					size_t src_len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);
int				ft_strchr2(const char *str, int c);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
size_t			ft_strspn(const char *s, const char *charset);
char			*ft_utoa_base(unsigned int u, int base, int hi_lo);
int				ft_wstrlen(const wchar_t *ws);

#endif
