# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 17:50:35 by gpiriou           #+#    #+#              #
#    Updated: 2021/04/15 17:00:43 by gpiriou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

GCC		= gcc -Wall -Wextra -Werror

SRC		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_strchr.c ft_itoa.c\
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c\
ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_putstr_fd.c ft_strrchr.c\
ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_putnbr_fd.c ft_strmapi.c\
ft_substr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl_fd.c\
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstadd_back.c ft_lstmap.c\
ft_skip_whitespace.c ft_skip_non_printable.c ft_atoi_lu.c ft_free_tab.c\
ft_swap.c ft_strcat.c ft_free_all.c ft_len_n_base.c ft_len_n.c ft_islower.c\
ft_islower.c ft_isupper.c ft_strndup.c ft_itoa_base.c ft_valid_base.c\
ft_itoa_base_lu.c ft_print_address.c ft_print_list.c ft_word_count.c\
ft_putnbr_base.c ft_len_n_base_lu.c ft_len_n_base_ui.c ft_itoa_base_ui.c\
ft_itoa_ui.c ft_len_n_ui.c ft_str_toupper.c\

OBJ 	= $(SRC:.c=.o)

INC		= -I includes/

$(NAME): $(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)
%.o: %.c
				$(GCC) $(INC) -o $@ -c $?

all: $(NAME)

clean:
				rm -rf $(OBJ) ${OBJBONUS}
fclean: clean
				rm -rf $(NAME)
re: fclean all

.PHONY: clean fclean re
