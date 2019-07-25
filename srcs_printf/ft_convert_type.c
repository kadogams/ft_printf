/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:24:53 by skadogam          #+#    #+#             */
/*   Updated: 2018/10/03 15:53:03 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_ld(va_list ap, t_list **buff, t_buff **flags)
{
	(*flags)->size = 3;
	ft_convert_signed(ap, buff, flags);
}

void	ft_convert_o(va_list ap, t_list **buff, t_buff **flags)
{
	(*flags)->base = 8;
	if ((*flags)->hash && (*flags)->precision == 0)
		(*flags)->precision++;
	ft_convert_unsigned(ap, buff, flags);
}

void	ft_convert_lo(va_list ap, t_list **buff, t_buff **flags)
{
	(*flags)->size = 3;
	(*flags)->base = 8;
	if ((*flags)->hash && (*flags)->precision == 0)
		(*flags)->precision++;
	ft_convert_unsigned(ap, buff, flags);
}

void	ft_convert_lu(va_list ap, t_list **buff, t_buff **flags)
{
	(*flags)->size = 3;
	ft_convert_unsigned(ap, buff, flags);
}
