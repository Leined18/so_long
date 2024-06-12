# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 16:56:35 by danpalac          #+#    #+#              #
#    Updated: 2024/06/12 11:20:50 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==========COLOURS=============================================================#

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

#==========NAMES===============================================================#

NAME		:= libft.a

#==========COMMANDS============================================================#

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g3
RM			:= rm -rf
AR			:= ar rcs
LIB			:= ranlib
MKDIR 		:= mkdir -p

#==========SOURCES============================================================#


IS_FILES	:= ft_isalpha ft_isalnum ft_isascii ft_isdigit ft_isprint
MEM_FILES	:= ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset
PUT_FILES	:= ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_error ft_successful
TO_FILES	:= ft_atoi ft_itoa ft_tolower ft_toupper
STR_FILES	:= ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
			ft_strnstr ft_strrchr ft_strtrim ft_substr ft_strrncmp 
LST_FILES	:= ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus ft_lstlast_bonus ft_lstadd_back_bonus \
		  	ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus
PRINTF_FILES	:= ft_printf
PRINTF_PUT_FILES := ft_putaddr ft_putbase_fd ft_putchar ft_puthexa ft_putnbr ft_putstr ft_putunsigned
MATH_FILES	:= ft_abs
GET_FILES := get_next_line


##==========DIRECTORIES=======================================================#

INCLUDES := inc/
SRC_DIR := srcs/
OBJ_DIR := obj/

IS_DIR := is/
LST_DIR := lst/
MEM_DIR := mem/
PUT_DIR := put/
STR_DIR := str/
TO_DIR := to/
PRINTF_DIR := printf/
PRINTF_PUT_DIR := printf/put/
MATH_DIR := math/
GET_DIR := get/

#==========FILES###===========================================================#

SRC_FILES+=$(addprefix $(IS_DIR), $(IS_FILES))
SRC_FILES+=$(addprefix $(MEM_DIR), $(MEM_FILES))
SRC_FILES+=$(addprefix $(PUT_DIR), $(PUT_FILES))
SRC_FILES+=$(addprefix $(TO_DIR), $(TO_FILES))
SRC_FILES+=$(addprefix $(STR_DIR), $(STR_FILES))
SRC_FILES+=$(addprefix $(LST_DIR), $(LST_FILES))
SRC_FILES+=$(addprefix $(PRINTF_DIR), $(PRINTF_FILES))
SRC_FILES+=$(addprefix $(PRINTF_PUT_DIR), $(PRINTF_PUT_FILES))
SRC_FILES+=$(addprefix $(MATH_DIR), $(MATH_FILES))
SRC_FILES+=$(addprefix $(GET_DIR), $(GET_FILES))

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS := $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

#==========RULES==============================================================#

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)
	@echo "$(BLUE) Compiling libft  ➟  $(CYAN)[$<]$(WHITE)"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -MMD -MP -c $< -o $@

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)\n ✓ Compiled $(NAME)\n$(WHITE)"

clean : 
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(RED)\n ✗ Files object libft erased.‼️\n$(WHITE)";

fclean : clean
	@$(RM) -f $(NAME)
	@echo "$(GREEN) everything cleaned...$(WHITE)"

re: fclean all

norm:
	@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

-include $(DEPS)

.PHONY: all clean fclean re norm
