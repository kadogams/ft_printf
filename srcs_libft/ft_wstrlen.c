/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:23:04 by skadogam          #+#    #+#             */
/*   Updated: 2018/07/04 15:38:51 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(const wchar_t *ws)
{
	int	count;

	count = 0;
	while (*ws)
	{
		if (*ws >= 0 && !(*ws >= 0xd800 && *ws <= 0xdfff))
		{
			if (*ws < 0x80)
				count++;
			else if (*ws < 0x800)
				count += 2;
			else if (*ws < 0x10000)
				count += 3;
			else if (*ws < 0x110000)
				count += 4;
			else
				return (-1);
		}
		else
			return (-1);
		ws++;
	}
	return (count);
}
