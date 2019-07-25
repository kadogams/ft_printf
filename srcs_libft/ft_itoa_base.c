/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:17:20 by skadogam          #+#    #+#             */
/*   Updated: 2018/09/25 14:45:51 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_dlen(int n, int base)
{
	size_t	len;

	len = 1;
	if (base == 10 && n < 0)
		len++;
	while (n /= base)
		len++;
	return (len);
}

char			*ft_itoa_base(int n, int base, int hi_lo)
{
	unsigned int	u;
	int				neg;
	size_t			len;
	char			*dst;

	neg = 0;
	len = (base < 2 || base > 16) ? 0 : ft_dlen(n, base);
	if (base < 2 || base > 16 || !(dst = ft_strnew(len)))
		return (NULL);
	if (n < 0 && base == 10)
	{
		dst[0] = '-';
		neg = -1;
	}
	u = (n >= 0) ? (unsigned int)n : (unsigned int)-n;
	while (neg + len--)
	{
		if (u % base < 10)
			dst[len] = u % base + '0';
		else
			dst[len] = hi_lo ? u % base + 'A' - 10 : u % base + 'a' - 10;
		u /= base;
	}
	return (dst);
}
