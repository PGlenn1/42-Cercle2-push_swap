# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 17:50:35 by gpiriou           #+#    #+#              #
#    Updated: 2023/05/25 18:50:15 by glpiriou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

GCC		= gcc -Wall -Wextra -Werror

SRC		= bubble_sort.c ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c is_number.c ft_isdigit.c ft_isprint.c ft_is_whitespace.c ft_strchr.c ft_itoa.c\
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c\
ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_putstr_fd.c ft_strrchr.c\
ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_putnbr_fd.c ft_strmapi.c\
ft_substr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl_fd.c\
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstadd_back.c ft_lstmap.c\

OBJ 	= $(SRC:.c=.o)

INC		= -I includes/

$(NAME): $(OBJ)
				ar rcs $(NAME) $(OBJ)
%.o: %.c
				$(GCC) $(INC) -o $@ -c $?

all: $(NAME)

clean:
				rm -rf $(OBJ)
fclean: clean
				rm -rf $(NAME)
re: fclean all

.PHONY: clean fclean re
