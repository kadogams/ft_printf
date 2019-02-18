/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:46:24 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/18 14:24:54 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int check_space_digit(char *line, t_asm *env)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			i++;
		else
			break;
	}
	i += skip_whitespace(line + i, env, UPDATE_X);
	if (line[i] == '\0')
		return (OK);
	return (KO);
}

int	skip_whitespace(char *str, t_asm *env, int update)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str && str[i])
	{
		if (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
		str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		{
			i++;
			if (update)
				env->cur_x += 1;
			continue ;
		}
		if (update)
			env->cur_x += 1;
		break ;
	}
	return (i);
}

int		check_last_line(char *line, int option, t_asm *env)
{
	char	*str;
	int		i;

	str = ft_strchr(line, '"');
	if (option)
		str = ft_strchr(str + 1, '"');
	i = skip_whitespace(str + 1, env, UPDATE_X) + 1;
	if (str[i] == '\0')
	{
		ft_strdel(&env->line);
		return (OK);
	}
	ft_strdel(&env->line);
	return (KO);
}

int	skip_blank_lines(t_asm *env)
{
	int		ret;
	int		i;
	while ((ret = get_next_line(env->fd_s, &env->line)) > 0)
	{
		env->cur_x = 0;
		env->cur_y += 1;
		i = skip_whitespace(env->line, env, NO_UPDATE_X);
		if (env->line[i] == '\0')
		{
			ft_strdel(&env->line);
			continue ;
		}
		else
		{
			return (1);
		}
	}
	if (ret == -1)
		return (-1);
	return (0);
}
