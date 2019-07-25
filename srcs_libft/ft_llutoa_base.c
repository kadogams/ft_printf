/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:17:20 by skadogam          #+#    #+#             */
/*   Updated: 2018/09/25 14:46:08 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_llulen(unsigned long long llu, int base)
{
	size_t	len;

	len = 1;
	while (llu /= base)
		len++;
	return (len);
}

char			*ft_llutoa_base(unsigned long long llu, int base, int hi_lo)
{
	size_t				len;
	char				*dst;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_llulen(llu, base);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		if (llu % base < 10)
			dst[len] = llu % base + '0';
		else
			dst[len] = hi_lo ? llu % base + 'A' - 10 : llu % base + 'a' - 10;
		llu /= base;
	}
	return (dst);
}
