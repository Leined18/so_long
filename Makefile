NAME	= so_long
MAKEFLAGS += --no-print-directory

CC		= cc
CCFLAGS = -Wextra -Werror -Wall -fsanitize=address -g3 -I $(INC) -I $(LIBFT_DIR)inc/ -I $(MLX_DIR)
MLXFLAG = -lmlx -lXext -lX11

INC = inc/
Map = assets/maps/mapa1.ber

#libft
LIBFT_DIR	= libft/
LIBFT	= $(LIBFT_DIR)libft.a

#mlx
MLX_DIR		= mlx/
MLX		= $(MLX_DIR)libmlx.a
MLX_LINUX = $(MLX_DIR)libmlx_Linux.a

#srcs#objs
SRCS_DIR	= srcs/
OBJS_DIR	= objs/

SRCS_FILES	= main.c read_map.c check_map.c finish.c draw_map.c move_key.c
OBJS_FILES = $(SRCS_FILES:.c=.o)

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		= $(addprefix $(OBJS_DIR), $(OBJS_FILES))

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
	$(CC) $(CCFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX) $(MLX_LINUX) -lX11 -lXext -o $(NAME)
	printf "\33[2K\r$(GRAY)$(CC) $(CCFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX) $(MLX_LINUX) -lX11 -lXext -o $(NAME)"
	@echo "\n$(GREEN)$(NAME) compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)\n------------\n| Done! 👌 |\n------------\$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	[ -d $(OBJS_DIR) ] | mkdir -p $(OBJS_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@
	@printf "\33[2K\r$(GRAY)$(CC) $(CCFLAGS) -c $< -o $@$(DEF_COLOR)"

$(LIBFT):
	@echo "\nCompiling $(BLUE)libft$(DEF_COLOR)"
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "\nCompiling $(BLUE)mlx$(DEF_COLOR)"
	@make -C $(MLX_DIR)

exe:
	./$(NAME) $(Map)

clean:
	rm -rf $(OBJS_DIR)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	echo "$(GREEN)$(NAME)$(YELLOW) cleaned\n$(DEF_COLOR)"

re: all fclean

.SILENT: all clean fclean
