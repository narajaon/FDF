# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: narajaon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 13:20:13 by narajaon          #+#    #+#              #
#    Updated: 2017/05/29 18:34:18 by narajaon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
HEAD = fdf.h
LIB = libft.a
LIBDIR = libft
SRC = main.c \
	  link_points.c \
	  points_manip.c \
	  points_parsing.c \
	  utils.c
FLAG = -framework OpenGL -framework AppKit -lmlx
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(HEAD)
	@echo "Compiling \033[92m$(LIB)\033[0m..."
	@make -C $(LIBDIR)/
	@echo "Compiling \033[92m$(NAME)\033[0m..."
	@gcc $(SRC) $(FLAG) $(LIBDIR)/$(LIB) -o $(NAME)
	@echo "$(NAME) compilation:\033[92m OK\033[0m"

clean:
	@echo "Deleting:\033[33m $(LIB) and *.o\033[0m"
	@rm -f $(OBJ)
	@make -C $(LIBDIR)/ clean

fclean: clean
	@echo "Deleting:\033[33m $(NAME)\033[0m"
	@echo "Deleting:\033[33m $(LIB)\033[0m"
	@rm -f $(NAME)
	@rm -f $(LIBDIR)/$(LIB)

re: fclean all

.PHONY: clean fclean re
