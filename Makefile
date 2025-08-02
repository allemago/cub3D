################################### SETTINGS ###################################

NAME=				cub3D

CFLAGS= 			-Wall -Wextra -Werror -g3

INCLD=  			-I ./include/ -I ./minilibx-linux/

CYAN=				\033[1;36m
GREEN=				\033[1;32m
RESET=				\033[0m
NOPRINT=			--no-print-directory

##################################### PATHS #####################################

SRC_PATH= 			src
PARS_PATH=			src/parsing
EXEC_PATH=			src/exec
MANDATORY_PATH=		$(EXEC_PATH)/mandatory
BONUS_PARS_PATH=	$(PARS_PATH)/bonus
BONUS_EXEC_PATH=	$(EXEC_PATH)/bonus

################################### SRC FILES ###################################

SRC_FILES=			cleanup.c													\

PARS_FILES=			checks_utils.c checks.c elem_utils.c flood_fill.c			\
					init_data.c map_utils.c pars_utils.c string_utils.c			\
					
EXEC_FILES=			draw.c events.c moves.c player.c raycasting.c				\
					textures.c init_exec.c										\
					
MANDATORY_FILES= 	game.c main.c  												\

BONUS_EXEC_FILES=	game_bonus.c main_bonus.c minimap_bonus.c init_bonus.c		\
					hand_bonus.c animation_bonus.c destroy_bonus.c				\

BONUS_PARS_FILES=	checks_bonus.c												\

################################### LIBRARIES ###################################

MLX_REPO=			https://github.com/42paris/minilibx-linux.git

LIBFT_PATH=    		./libft
MLX_PATH=			./minilibx-linux

LIBFT_FLAGS=		-L$(LIBFT_PATH) -lft
MLX_FLAGS =			-L$(MLX_PATH) -lmlx -lXext -lX11 -lm

LIBFT=        		$(LIBFT_PATH)/libft.a
MLX=				$(MLX_PATH)/libmlx.a

################################# SRC FILE LISTS ################################

SRC_MANDATORY=		$(MANDATORY_PATH)/$(MANDATORY_FILES)						\
					$(SRC_PATH)/$(SRC_FILES)									\
					$(PARS_PATH)/$(PARS_FILES)									\
					$(EXEC_PATH)/$(EXEC_FILES)									\

SRC_BONUS=			$(BONUS_PARS_PATH)/$(BONUS_PARS_FILES)						\
					$(BONUS_EXEC_PATH)/$(BONUS_EXEC_FILES)						\
					$(SRC_PATH)/$(SRC_FILES)									\
					$(PARS_PATH)/$(PARS_FILES)									\
					$(EXEC_PATH)/$(EXEC_FILES)									\

################################### OBJ FILES ###################################

OBJ_PATH= 			obj

OBJ_MANDATORY= 		$(addprefix $(OBJ_PATH)/, $(notdir $(SRC_MANDATORY:.c=.o)))
OBJ_BONUS=			$(addprefix $(OBJ_PATH)/, $(notdir $(SRC_BONUS:.c=.o)))

################################# MAIN TARGETS ##################################

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(OBJ_PATH)/%.o: $(PARS_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(OBJ_PATH)/%.o: $(EXEC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(OBJ_PATH)/%.o: $(MANDATORY_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(OBJ_PATH)/%.o: $(BONUS_PARS_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

$(OBJ_PATH)/%.o: $(BONUS_EXEC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLD) -c $< -o $@

############################### SETUP LIBRARIES #################################

$(MLX):
	@rm -rf $(MLX_PATH)
	@git clone $(MLX_REPO) $(MLX_PATH) > /dev/null 2>&1
	@$(MAKE) -s -C $(MLX_PATH) > /dev/null 2>&1

$(LIBFT):
	@$(MAKE) $(NOPRINT) -C $(LIBFT_PATH)
	
################################# BUILD PROJECT #################################

$(NAME): $(OBJ_MANDATORY) $(MLX) $(LIBFT)
	@$(CC) $(OBJ_MANDATORY) -o $(NAME) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@printf "\n${CYAN}"
	@printf "  ░█▀▀░█░█░█▀▄░▀▀█░█▀▄\n"
	@printf "  ░█░░░█░█░█▀▄░░▀▄░█░█\n"
	@printf "  ░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░\n"
	@printf "\n\n${RESET}"

################################# CLEAN TARGETS #################################

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) $(NOPRINT) -C $(LIBFT_PATH) clean
	@if [ -d $(MLX_PATH) ]; then $(MAKE) -C $(MLX_PATH) clean > /dev/null; fi
	@printf "\n\n${GREEN}"
	@printf "  ░█▀▀░█░░░█▀▀░█▀█░█▀█░█░█░█▀█░░█\n"
	@printf "  ░█░░░█░░░█▀▀░█▀█░█░█░█░█░█▀▀░░▀\n"
	@printf "  ░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀▀▀░▀░░░░▀\n"
	@printf "\n\n${RESET}"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf minilibx-linux
	@$(MAKE) $(NOPRINT) -C $(LIBFT_PATH) fclean

re: fclean all

################################# BONUS TARGET #################################

bonus:
	@$(MAKE) re > /dev/null
	@$(MAKE) $(MLX) $(LIBFT) $(OBJ_BONUS) > /dev/null
	@$(CC) $(OBJ_BONUS) -o $(NAME) $(MLX_FLAGS) $(LIBFT_FLAGS)
	@printf "\n${CYAN}"
	@printf "  ░█▀▄░█▀█░█▀█░█░█░█▀▀\n"
	@printf "  ░█▀▄░█░█░█░█░█░█░▀▀█\n"
	@printf "  ░▀▀░░▀▀▀░▀░▀░▀▀▀░▀▀▀\n"
	@printf "\n\n${RESET}"

##################################### TESTS ####################################

test: re
	./cub3D maps/map_ok.cub

test_bonus: bonus
	./cub3D maps/map_ok_bonus.cub

valgrind: re
	valgrind --tool=memcheck --track-origins=yes ./cub3D maps/OK/map_ok1.cub

valgrind_bonus: bonus
	valgrind --tool=memcheck --track-origins=yes ./cub3D maps/OK/map_ok1_bonus.cub

##################################### PHONY ####################################

.PHONY: all clean fclean re bonus
