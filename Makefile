NAME	= so_long

LIBFT	= libft.a
MLX		= libmlx.a
MLX_LINUX = libmlx_Linux.a


CC		= cc
CCFLAGS = -Wextra -Werror -Wall -fsanitize=address -g3 -I $(INC) -I $(LIBFT_DIR)inc/ -I $(MLX_DIR)
MLXFLAG = -lmlx -lXext -lX11

INC = inc/

LIBFT_DIR	= $(INC)libft/
MLX_DIR		= $(INC)minilibx-linux/
SRCS_DIR	= srcs/
OBJS_DIR	= objs/

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		= $(addprefix $(OBJS_DIR), $(OBJS_FILES))

SRCS_FILES	= main.c
OBJS_FILES = $(SRCS_FILES:.c=.o)

# Colors

BOLD_PURPLE	= \033[1;35m
BOLD_CYAN	= \033[1;36m
BOLD_YELLOW	= \033[1;33m
NO_COLOR	= \033[0m
DEF_COLOR 	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE		= \033[0;97m


all: $(NAME)

$(NAME) :	$(LIBFT) $(MLX) $(OBJS)
	echo "\nCompiling $(BLUE)$(NAME)$(DEF_COLOR)"
	$(CC) $(MLXFLAGS) $(CFLAGS) $(LIBFT_DIR)$(LIBFT) $(MLX_DIR)$(MLX) $(MLX_DIR)$(MLX_LINUX) $(OBJS) -o $(NAME)
	echo "$(BLUE)\n------------\n| Done! 👌 |\n------------\$(DEF_COLOR)"


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	[ -d $(OBJS_DIR) ] | mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	printf "\33[2K\r$(GRAY)$(CC) $(CFLAGS) -c $< -o $@$(DEF_COLOR)"


$(LIBFT):
	echo "\nCompiling $(BLUE)libft$(DEF_COLOR)"
	make -C $(LIBFT_DIR)


$(MLX):
	echo "\nCompiling $(BLUE)mlx$(DEF_COLOR)"
	make -C $(MLX_DIR)


clean:
	rm -rf $(OBJS_DIR)
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)

re: all fclean
