/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:29:54 by skadogam          #+#    #+#             */
/*   Updated: 2018/09/14 13:30:01 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_back(void *dst, const void *src, size_t dst_len,
			size_t src_len)
{
	while (src_len-- && dst_len--)
		((unsigned char*)dst)[dst_len] = ((unsigned char*)src)[src_len];
	return (dst);
}
