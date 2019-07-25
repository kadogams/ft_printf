/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_type2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:26:48 by skadogam          #+#    #+#             */
/*   Updated: 2018/10/03 15:56:17 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_x(va_list ap, t_list **buff, t_buff **flags)
{
	(*flags)->base = 16;
	if ((*flags)->hash)
		(*flags)->hash++;
	ft_convert_unsigned(ap, buff, flags);
}

void	ft_convert_lx(va_list ap, t_list **buff, t_buff **flags)
{
	(*flags)->base = 16;
	(*flags)->hi_lo = 1;
	if ((*flags)->hash)
		(*flags)->hash = 3;
	ft_convert_unsigned(ap, buff, flags);
}

void	ft_convert_p(va_list ap, t_list **buff, t_buff **flags)
{
	unsigned long	p;

	(*flags)->base = 16;
	(*flags)->size = 3;
	(*flags)->hash = 4;
	(*flags)->space = 0;
	(*flags)->plus = 0;
	p = va_arg(ap, unsigned long);
	ft_adjust_flags(buff, flags, ft_lutoa_base(p, 16, 0));
}

void	ft_convert_percent(t_list **buff, t_buff **flags)
{
	(*flags)->precision = -1;
	(*flags)->space = 0;
	(*flags)->plus = 0;
	(*flags)->hash = 0;
	ft_adjust_flags(buff, flags, ft_strdup("%"));
}

void	ft_convert_b(va_list ap, t_list **buff, t_buff **flags)
{
	(*flags)->base = 2;
	if ((*flags)->hash)
		(*flags)->hash = 5;
	ft_convert_unsigned(ap, buff, flags);
}
