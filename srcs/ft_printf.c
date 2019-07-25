/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:08:46 by skadogam          #+#    #+#             */
/*   Updated: 2019/02/22 12:49:35 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_check_flags(const char **format, t_buff **flags)
{
	*format += ft_flags(flags, *format, " -+0#");
	*format += ft_length(&(*flags)->width, *format, "0123456789");
	if (**format == '.')
		*format += ft_length(&(*flags)->precision, *format + 1, "0123456789-")
			+ 1;
	*format += ft_size(flags, *format, "hljz");
}

static void	ft_convert(const char **format, t_list **buff, va_list ap, int *len)
{
	t_list		*new;
	t_buff		*flags;
	static void	(*wut[58])(va_list ap, t_list **buff, t_buff **flags);

	if (wut[2] != ft_convert_wchar)
		ft_init_wut(wut);
	new = ft_lstnew(NULL, 0);
	ft_lstaddback(buff, new);
	flags = ft_buffnew();
	*format += 1;
	while (ft_strspn(*format, " -+#.0123456789hljz"))
		ft_check_flags(format, &flags);
	if (ft_isalpha(**format) && (*wut[(int)**format - 65]))
		(*wut[(int)**format - 65])(ap, &new, &flags);
	else if (**format == '%')
		ft_convert_percent(&new, &flags);
	else if (**format)
		ft_convert_char2(**format, &new, &flags);
	free(flags);
	flags = NULL;
	*len = ((int)new->content_size >= 0) ? *len + (int)new->content_size : -1;
	**format ? *format += 1 : 0;
}

static void	ft_convert_none(const char **format, t_list **buff, int *len)
{
	int		len1;
	size_t	len2;
	t_list	*new;

	new = ft_lstnew(NULL, 0);
	ft_lstaddback(buff, new);
	len1 = ft_strchr2(*format, '%');
	if (len1 >= 0)
	{
		new->content = ft_strnew(len1);
		ft_memcpy(new->content, *format, len1);
		new->content_size = len1;
		*format = *format + len1;
	}
	else
	{
		len2 = ft_strlen(*format);
		new->content = ft_strnew(len2);
		ft_memcpy(new->content, *format, len2);
		new->content_size = len2;
		*format = *format + len2;
	}
	*len += (int)new->content_size;
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	t_list	*buff;

	va_start(ap, format);
	len = 0;
	buff = NULL;
	while (*format && len != -1)
	{
		if (*format == '%')
		{
			ft_convert(&format, &buff, ap, &len);
			if (len != -1)
				ft_print_n_free(1, &buff);
		}
		else
			ft_convert_none(&format, &buff, &len);
	}
	if (len != -1)
		ft_print_n_free(1, &buff);
	va_end(ap);
	return (len);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		len;
	t_list	*buff;

	if (fd < 0)
		return (-1);
	va_start(ap, format);
	len = 0;
	buff = NULL;
	while (*format && len != -1)
	{
		if (*format == '%')
		{
			ft_convert(&format, &buff, ap, &len);
			if (len != -1)
				ft_print_n_free(fd, &buff);
		}
		else
			ft_convert_none(&format, &buff, &len);
	}
	if (len != -1)
		ft_print_n_free(fd, &buff);
	va_end(ap);
	return (len);
}
