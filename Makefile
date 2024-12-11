# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eanne <eanne@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 13:09:18 by cauvray           #+#    #+#              #
#    Updated: 2024/12/11 20:55:07 by eanne            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRC_DIR	= srcs
OBJ_DIR	= objs
INC_DIR	= includes

_SRCS = main.c verif.c utils.c stack.c
SRCS = $(addprefix $(SRC_DIR)/, $(_SRCS))

_OBJS = $(_SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/,$(_OBJS))

# Path to libft library
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:	fclean all

bonus: re

test: all
	./$(NAME)

.PHONY:	all clean fclean re bonus test