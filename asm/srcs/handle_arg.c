/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 09:03:47 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/19 11:33:58 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//TODO int max atoiv2?
int		atoi_v2(char *str, int *nb, t_asm *env)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	if (str[i] == '-')
	{
		i++;
		env->cur_x += 1;
		neg = -1;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		*nb = *nb * 10 + str[i] - '0';
		env->cur_x +=1;
		i++;
	}
	i += skip_whitespace(str + i, env, NO_UPDATE_X);
	if (str[i] == '\0' || str[i] == ',')
		return (OK);
	return (KO);
}

int		get_reg(t_asm *env, t_arg *arg, char *line)
{
	ft_printf("Get_reg\n");
	if (arg->nb_arg == 3)
		return (KO);
	arg->type[arg->nb_arg] = REG_CODE;
	if (!atoi_v2(line, &arg->value[arg->nb_arg], env))
		return (KO);
	arg->nb_arg++;
	return (OK);
}

int		get_dir(t_asm *env, t_arg *arg, char *line)
{
	ft_printf("get dir\n");
	if (arg->nb_arg == 3)
		return (KO);
	arg->type[arg->nb_arg] = DIR_CODE;
	arg->nb_arg++;
	if (line[0] == LABEL_CHAR)
		return (create_label_arg(env, arg, line + 1));
	ft_printf("NB AAARAG = %d\n", arg->nb_arg);
	return (atoi_v2(line, &arg->value[arg->nb_arg - 1], env));
}

int		get_ind(t_asm *env, t_arg *arg, char *line)
{
	ft_printf("get ind\n");
	if (arg->nb_arg == 3)
		return (KO);
	arg->type[arg->nb_arg] = IND_CODE;
	arg->nb_arg++;
	if (line[0] == LABEL_CHAR)
		return (create_label_arg(env, arg, line + 1));
	return (atoi_v2(line, &arg->value[arg->nb_arg - 1], env));
}

int		handle_arg(t_asm *env, t_arg *arg, int a, char *line)
{
	int	ret;
	int	i;

	i = 0;
	ft_printf("\nHandle_arg line = %s\n\n", line);
	while (line[i])
	{
		if ((ret = skip_whitespace(line + i, env, UPDATE_X)) == -1)
			return (KO);
		i += ret;
		if (line[i] == DIRECT_CHAR)
			ret = get_dir(env, arg, line + i + 1);
		else if (line[i] == LABEL_CHAR || ft_isdigit(line[i]) || line[i] == '-')
			ret = get_ind(env, arg, line + i);
		else if (line[i] == 'r')
			ret = get_reg(env, arg, line + i + 1);
		else
			return (KO);
		if (ret == KO)
			return (KO);
		while (line[i] && line[i] != SEPARATOR_CHAR)
			i++;
		if (line[i] == SEPARATOR_CHAR)
			i++;
	}
	return (OK);
}
