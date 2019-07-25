/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:17:20 by skadogam          #+#    #+#             */
/*   Updated: 2018/09/27 15:05:59 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lulen(unsigned long lu, int base)
{
	size_t	len;

	len = 1;
	while (lu /= base)
		len++;
	return (len);
}

char			*ft_lutoa_base(unsigned long lu, int base, int hi_lo)
{
	size_t			len;
	char			*dst;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_lulen(lu, base);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		if (lu % base < 10)
			dst[len] = lu % base + '0';
		else
			dst[len] = hi_lo ? lu % base + 'A' - 10 : lu % base + 'a' - 10;
		lu /= base;
	}
	return (dst);
}
