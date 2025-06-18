# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 10:15:23 by vloureir          #+#    #+#              #
#    Updated: 2025/06/13 22:45:46 by vloureir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --silent
endif

NAME := pong

SRC  := src/main.c src/errors.c src/render_base.c src/render_movable.c \
		src/utils.c	src/control_check.c src/score_low.c src/score_high.c \
		src/score_check.c

OBJ := $(SRC:.c=.o)

INC := -Iincludes

HEADER := includes/pong.h

CFLAGS := -Wall -Wextra -Werror -g

LFLAGS := -Lminilibx-linux/ -lmlx_Linux -lXext -lX11 -lm

REPO := https://github.com/42paris/minilibx-linux.git

MLX_DIR := ./minilibx-linux/

CC := cc

RM := rm -f

RED := \033[1;30;41m

GREEN := \033[1;30;42m

OFF := \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(MAKE) -C $(MLX_DIR)
	@echo "$(GREEN) Minilibx Compiled $(OFF)"
	$(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -o $(NAME) $(INC)
	@echo "$(GREEN) Executable Created $(OFF)"

mlx:
	git clone $(REPO)

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	@echo "$(RED) Executable Deleted $(OFF)"

del: fclean
	rm -rf $(MLX_DIR)
	@echo "$(RED) Minilibx Deleted $(OFF)"

re: fclean all

.PHONY: all clean fclean re del mlx