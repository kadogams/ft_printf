/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:11:18 by skadogam          #+#    #+#             */
/*   Updated: 2018/10/03 15:55:54 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_buff	*ft_buffnew(void)
{
	t_buff	*new_flags;

	if (!(new_flags = (t_buff*)malloc(sizeof(*new_flags))))
		return (NULL);
	new_flags->width = 0;
	new_flags->space = 0;
	new_flags->minus = 0;
	new_flags->plus = 0;
	new_flags->zero = ' ';
	new_flags->hash = 0;
	new_flags->precision = -1;
	new_flags->size = 0;
	new_flags->base = 10;
	new_flags->hi_lo = 0;
	return (new_flags);
}

void	ft_init_wut(void (*wut[58])(va_list ap, t_list **b, t_buff **f))
{
	size_t	len;

	len = 58;
	while (len--)
		wut[len] = NULL;
	wut[(int)'b' - 65] = ft_convert_b;
	wut[(int)'c' - 65] = ft_convert_char;
	wut[(int)'C' - 65] = ft_convert_wchar;
	wut[(int)'d' - 65] = ft_convert_signed;
	wut[(int)'D' - 65] = ft_convert_ld;
	wut[(int)'i' - 65] = ft_convert_signed;
	wut[(int)'o' - 65] = ft_convert_o;
	wut[(int)'O' - 65] = ft_convert_lo;
	wut[(int)'p' - 65] = ft_convert_p;
	wut[(int)'s' - 65] = ft_convert_s;
	wut[(int)'S' - 65] = ft_convert_wstr;
	wut[(int)'u' - 65] = ft_convert_unsigned;
	wut[(int)'U' - 65] = ft_convert_lu;
	wut[(int)'x' - 65] = ft_convert_x;
	wut[(int)'X' - 65] = ft_convert_lx;
}
