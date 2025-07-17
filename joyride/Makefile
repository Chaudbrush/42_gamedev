# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 17:09:05 by vloureir          #+#    #+#              #
#    Updated: 2025/07/15 14:03:27 by vloureir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --silent
endif

NAME := joyride

SRC := src/enemy.c src/exit_and_free.c src/fps.c src/ft_memset.c \
		src/img_init_1.c src/img_init_2.c src/img_utils.c src/initial_init.c \
		src/keys.c src/main.c src/render.c src/reset.c src/score_game.c \
		src/score_io.c src/score_vars.c

OBJ := $(SRC:.c=.o)

INC := -Iincludes

HEADER := includes/joyride.h

CFLAGS := -Wall -Wextra -Werror

LFLAGS := -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm

REPO := https://github.com/42paris/minilibx-linux.git

MLX_DIR := ./minilibx-linux/

CC := cc

RM := rm -f

SCORE := score.txt

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
	$(RM) $(SCORE)
	rm -rf $(MLX_DIR)
	@echo "$(RED) Minilibx Deleted $(OFF)"

re: fclean all

.PHONY: all clean fclean re del mlx