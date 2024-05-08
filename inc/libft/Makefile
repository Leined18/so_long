# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 16:56:35 by danpalac          #+#    #+#              #
#    Updated: 2024/02/26 15:47:01 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror -I $(INC)
RM		= rm -rf
AR		= ar rcs
LIB		= ranlib
INC			= inc/

SRCS_FILES	= ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_bzero.c ft_calloc.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_atoi.c ft_itoa.c ft_split.c ft_strchr.c ft_strdup.c \
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
			ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
		  	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 


SRCS_DIR			= srcs/
OBJS_DIR			= objs/
SRCS				= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS				= $(addprefix $(OBJS_DIR), $(OBJS_FILES))
OBJS_FILES			= $(SRCS_FILES:%.c=%.o) 

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

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)
	$(LIB) $(NAME)
	@echo "$(GREEN)\nlibft.a compiled!$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	[ -d $(OBJS_DIR) ] | mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	printf "\33[2K\r$(GRAY) $(CC) $(CFLAGS) -c $< -o $@ $(DEF_COLOR)"


clean:
	$(RM) $(OBJS_DIR)
	@echo "$(GREEN)\nlibft$(YELLOW) cleaned$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT: all $(NAME) $(OBJS) re clean fclean
.PHONY: all clean fclean re
