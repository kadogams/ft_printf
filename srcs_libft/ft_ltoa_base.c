/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:17:20 by skadogam          #+#    #+#             */
/*   Updated: 2018/09/25 14:46:47 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_llen(long l, int base)
{
	size_t	len;

	len = 1;
	if (base == 10 && l < 0)
		len++;
	while (l /= base)
		len++;
	return (len);
}

char			*ft_ltoa_base(long l, int base, int hi_lo)
{
	unsigned long	lu;
	int				neg;
	size_t			len;
	char			*dst;

	neg = 0;
	len = (base < 2 || base > 16) ? 0 : ft_llen(l, base);
	if (base < 2 || base > 16 || !(dst = ft_strnew(len)))
		return (NULL);
	if (l < 0 && base == 10)
	{
		dst[0] = '-';
		neg = -1;
	}
	lu = (l >= 0) ? (unsigned long)l : (unsigned long)-l;
	while (neg + len--)
	{
		if (lu % base < 10)
			dst[len] = lu % base + '0';
		else
			dst[len] = hi_lo ? lu % base + 'A' - 10 : lu % base + 'a' - 10;
		lu /= base;
	}
	return (dst);
}
