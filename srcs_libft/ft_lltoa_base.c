/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:17:20 by skadogam          #+#    #+#             */
/*   Updated: 2018/09/25 14:45:59 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lllen(long long ll, int base)
{
	size_t	len;

	len = 1;
	if (base == 10 && ll < 0)
		len++;
	while (ll /= base)
		len++;
	return (len);
}

char			*ft_lltoa_base(long long ll, int base, int hi_lo)
{
	unsigned long long	llu;
	int					neg;
	size_t				len;
	char				*dst;

	neg = 0;
	len = (base < 2 || base > 16) ? 0 : ft_lllen(ll, base);
	if (base < 2 || base > 16 || !(dst = ft_strnew(len)))
		return (NULL);
	if (ll < 0 && base == 10)
	{
		dst[0] = '-';
		neg = -1;
	}
	llu = (ll >= 0) ? (unsigned long long)ll : (unsigned long long)-ll;
	while (neg + len--)
	{
		if (llu % base < 10)
			dst[len] = llu % base + '0';
		else
			dst[len] = hi_lo ? llu % base + 'A' - 10 : llu % base + 'a' - 10;
		llu /= base;
	}
	return (dst);
}
