/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:23:32 by skadogam          #+#    #+#             */
/*   Updated: 2018/10/04 14:05:49 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** wchar_t:
** < 0x80 = 1 byte: 0xxxxxxx
** < 0x800 = 2 bytes: 110xxxxx 10xxxxxx
** < 0x10000 = 3 bytes: 1110xxxx 10xxxxxx 10xxxxxx
** > 0xffff = 4 bytes: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

static size_t	ft_convert_bytes(wchar_t wc, char *s)
{
	if (wc < 0x80)
	{
		*s = (char)wc;
		return (1);
	}
	if (wc < 0x800)
	{
		s[0] = 0b11000000 | (wc >> 6);
		s[1] = 0b10000000 | (wc & 0b00111111);
		return (2);
	}
	else if (wc < 0x10000)
	{
		s[0] = 0b11100000 | (wc >> 12);
		s[1] = 0b10000000 | ((wc >> 6) & 0b00111111);
		s[2] = 0b10000000 | (wc & 0b00111111);
		return (3);
	}
	s[0] = 0b11110000 | (wc >> 18);
	s[1] = 0b10000000 | ((wc >> 12) & 0b00111111);
	s[2] = 0b10000000 | ((wc >> 6) & 0b00111111);
	s[3] = 0b10000000 | (wc & 0b00111111);
	return (4);
}

void			ft_convert_wchar(va_list ap, t_list **buff, t_buff **flags)
{
	wchar_t	wc[2];
	int		len;
	char	*s;

	(*flags)->precision = -1;
	wc[0] = (wchar_t)va_arg(ap, int);
	wc[1] = 0;
	if (!(len = ft_wstrlen(wc)))
		len++;
	if (len == 1)
		ft_convert_char2((char)*wc, buff, flags);
	else
	{
		if (len == -1 || !(s = ft_strnew(len)))
		{
			(*buff)->content_size = -1;
			return ;
		}
		ft_convert_bytes(*wc, s);
		ft_convert_s2(buff, flags, s, len);
		ft_strdel(&s);
	}
}

static void		ft_adjust_len(t_buff **flags, char *s, int *len)
{
	*len = (int)(*flags)->precision;
	while (*len)
	{
		if (!(s[*len] & (1 << 7)) || s[*len] & (1 << 6))
			break ;
		*len -= 1;
	}
}

void			ft_convert_wstr(va_list ap, t_list **buff, t_buff **flags)
{
	int		len;
	size_t	i;
	char	*s;
	wchar_t	*ws;

	i = 0;
	if (!(ws = va_arg(ap, wchar_t*)))
		ft_convert_s2(buff, flags, "(null)", 6);
	else
	{
		len = ft_wstrlen(ws);
		if (len == -1 || !(s = ft_strnew(len)))
		{
			(*buff)->content_size = -1;
			return ;
		}
		while (*ws)
			i += ft_convert_bytes(*ws++, &s[i]);
		if ((int)(*flags)->precision != -1 && (size_t)len > (*flags)->precision)
			ft_adjust_len(flags, s, &len);
		ft_convert_s2(buff, flags, s, len);
		ft_strdel(&s);
	}
}
