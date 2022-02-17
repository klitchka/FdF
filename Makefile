# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 16:31:15 by aaparici          #+#    #+#              #
#    Updated: 2022/02/17 16:31:16 by aaparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
NAME := fdf

OPEN_GL := -framework OpenGl -framework Appkit
SRC_DIR := src/
OBJ_DIR := obj/
INC_DIR = inc/
LIBFT_DIR := libft/
MLX_DIR := minilibx_macos/ 
CFLAGS := -Wall -Wextra -Werror -O3 -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

FILES :=	fdf.c fdf_util.c read_map.c handle.c\
			 mouse.c color.c palette.c draw.c get_map.c\
			 plot.c plot_util.c rot.c apply.c zoom.c\
			 screen.c

HEADERS = color.h keys.h fdf.h

SRC := $(addprefix $(SRC_DIR), $(FILES))
OBJ := $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
INC = $(addprefix $(INC_DIR), $(HEADERS))

all:	$(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -lmlx -lm -lft -L $(LIBFT_DIR) -L $(MLX_DIR) $(OPEN_GL) -o $(NAME)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o  $@

.PHONY: all, clean, fclean, re

clean:
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -rf $(NAME)

re: fclean all
