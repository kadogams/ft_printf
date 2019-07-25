/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:59:37 by skadogam          #+#    #+#             */
/*   Updated: 2018/10/16 15:28:51 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 256

typedef struct s_dlist	t_dlist;

typedef struct	s_line
{
	int				fd;
	size_t			eol;
	size_t			save;
	t_dlist			*buff;
	struct s_line	*prev;
	struct s_line	*next;
}				t_line;

int				get_next_line(const int fd, char **line);
int				get_next_line_v2(const int fd, char **line, int write);

#endif
