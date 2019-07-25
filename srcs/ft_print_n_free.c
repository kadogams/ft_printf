/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:45:46 by skadogam          #+#    #+#             */
/*   Updated: 2019/02/22 12:46:14 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_n_free(int fd, t_list **buff)
{
	t_list	*tmp;

	while (*buff)
	{
		tmp = (*buff)->next;
		write(fd, (*buff)->content, (*buff)->content_size);
		ft_memdel(&(*buff)->content);
		free(*buff);
		*buff = NULL;
		*buff = tmp;
	}
}
