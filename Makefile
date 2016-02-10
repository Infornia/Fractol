# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:17:56 by mwilk             #+#    #+#              #
#    Updated: 2016/02/11 00:15:24 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## PROJECT

NAME = fractol

LIBFT = libft

## COMPILATEUR

OS = $(shell uname -s)
CC = clang
FLAGS = -Wall -Wextra -Werror

## FILES

SRC = init.c\
	  init_img.c\
	  fractol.c\
	  main.c\
	  hooks.c\
	  hooks_help.c\
	  draw.c\
	  color.c\
	  usage.c\
	  julia.c\
	  tree.c\
	  burn_newton.c\
	  mandelbrot.c\
	  triangle.c\

INC =  -I ./inc/
INC += -I ./libft/inc/
INC += -I minilibx/

OBJ = $(SRC:.c=.o)

LIB =  -L libft -lft
LIB += -L minilibx/ -lmlx -framework OpenGl -framework Appkit

## RULES

all: ml $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INC) $(LIB) -o $(NAME) $(SRC)
	@echo "\033[35m <(O.O<) WOW ! Very Fractol ! Amaze ! (>^o^)> \033[0m"

clean:
	rm -rf $(OBJ)
	@echo "\033[36mT.T Miss you Frac object files T.T \033[0m"

fclean: mfl clean
	rm -rf $(NAME) $(LIBFT)
	rm -rf .gitmodules
	@echo "\033[36m X.x Bye Bye compiled files >_< \033[0m"

%.o:%.c
	$(CC) $(FLAGS) $(INC) -c $< -o $@

ml:
		git rm -rf --cached $(LIBFT)
		git submodule add --force https://github.com/Infornia/libft.git $(LIBFT)
		git submodule init
		git submodule update
		make -C libft


mcl:
		make -C libft clean

mfl:
		make -C libft fclean
#		mkdir -p $(LIBFT)
#		rm -rf $(LIBFT)
#		rm -rf .git/modules/$(LIBFT)
#		rm -fr $(LIBFT)
#		rm -fr .gitmodules

mrl:
		make -C libft re

re: fclean all

.PHONY: all normal clean fclean re makelib makerelib cleanlib fcleanlib

