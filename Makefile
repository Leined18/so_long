NAME        = so_long
CC          = gcc
CFLAGS      = -Wextra -Werror -Wall -fsanitize=address -g3 -I$(INC) -I$(LIBFT_DIR)inc/ -I$(MLX_DIR)
LDFLAGS     = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX) $(MLX_LINUX) -lX11 -lXext -lm -lbsd

INC         = inc/
map        = assets/maps

LIBFT_DIR   = libft/
LIBFT       = $(LIBFT_DIR)libft.a

MLX_DIR     = mlx/
MLX         = $(MLX_DIR)libmlx.a
MLX_LINUX   = $(MLX_DIR)libmlx_Linux.a

SRCS_DIR    = srcs/
OBJS_DIR    = objs/

SRCS_FILES  = main.c ft_read_map.c ft_check_map.c ft_init.c ft_load.c ft_load_animation.c \
			  ft_free.c ft_finish.c ft_draw_map.c ft_move_key.c ft_map_is_posible.c \
			  ft_allocate.c ft_lists.c ft_animate.c


OBJS_FILES  = $(SRCS_FILES:.c=.o)

SRCS        = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS        = $(addprefix $(OBJS_DIR), $(OBJS_FILES))

# Colors
BOLD_BLACK   = \033[1;30m
BOLD_RED     = \033[1;31m
BOLD_GREEN   = \033[1;32m
BOLD_YELLOW  = \033[1;33m
BOLD_BLUE    = \033[1;34m
BOLD_PURPLE  = \033[1;35m
BOLD_CYAN    = \033[1;36m
BOLD_WHITE   = \033[1;37m

BLACK        = \033[0;30m
RED          = \033[0;31m
GREEN        = \033[0;32m
YELLOW       = \033[0;33m
BLUE         = \033[0;34m
PURPLE       = \033[0;35m
CYAN         = \033[0;36m
WHITE        = \033[0;37m

GRAY         = \033[0;90m
LIGHT_RED    = \033[0;91m
LIGHT_GREEN  = \033[0;92m
LIGHT_YELLOW = \033[0;93m
LIGHT_BLUE   = \033[0;94m
LIGHT_PURPLE = \033[0;95m
LIGHT_CYAN   = \033[0;96m
LIGHT_WHITE  = \033[0;97m

NO_COLOR     = \033[0m
DEF_COLOR    = \033[0;39m


all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "\nCompiling $(BLUE)$(NAME)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "\33[2K\r$(GRAY)$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)$(DEF_COLOR)"
	@echo "\n$(GREEN)$(NAME) compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)\n------------\n| Done! 👌 |\n------------\$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@[ -d $(OBJS_DIR) ] || mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K\r$(GRAY)$(CC) $(CFLAGS) -c $< -o $@$(DEF_COLOR)"

$(LIBFT):
	@echo "\nCompiling $(BLUE)libft$(DEF_COLOR)"
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "\nCompiling $(BLUE)mlx$(DEF_COLOR)"
	@make -C $(MLX_DIR)

run: $(NAME)
	@if [ -z "$(MAP)" ]; then \
		echo "$(BOLD_RED)Error$(DEF_COLOR): $(LIGHT_WHITE)Debes especificar el nombre del mapa con MAP=nombre_del_mapa $(DEF_COLOR)"; \
	else \
		./$(NAME) $(map)/$(MAP); \
	fi

clean:
	rm -rf $(OBJS_DIR)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME) test
	@echo "$(GREEN)$(NAME)$(YELLOW) cleaned$(DEF_COLOR)"

re: fclean all 

.PHONY: all clean fclean re map1
.SILENT: all clean fclean
