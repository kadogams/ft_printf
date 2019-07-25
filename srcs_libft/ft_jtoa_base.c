/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:17:20 by skadogam          #+#    #+#             */
/*   Updated: 2018/09/27 14:58:46 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_jlen(intmax_t j, int base)
{
	size_t	len;

	len = 1;
	if (base == 10 && j < 0)
		len++;
	while (j /= base)
		len++;
	return (len);
}

char			*ft_jtoa_base(intmax_t j, int base, int hi_lo)
{
	uintmax_t	ju;
	int			neg;
	size_t		len;
	char		*dst;

	neg = 0;
	len = (base < 2 || base > 16) ? 0 : ft_jlen(j, base);
	if (base < 2 || base > 16 || !(dst = ft_strnew(len)))
		return (NULL);
	if (j < 0 && base == 10)
	{
		dst[0] = '-';
		neg = -1;
	}
	ju = (j >= 0) ? (uintmax_t)j : (uintmax_t)-j;
	while (neg + len--)
	{
		if (ju % base < 10)
			dst[len] = ju % base + '0';
		else
			dst[len] = hi_lo ? ju % base + 'A' - 10 : ju % base + 'a' - 10;
		ju /= base;
	}
	return (dst);
}
