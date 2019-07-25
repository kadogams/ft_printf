/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:17:20 by skadogam          #+#    #+#             */
/*   Updated: 2018/09/27 15:06:38 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_julen(uintmax_t ju, int base)
{
	size_t	len;

	len = 1;
	while (ju /= base)
		len++;
	return (len);
}

char			*ft_jutoa_base(uintmax_t ju, int base, int hi_lo)
{
	size_t			len;
	char			*dst;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_julen(ju, base);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		if (ju % base < 10)
			dst[len] = ju % base + '0';
		else
			dst[len] = hi_lo ? ju % base + 'A' - 10 : ju % base + 'a' - 10;
		ju /= base;
	}
	return (dst);
}
