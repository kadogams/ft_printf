/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:17:20 by skadogam          #+#    #+#             */
/*   Updated: 2018/10/10 09:31:41 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ulen(unsigned int u, int base)
{
	size_t	len;

	len = 1;
	while (u /= base)
		len++;
	return (len);
}

char			*ft_utoa_base(unsigned int u, int base, int hi_lo)
{
	size_t			len;
	char			*dst;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_ulen(u, base);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		if (u % base < 10)
			dst[len] = u % base + '0';
		else
			dst[len] = hi_lo ? u % base + 'A' - 10 : u % base + 'a' - 10;
		u /= base;
	}
	return (dst);
}
