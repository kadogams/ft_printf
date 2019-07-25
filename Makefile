# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 15:03:00 by skadogam          #+#    #+#              #
#    Updated: 2019/07/14 18:22:35 by kadogams         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADERS = includes

INC = -I $(HEADERS)

IN_PRINTF =\
	ft_convert_char.c\
	ft_convert_nbr.c\
	ft_convert_size.c\
	ft_convert_type.c\
	ft_convert_type2.c\
	ft_convert_wchar_v2.c\
	ft_flags.c\
	ft_init_stuff.c\
	ft_print_n_free.c\
	ft_printf.c

IN_LIBFT =\
	ft_bzero.c\
	ft_isalpha.c\
	ft_itoa_base.c\
	ft_jtoa_base.c\
	ft_jutoa_base.c\
	ft_lltoa_base.c\
	ft_llutoa_base.c\
	ft_lstaddback.c\
	ft_lstnew.c\
	ft_ltoa_base.c\
	ft_lutoa_base.c\
	ft_memalloc.c\
	ft_memcpy.c\
	ft_memcpy_back.c\
	ft_memdel.c\
	ft_memset.c\
	ft_strchr2.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strlen.c\
	ft_strnew.c\
	ft_strspn.c\
	ft_utoa_base.c\
	ft_wstrlen.c

PRINTF_DIR = srcs_printf

LIBFT_DIR = srcs_libft

SRCS = $(addprefix $(LIBFT_DIR)/,$(IN_LIBFT)) $(addprefix $(PRINTF_DIR)/,$(IN_PRINTF))

OUT_DIR = tmp

OBJS = $(addprefix $(OUT_DIR)/,$(IN_LIBFT:.c=.o)) $(addprefix $(OUT_DIR)/,$(IN_PRINTF:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[32mOutfile LIBFTPRINTF	[ ✔ ]\e[0m"

$(OUT_DIR)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(OUT_DIR)/%.o: $(PRINTF_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf $(OUT_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
