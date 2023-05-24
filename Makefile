# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 17:50:35 by gpiriou           #+#    #+#              #
#    Updated: 2023/03/09 16:43:35 by glpiriou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDE = -I includes/

SRC_DIR = src

RM = rm -f

NAME = push_swap

# Colors
GREEN=\033[0;32m
RED=\033[0;31m
PINK=\033[0;35m
END=\033[0m

SRC = $(shell find $(SRC_DIR) -type f -name *.c)

OBJ = $(SRC:.c=.o)

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "$(GREEN) ==== Project compiled ==== $(END)"

all :	$(NAME)

clean :
	@$(RM) $(OBJ) $(OBJ_B)
	@echo "$(RED) ==== All object removed ==== $(END)"

fclean :	clean
	@$(RM) $(NAME) $(NAME_B)
	@echo "$(PINK) ==== Executables removed ==== $(END)"

re :	fclean all

.PHONY : all clean fclean re