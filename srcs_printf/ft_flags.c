/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 12:58:18 by skadogam          #+#    #+#             */
/*   Updated: 2018/10/03 15:55:39 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_size2(t_buff **flags, int c)
{
	if ((char)c == 'h')
	{
		if (!(*flags)->size)
			(*flags)->size = 2;
		else if ((*flags)->size == 2)
			(*flags)->size = 1;
	}
	else if ((char)c == 'l')
	{
		if ((*flags)->size < 3)
			(*flags)->size = 3;
		else if ((*flags)->size == 3)
			(*flags)->size = 4;
	}
	else if ((char)c == 'z')
		(*flags)->size = 5;
	else if ((char)c == 'j')
		(*flags)->size = 6;
}

size_t		ft_size(t_buff **flags, const char *s, const char *charset)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (charset[j])
		{
			if (s[i] == charset[j])
			{
				ft_size2(flags, s[i]);
				break ;
			}
			j++;
		}
		if (!charset[j])
			break ;
		i++;
	}
	return (i);
}

size_t		ft_length(size_t *len, const char *s, const char *charset)
{
	size_t	i;
	size_t	j;

	if ((int)*len == -1)
		*len = 0;
	i = 0;
	if (s[0] == '-')
		return (-1);
	while (s[i])
	{
		j = 0;
		while (charset[j])
		{
			if (s[i] == charset[j])
			{
				*len = *len * 10 + s[i] - '0';
				break ;
			}
			j++;
		}
		if (!charset[j])
			break ;
		i++;
	}
	return (i);
}

static void	ft_flags2(t_buff **flags, int c)
{
	if ((char)c == ' ')
		(*flags)->space = 1;
	else if ((char)c == '-')
		(*flags)->minus = 1;
	else if ((char)c == '+')
		(*flags)->plus = 1;
	else if ((char)c == '0')
		(*flags)->zero = '0';
	else if ((char)c == '#')
		(*flags)->hash = 1;
}

size_t		ft_flags(t_buff **flags, const char *s, const char *charset)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (charset[j])
		{
			if (s[i] == charset[j])
			{
				ft_flags2(flags, s[i]);
				break ;
			}
			j++;
		}
		if (!charset[j])
			break ;
		i++;
	}
	return (i);
}
