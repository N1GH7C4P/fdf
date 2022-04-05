# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 02:27:28 by linuxlite         #+#    #+#              #
#    Updated: 2022/04/05 03:48:55 by linuxlite        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= fdf
INCLUDE		= -I ./libft/ -I /usr/include -I mlx_linux
LIBS		= -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= src/
CC			= clang
CFLAGS		= -Wall -Werror -Wextra -O3 -g -fsanitize=address -v
RM			= rm -f
MINILIB		= -I minilibx-linux

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	fdf window graphics point line lines map projection params

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
			@echo "$(GREEN)fdf compiled!$(DEF_COLOR)"

clean:
			@$(RM) -rf $(OBJ)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)fdf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)fdf executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for fdf!$(DEF_COLOR)"
			
.PHONY:		all clean fclean re norm