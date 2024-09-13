NAME	= so_long

SRC_PATH = src/
OBJ_PATH = obj/
SRC 	= main.c utils.c errors.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ 	= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
HEADER = -I includes

LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft
PRINTF_FLAGS = -L $(LIBFT_PATH)/ft_printf -lftprintf

# INCLUDES = -I/usr/include -Imlx

MLX_PATH = ./minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS = -L ./minilibx-linux -lmlx -lmlx_Linux -L/usr/lib/X11 -lXext -lX11

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) $(PRINTF_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(MLX_LIB):
	make -C $(MLX_PATH)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

clean:
		make clean -C $(MLX_PATH)
		make clean -C $(LIBFT_PATH)
		rm -rf $(OBJ_PATH)

fclean: clean
		make fclean -C $(LIBFT_PATH)
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re