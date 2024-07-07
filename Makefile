# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 12:15:37 by danpalac          #+#    #+#              #
#    Updated: 2024/07/07 22:47:00 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================COLORS=============================================#
BOLD_BLACK		:= \033[1;30m
BOLD_RED		:= \033[1;31m
BOLD_GREEN		:= \033[1;32m
BOLD_YELLOW		:= \033[1;33m
BOLD_BLUE		:= \033[1;34m
BOLD_PURPLE		:= \033[1;35m
BOLD_CYAN		:= \033[1;36m
BOLD_WHITE		:= \033[1;37m
BLACK			:= \033[0;30m
RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
WHITE			:= \033[0;37m
GRAY			:= \033[0;90m
LIGHT_RED		:= \033[0;91m
LIGHT_GREEN		:= \033[0;92m
LIGHT_YELLOW	:= \033[0;93m
LIGHT_BLUE		:= \033[0;94m
LIGHT_PURPLE	:= \033[0;95m
LIGHT_CYAN		:= \033[0;96m
LIGHT_WHITE		:= \033[0;97m
NO_COLOR		:= \033[0m
DEF_COLOR		:= \033[0;39m

#==============================VARIABLES=============================================#

NAME	= so_long
BONUS_NAME = so_long_bonus
LIBFT	= $(LIBFT_DIR)libft.a
MLX		= $(MLX_DIR)libmlx.a
MLX_LINUX	= $(MLX_DIR)libmlx_Linux.a

#===============================COMPILER============================================#

CC		= gcc
CFLAGS	= -Wextra -Werror -Wall -g3 -fsanitize=address
LDFLAGS	= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX) $(MLX_LINUX) -lX11 -lXext -lm -lbsd
MKDIR	= mkdir -p
IFLAGS	= -I$(INC) -I$(LIBFT_INC) -I$(MLX_DIR)

#==============================DIRECTORIES============================================#

SRCS_DIR		:= srcs/
OBJS_DIR		:= obj/
LIBFT_DIR		:= libft/
MLX_DIR			:= mlx/
MAP_DIR			:= map/
GRAFIC_DIR		:= grafic/
HOOK_DIR		:= hook/
BONUS_DIR		:= bonus/
RENDER_DIR		:= render/
INC				:= inc/
LIBFT_INC		:= $(LIBFT_DIR)inc/
MAPS			:= assets/maps

#==============================SOURCES============================================#

MAP_FILES		:= ft_check_map ft_draw_map ft_map_is_posible ft_read_map
RENDER_FILES	:= ft_init ft_load ft_free main
GRAFIC_FILES	:= ft_get_frame ft_get_info ft_spritesheet
HOOK_FILES		:= ft_finish ft_move_key
BONUS_FILES		:= ft_animate_bonus ft_init_bonus ft_draw_bonus ft_checks_bonus\
					ft_hook_bonus\

# ==============================FILES============================================#

SRCS_FILES+=$(addprefix $(MAP_DIR), $(MAP_FILES))
SRCS_FILES+=$(addprefix $(RENDER_DIR), $(RENDER_FILES))
SRCS_FILES+=$(addprefix $(GRAFIC_DIR), $(GRAFIC_FILES))
SRCS_FILES+=$(addprefix $(HOOK_DIR), $(HOOK_FILES))
BONUS_SRCS_FILES+=$(addprefix $(BONUS_DIR), $(BONUS_FILES))

SRCS		:= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		:= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

BONUS_SRCS  := $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_SRCS_FILES)))
BONUS_OBJS  := $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_SRCS_FILES)))

DEPS		:= $(addprefix $(OBJS_DIR), $(addsuffix .d, $(SRCS_FILES) $(BONUS_SRCS_FILES)))

#==============================RULES=============================================#

.PHONY: all clean fclean re run bonus NOBONUS BONUS

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) -I$(INC) -I$(LIBFT_INC) -I$(MLX_DIR) -MP -MMD -c $< -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJS) NOBONUS
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\n$(GREEN)$(NAME)✓ compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)\n------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

bonus: clean BONUS $(BONUS_NAME)

$(BONUS_NAME): $(MLX) $(LIBFT) $(OBJS) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(BONUS_OBJS) $(LDFLAGS) -o $(BONUS_NAME)
	@echo "\n$(GREEN)$(BONUS_NAME)✓ compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)\n------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

NOBONUS:
	@$(eval CFLAGS += -DBONUS=0)
	@echo "$(LIGHT_PURPLE)Compilación sin bonus: CFLAGS=$(CFLAGS)$(DEF_COLOR)"

BONUS:
	@$(eval CFLAGS += -DBONUS=1)
	@echo "$(LIGHT_PURPLE)Compilación con bonus: CFLAGS=$(CFLAGS)$(DEF_COLOR)"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MLX):
	@make -sC $(MLX_DIR)

run: clean $(NAME) 
	@if [ -z "$(MAP)" ]; then \
	echo "$(BOLD_RED)Error$(DEF_COLOR): $(LIGHT_WHITE)Debes especificar el nombre del mapa con MAP=nombre_del_mapa $(DEF_COLOR)"; \
	else \
		./$(NAME) $(MAPS)/$(MAP); \
	fi

run_bonus: clean bonus
	@if [ -z "$(MAP)" ]; then \
	echo "$(BOLD_RED)Error$(DEF_COLOR): $(LIGHT_WHITE)Debes especificar el nombre del mapa con MAP=nombre_del_mapa $(DEF_COLOR)"; \
	else \
		./$(BONUS_NAME) $(MAPS)/bonus/$(MAP); \
	fi

clean:
	@$(RM) -rf $(OBJS_DIR)
	@make fclean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo "$(GREEN)$(NAME) $(BONUS_NAME)$(YELLOW) cleaned$(DEF_COLOR)"

re: fclean all

-include $(DEPS)

.SILENT: all clean fclean
