NAME=			cub3D

CFLAGS= 		-Wall -Wextra -Werror -g3
INCLD=  		-I ./include/ -I ./minilibx-linux/

CYAN=                           \033[1;36m
GREEN=                          \033[1;32m
RESET=                          \033[0m

SRC_PATH= 		src
SRC_FILES=		main.c cleanup.c												\

PARS_PATH=		src/parsing
PARS_FILES=		checks_utils.c checks.c elem_utils.c flood_fill.c init_data.c	\
				map_utils.c pars_utils.c string_utils.c						\

EXEC_PATH=		src/exec
EXEC_FILES=		draw.c moves.c game.c init.c player.c minimap.c 		\
				raycasting.c textures.c events.c	\

LIBFT_PATH=    	./libft
MLX_PATH=		./minilibx-linux

LIBFT_FLAGS=	-L$(LIBFT_PATH) -lft
MLX_FLAGS =		-L$(MLX_PATH) -lmlx -lXext -lX11 -lm

LIBFT=        	$(LIBFT_PATH)/libft.a
MLX=			$(MLX_PATH)/libmlx.a

SRC=			$(SRC_PATH)/$(SRC_FILES)	\
				$(PARS_PATH)/$(PARS_FILES)	\
				$(EXEC_PATH)/$(EXEC_FILES)	\

OBJ_PATH= 		obj
OBJ= 			$(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))

NOPRINT=		--no-print-directory

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(OBJ_PATH)/%.o: $(PARS_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(OBJ_PATH)/%.o: $(EXEC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

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

copy_mlx:
		@cp -r ~/Documents/minilibx-linux minilibx-linux

.PHONY: all clean fclean re input
