/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:08:03 by skadogam          #+#    #+#             */
/*   Updated: 2018/10/03 15:52:40 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_add_hash(t_list **buff, t_buff **flags, const char *s,
				size_t len)
{
	if ((*flags)->minus)
	{
		if (!(*flags)->width)
			len -= 2;
		if ((*flags)->hash == 2 || (*flags)->hash == 4)
			ft_memcpy((*buff)->content, "0x", 2);
		else if ((*flags)->hash == 3)
			ft_memcpy((*buff)->content, "0X", 2);
		else if ((*flags)->hash == 5)
			ft_memcpy((*buff)->content, "0b", 2);
		ft_memcpy(&((char*)(*buff)->content)[2], s, len);
	}
	else
	{
		if ((*flags)->hash == 1)
			((char*)(*buff)->content)[(*flags)->width - len - 1] = '0';
		else if ((*flags)->hash == 2 || (*flags)->hash == 4)
			ft_memcpy_back((*buff)->content, "0x", (*flags)->width - len, 2);
		else if ((*flags)->hash == 3)
			ft_memcpy_back((*buff)->content, "0X", (*flags)->width - len, 2);
		else if ((*flags)->hash == 5)
			ft_memcpy_back((*buff)->content, "0b", (*flags)->width - len, 2);
	}
}

static void	ft_convert_nbr3(t_list **buff, t_buff **flags, const char *s,
				size_t len)
{
	if (((*flags)->space || (*flags)->plus) && s[0] != '-')
	{
		((char*)(*buff)->content)[0] = (*flags)->plus ? '+' : ' ';
		ft_memcpy(&((char*)(*buff)->content)[1], s, len);
	}
	else if ((*flags)->hash)
	{
		if ((*flags)->hash == 1)
		{
			((char*)(*buff)->content)[0] = '0';
			ft_memcpy(&((char*)(*buff)->content)[1], s, len);
		}
		else
			ft_add_hash(buff, flags, s, len);
	}
	else
		ft_memcpy((*buff)->content, s, len);
}

static void	ft_convert_nbr2b(t_list **buff, t_buff **flags, char **s,
				size_t len)
{
	if (((*flags)->space || (*flags)->plus) && *s[0] != '-')
	{
		if ((*flags)->zero == '0')
			((char*)(*buff)->content)[0] = (*flags)->plus ? '+' : ' ';
		else
			((char*)(*buff)->content)[(*flags)->width - len - 1] =
				(*flags)->plus ? '+' : ' ';
	}
	else if ((*flags)->zero == '0')
	{
		if (*s[0] == '-')
		{
			*s[0] = '0';
			((char*)(*buff)->content)[0] = '-';
		}
		else if ((*flags)->hash > 1 && (*flags)->hash < 5)
			((char*)(*buff)->content)[1] = ((*flags)->hash == 3) ? 'X' : 'x';
		else if ((*flags)->hash == 5)
			((char*)(*buff)->content)[1] = 'b';
	}
	else if ((*flags)->hash)
		ft_add_hash(buff, flags, *s, len);
}

static void	ft_convert_nbr2(t_list **buff, t_buff **flags, char **s, size_t len)
{
	(*buff)->content = ft_strnew((*flags)->width);
	if ((*flags)->minus)
	{
		ft_memset(&((char*)(*buff)->content)[len - 1], ' ',
			(*flags)->width - len + 1);
		ft_convert_nbr3(buff, flags, *s, len);
	}
	else
	{
		ft_memset((*buff)->content, (*flags)->zero, (*flags)->width - len);
		ft_convert_nbr2b(buff, flags, s, len);
		ft_memcpy_back((*buff)->content, *s, (*flags)->width, len);
	}
	(*buff)->content_size = (*flags)->width;
}

void		ft_convert_nbr(t_list **buff, t_buff **flags, char *s, size_t len)
{
	if (len + ((*flags)->hash > 1) < (*flags)->width)
		ft_convert_nbr2(buff, flags, &s, len);
	else
	{
		(*flags)->width = 0;
		(*flags)->minus = 1;
		if (((*flags)->space || (*flags)->plus) && s[0] != '-')
			len++;
		else if ((*flags)->hash)
			len += ((*flags)->hash == 1) ? 1 : 2;
		(*buff)->content = ft_strnew(len);
		ft_convert_nbr3(buff, flags, s, len);
		(*buff)->content_size = len;
	}
	ft_strdel(&s);
}
