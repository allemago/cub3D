# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 13:16:26 by magrabko          #+#    #+#              #
#    Updated: 2025/03/20 17:34:08 by magrabko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=			cub3D

CFLAGS= 		-Wall -Wextra -Werror -g3
INCLD=  		-I ./include/ -I ./minilibx-linux/

CYAN=                           \033[1;36m
GREEN=                          \033[1;32m
RESET=                          \033[0m

SRC_PATH= 		src
SRC_FILES=		main.c cleanup.c

PARS_PATH=		src/parsing
PARS_FILES=		checks_utils.c checks.c elem_utils.c flood_fill.c map_utils.c 	\
				pars_init.c pars_utils.c string_utils.c							\

EXEC_PATH=		src/exec
EXEC_FILES=		exec.c draw.c mlx.c init.c

LIBFT_PATH=    	./libft
MLX_PATH=		./minilibx-linux

LIBFT_FLAGS=	-L$(LIBFT_PATH) -lft
MLX_FLAGS =		-L$(MLX_PATH) -lmlx -lXext -lX11

LIBFT=        	$(LIBFT_PATH)/libft.a
MLX= 			$(MLX_PATH)/libmlx_Linux.a 
GCL= 			git clone
MLX_URL= 		https://github.com/42Paris/minilibx-linux.git

SRC=			$(SRC_PATH)/$(SRC_FILES)	\
				$(PARS_PATH)/$(PARS_FILES)	\
				$(EXEC_PATH)/$(EXEC_FILES)	\

OBJ_PATH= 		obj
OBJ= 			$(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))

NOPRINT=		--no-print-directory

all: $(MLX_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(OBJ_PATH)/%.o: $(PARS_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(OBJ_PATH)/%.o: $(EXEC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(MLX_PATH):
	@$(GCL) $(MLX_URL) > /dev/null 2>&1
	@$(MAKE) -C $@ > /dev/null 2>&1

$(MLX):
	@$(MAKE) -C $(MLX_PATH) > /dev/null 2>&1

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null 2>&1

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	@$(CC) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@printf "\n${CYAN}"
	@printf "  ░█▀▀░█░█░█▀▄░▀▀█░█▀▄\n"
	@printf "  ░█░░░█░█░█▀▄░░▀▄░█░█\n"
	@printf "  ░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░\n"
	@printf "\n\n${RESET}"

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean > /dev/null
	@$(MAKE) -C $(MLX_PATH) clean > /dev/null
	@printf "\n\n${GREEN}"
	@printf "  ░█▀▀░█░░░█▀▀░█▀█░█▀█░█░█░█▀█░░█\n"
	@printf "  ░█░░░█░░░█▀▀░█▀█░█░█░█░█░█▀▀░░▀\n"
	@printf "  ░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀▀▀░▀░░░░▀\n"
	@printf "\n\n${RESET}"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(MLX_PATH)
	@$(MAKE) -C $(LIBFT_PATH) fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re
