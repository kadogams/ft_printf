/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:30:49 by skadogam          #+#    #+#             */
/*   Updated: 2018/11/07 11:27:41 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_add_precision(t_buff **flags, char *s, size_t *len)
{
	size_t	neg;
	char	*tmp;

	neg = (s[0] == '-') ? 1 : 0;
	tmp = ft_strnew((*flags)->precision + neg);
	ft_memset(tmp, '0', (*flags)->precision + neg - *len);
	if (neg)
	{
		s[0] = '0';
		tmp[0] = '-';
	}
	if ((*flags)->hash == 1 && *len < (*flags)->precision)
		(*flags)->hash = 0;
	ft_memcpy_back(tmp, s, (*flags)->precision + neg, *len);
	*len = (*flags)->precision + neg;
	ft_strdel(&s);
	return (tmp);
}

void		ft_adjust_flags(t_list **buff, t_buff **flags, char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if ((*flags)->hash && (*flags)->hash != 4 && s[0] == '0')
		(*flags)->hash = 0;
	if (!(*flags)->precision && s[0] == '0')
	{
		len = 0;
		if ((*flags)->hash == 4)
			(*flags)->zero = ' ';
	}
	else if ((int)(*flags)->precision != -1)
	{
		if (len <= (*flags)->precision)
			s = ft_add_precision(flags, s, &len);
		(*flags)->zero = ' ';
	}
	ft_convert_nbr(buff, flags, s, len);
}

void		ft_convert_unsigned(va_list ap, t_list **buff, t_buff **f)
{
	char	*s;

	(*f)->space = 0;
	(*f)->plus = 0;
	if ((*f)->zero == '0' && (*f)->precision < 2)
		(*f)->zero = ' ';
	if ((*f)->size == 6)
		s = ft_jutoa_base(va_arg(ap, uintmax_t), (*f)->base, (*f)->hi_lo);
	else if ((*f)->size == 5)
		s = ft_lutoa_base(va_arg(ap, size_t), (*f)->base, (*f)->hi_lo);
	else if ((*f)->size == 4)
		s = ft_llutoa_base(va_arg(ap, unsigned long long),
			(*f)->base, (*f)->hi_lo);
	else if ((*f)->size == 3)
		s = ft_lutoa_base(va_arg(ap, unsigned long), (*f)->base, (*f)->hi_lo);
	else if ((*f)->size == 2)
		s = ft_utoa_base((unsigned short int)va_arg(ap, unsigned int),
			(*f)->base, (*f)->hi_lo);
	else if ((*f)->size == 1)
		s = ft_utoa_base((unsigned char)va_arg(ap, unsigned int),
			(*f)->base, (*f)->hi_lo);
	else
		s = ft_utoa_base(va_arg(ap, unsigned int), (*f)->base, (*f)->hi_lo);
	ft_adjust_flags(buff, f, s);
}

void		ft_convert_signed(va_list ap, t_list **buff, t_buff **flags)
{
	char	*s;

	if ((*flags)->zero == '0' && (*flags)->precision < 2)
		(*flags)->zero = ' ';
	if ((*flags)->size == 6)
		s = ft_jtoa_base(va_arg(ap, intmax_t), 10, 0);
	else if ((*flags)->size == 5)
		s = ft_ltoa_base(va_arg(ap, size_t), 10, 0);
	else if ((*flags)->size == 4)
		s = ft_lltoa_base(va_arg(ap, long long), 10, 0);
	else if ((*flags)->size == 3)
		s = ft_ltoa_base(va_arg(ap, long), 10, 0);
	else if ((*flags)->size == 2)
		s = ft_itoa_base((short int)va_arg(ap, int), 10, 0);
	else if ((*flags)->size == 1)
		s = ft_itoa_base((char)va_arg(ap, int), 10, 0);
	else
		s = ft_itoa_base(va_arg(ap, int), 10, 0);
	ft_adjust_flags(buff, flags, s);
}
