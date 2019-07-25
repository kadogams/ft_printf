/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:04:48 by skadogam          #+#    #+#             */
/*   Updated: 2019/02/22 12:46:39 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

# define intmax_t __intmax_t
# define uintmax_t __uintmax_t

/*
** size 1: hh | 2: h | 3: l | 4: ll | 5: z | 6: j
*/

typedef struct	s_buff
{
	size_t			width;
	size_t			precision;
	int				space;
	int				minus;
	int				plus;
	char			zero;
	int				hash;
	int				size;
	int				base;
	int				hi_lo;
}				t_buff;

void			ft_adjust_flags(t_list **buff, t_buff **flags, char *s);
t_buff			*ft_buffnew(void);
void			ft_convert_b(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_char(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_char2(char c, t_list **buff, t_buff **flags);
void			ft_convert_ld(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_lo(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_lu(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_lx(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_nbr(t_list **buf, t_buff **flags, char *s, size_t l);
void			ft_convert_o(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_p(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_percent(t_list **buff, t_buff **flags);
void			ft_convert_s(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_s2(t_list **buff, t_buff **flags, char *s, size_t l);
void			ft_convert_signed(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_unsigned(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_wchar(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_wstr(va_list ap, t_list **buff, t_buff **flags);
void			ft_convert_x(va_list ap, t_list **buff, t_buff **flags);
size_t			ft_flags(t_buff **flags, const char *s, const char *charset);
void			ft_init_wut(void
					(*wut[58])(va_list ap, t_list **buff, t_buff **flags));
size_t			ft_length(size_t *len, const char *s, const char *charset);
void			ft_print_n_free(int fd, t_list **buff);
size_t			ft_size(t_buff **flags, const char *s, const char *charset);

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

#endif
