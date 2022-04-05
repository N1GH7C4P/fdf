# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpolojar <kpolojar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 02:27:28 by linuxlite         #+#    #+#              #
#    Updated: 2022/04/05 19:29:08 by kpolojar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= fdf
INCLUDE		= -I ./libft/ -I ./minilibx-mac-osx/
LIBS		= -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT		= libft
MLX			= minilibx
SRC_DIR		= src/
OBJ_DIR		= src/
CC			= clang
CFLAGS		= -Wall -Werror -Wextra -O3
RM			= rm -f

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

all:		$(NAME)


$(NAME):	$(OBJ)
			@make -C $(MLX)
			@make -C $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBS) -o $(NAME)
			@echo "$(GREEN)fdf compiled!$(DEF_COLOR)"

clean:
			@$(RM) -rf $(OBJ)
			@make clean -C $(LIBFT)
			@make clean -C $(MLX)
			@echo "$(BLUE)fdf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)fdf executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for fdf!$(DEF_COLOR)"
			
.PHONY:		all clean fclean re norm