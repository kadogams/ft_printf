# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 15:03:00 by skadogam          #+#    #+#              #
#    Updated: 2019/07/25 17:15:42 by skadogam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

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
	ft_abs.c\
	ft_atoi.c\
	ft_atoi_base.c\
	ft_atoimax_base.c\
	ft_bzero.c\
	ft_dlstadd.c\
	ft_dlstaddback.c\
	ft_dlstdel.c\
	ft_dlstdelone.c\
	ft_dlstnew.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isblank.c\
	ft_isdigit.c\
	ft_islower.c\
	ft_isprint.c\
	ft_ispunct.c\
	ft_isspace.c\
	ft_isupper.c\
	ft_itoa.c\
	ft_itoa_base.c\
	ft_jtoa_base.c\
	ft_jutoa_base.c\
	ft_lltoa_base.c\
	ft_llutoa_base.c\
	ft_lstadd.c\
	ft_lstaddback.c\
	ft_lstdel.c\
	ft_lstdel2.c\
	ft_lstdelone.c\
	ft_lstdelone2.c\
	ft_lstiter.c\
	ft_lstlen.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_ltoa_base.c\
	ft_lutoa_base.c\
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp_zero.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memcpy_back.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memset.c\
	ft_memset_back.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_sqrt.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strchr2.c\
	ft_strclr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin_free_s1.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strrev.c\
	ft_strsplit.c\
	ft_strspn.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_utoa_base.c\
	ft_wstrlen.c\
	get_next_line.c\
	get_next_line_v2.c

SRCS_DIR = srcs

SRCS_DIR_LIBFT = $(LIBFT)/srcs

SRCS = $(addprefix $(SRCS_DIR_LIBFT)/,$(IN_LIBFT)) $(addprefix $(SRCS_DIR)/,$(IN_PRINTF))

OUT_DIR = tmp

OBJS = $(addprefix $(OUT_DIR)/,$(IN_LIBFT:.c=.o)) $(addprefix $(OUT_DIR)/,$(IN_PRINTF:.c=.o))

all: $(NAME)

$(NAME): cp_headers $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[32mOutfile LIBFTPRINTF	[ ✔ ]\e[0m"

$(OUT_DIR)/%.o: $(SRCS_DIR_LIBFT)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(OUT_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

cp_headers:
	@/bin/cp $(LIBFT)/$(HEADERS)/*.h $(HEADERS)

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf $(OUT_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
