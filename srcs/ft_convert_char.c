/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:29:02 by skadogam          #+#    #+#             */
/*   Updated: 2018/10/03 15:52:31 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s2(t_list **buff, t_buff **flags, char *s, size_t len)
{
	if ((int)(*flags)->precision != -1 && len > (*flags)->precision)
		len = (*flags)->precision;
	if (len < (*flags)->width)
	{
		(*buff)->content = ft_strnew((*flags)->width);
		if ((*flags)->minus)
		{
			ft_memset((*buff)->content, ' ', (*flags)->width);
			ft_memcpy((*buff)->content, s, len);
		}
		else
		{
			ft_memset((*buff)->content, (*flags)->zero, (*flags)->width);
			ft_memcpy_back((*buff)->content, s, (*flags)->width, len);
		}
		(*buff)->content_size = (*flags)->width;
	}
	else
	{
		(*buff)->content = ft_strnew(len);
		ft_memcpy((*buff)->content, s, len);
		(*buff)->content_size = len;
	}
}

void	ft_convert_s(va_list ap, t_list **buff, t_buff **flags)
{
	char	*s;

	if ((*flags)->size == 3)
	{
		ft_convert_wstr(ap, buff, flags);
		return ;
	}
	if (!(s = va_arg(ap, char*)))
		ft_convert_s2(buff, flags, "(null)", 6);
	else
		ft_convert_s2(buff, flags, s, ft_strlen(s));
}

void	ft_convert_char2(char c, t_list **buff, t_buff **flags)
{
	if ((*flags)->width)
	{
		(*buff)->content = ft_strnew((*flags)->width);
		ft_memset((*buff)->content, (*flags)->zero, (*flags)->width);
		if ((*flags)->minus)
			ft_memcpy((*buff)->content, &c, 1);
		else
			ft_memcpy_back((*buff)->content, &c, (*flags)->width, 1);
		(*buff)->content_size = (*flags)->width;
	}
	else
	{
		(*buff)->content = ft_strdup(&c);
		(*buff)->content_size = 1;
	}
}

void	ft_convert_char(va_list ap, t_list **buff, t_buff **flags)
{
	char	c;

	if ((*flags)->size == 3)
	{
		ft_convert_wchar(ap, buff, flags);
		return ;
	}
	c = (char)va_arg(ap, int);
	if ((*flags)->width)
	{
		(*buff)->content = ft_strnew((*flags)->width);
		ft_memset((*buff)->content, (*flags)->zero, (*flags)->width);
		if ((*flags)->minus)
			ft_memcpy((*buff)->content, &c, 1);
		else
			ft_memcpy_back((*buff)->content, &c, (*flags)->width, 1);
		(*buff)->content_size = (*flags)->width;
	}
	else
	{
		(*buff)->content = ft_strdup(&c);
		(*buff)->content_size = 1;
	}
}
