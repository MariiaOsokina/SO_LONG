NAME	= so_long
NAME_BONUS	= so_long_bonus

SRC_PATH = src/
OBJ_PATH = obj/
SRC = main.c utils.c end_of_game.c end_of_game_2.c check_valid_map.c check_valid_map_2.c \
      check_path.c init_data.c place_sprites.c key_hook.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ 	= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
HEADER_FILE = src/so_long.h

SRC_PATH_BONUS = src_bonus/
OBJ_PATH_BONUS = obj_bonus/
SRC_BONUS 	= check_path_bonus.c check_valid_map_2_bonus.c check_valid_map_bounus.c \
            end_of_game_bonus.c end_of_game_2_bonus.c init_data_bonus.c key_hook_2_bonus.c \
            key_hook_3_bonus.c key_hook_bonus.c main_bonus.c \
            place_sprites_bonus.c utils_bonus.c
SRCS_BONUS	= $(addprefix $(SRC_PATH_BONUS), $(SRC_BONUS))
OBJ_BONUS 	= $(SRC_BONUS:.c=.o)
OBJS_BONUS	= $(addprefix $(OBJ_PATH_BONUS), $(OBJ_BONUS))
HEADER_FILE_BONUS = src_bonus/so_long_bonus.h
OBJS_BONUS	= $(addprefix $(OBJ_PATH_BONUS), $(OBJ_BONUS))

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror -g
HEADER = -I includes

LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft
PRINTF_FLAGS = -L $(LIBFT_PATH)/ft_printf -lftprintf

MLX_PATH = ./minilibx
MLX_LIB = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS = -L ./minilibx -lmlx -lmlx_Linux -L/usr/lib/X11 -lXext -lX11

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) $(PRINTF_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER_FILE)
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME_BONUS):	$(MLX_LIB) $(LIBFT_LIB) $(NAME_BONUS)

bonus: $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(MLX_FLAGS) $(PRINTF_FLAGS) $(LIBFT_FLAGS) -o $(NAME_BONUS)

$(OBJ_PATH_BONUS)%.o: $(SRC_PATH_BONUS)%.c $(HEADER_FILE_BONUS)
	mkdir -p $(OBJ_PATH_BONUS)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(MLX_LIB):
	make -C $(MLX_PATH)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

clean:
		make clean -C $(MLX_PATH)
		make clean -C $(LIBFT_PATH)
		rm -rf $(OBJ_PATH) $(OBJ_PATH_BONUS)

fclean: clean
		make fclean -C $(LIBFT_PATH)
		rm -f $(NAME) $(NAME_BONUS)

re:		fclean all

.PHONY: all clean fclean re