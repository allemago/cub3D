# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 12:34:41 by magrabko          #+#    #+#              #
#    Updated: 2025/02/11 14:08:45 by magrabko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=			cub3D

CFLAGS= 		-Wall -Wextra -Werror -g3
INCLD=  		-I ./include/ -I ./minilibx-linux/

CYAN=                           \033[1;36m
GREEN=                          \033[1;32m
RESET=                          \033[0m

SRC_PATH= 		src
OBJ_PATH= 		obj

LIBFT_PATH=    	./libft
MLX_PATH=		./minilibx-linux

LIBFT_FLAGS=	-L$(LIBFT_PATH) -lft
MLX_FLAGS =		-L$(MLX_PATH) -lmlx -lXext -lX11

LIBFT=        	$(LIBFT_PATH)/libft.a
MLX=			$(MLX_PATH)/libmlx.a

SRC=			$(SRC_PATH)/main.c				\

OBJ= 			$(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))

NOPRINT=		--no-print-directory

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	@$(MAKE) -s $(NOPRINT) -C $(MLX_PATH) > /dev/null 2>&1

$(LIBFT):
	@$(MAKE) $(NOPRINT) -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	@$(CC) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@printf "\n${CYAN}"
	@printf "  ░█▀▀░█░█░█▀▄░▀▀█░█▀▄\n"
	@printf "  ░█░░░█░█░█▀▄░░▀▄░█░█\n"
	@printf "  ░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░\n"
	@printf "\n\n${RESET}"

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) $(NOPRINT) -C $(LIBFT_PATH) clean
	@$(MAKE) $(NOPRINT) -C $(MLX_PATH) clean > /dev/null
	@printf "\n\n${GREEN}"
	@printf "  ░█▀▀░█░░░█▀▀░█▀█░█▀█░█░█░█▀█░░█\n"
	@printf "  ░█░░░█░░░█▀▀░█▀█░█░█░█░█░█▀▀░░▀\n"
	@printf "  ░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀▀▀░▀░░░░▀\n"
	@printf "\n\n${RESET}"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) $(NOPRINT) -C $(LIBFT_PATH) fclean

re: fclean all

input:
		@echo "\n\033[1;32m NORMAL INPUT TEST\033[0;33m"
		@echo "./so_long maps/valid/*.ber"
		@echo "\n\033[1;38;5;202m ERROR TESTS\033[0;33m"
		@echo "./so_long"
		@echo "./so_long map.txt"
		@echo "./so_long maps/invalid/*.ber"
		@echo "\n\033[1;32m VALGRIND TEST\033[0;33m"
		@echo "valgrind --leak-check=full ./so_long maps/valid/*.ber\n"

copy_mlx:
		@cp -r ~/Documents/minilibx-linux minilibx-linux

.PHONY: all clean fclean re input
