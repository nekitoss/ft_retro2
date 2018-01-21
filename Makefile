#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpochuka <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 21:09:12 by mpochuka          #+#    #+#              #
#    Updated: 2017/11/05 20:53:34 by kstorozh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = clang++

FAST = -Ofast

FLAGS = -Wall -Wextra -Werror

NAME = ft_retro

SRC = main.cpp\
		Ship.cpp Bullet.cpp Entity.cpp
		#Asteroid.cpp Enemy.cpp Star.cpp

OBJ = $(SRC:.cpp=.o)

INC = -I ./ -I ./vizu

NCURSES = -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(INC) $(LIB) $(OBJ) $(NCURSES) -o $(NAME)
	@echo  "\033[32mCompiled and created" $(NAME) "binary\033[0m"

%.o: %.cpp
	@$(CC) $(INC) $(FAST) $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@echo "\033[01;31m"$(NAME)" object files deleted\033[0m"

fclean: clean
	@rm -f $(NAME) a.out
	@echo "\033[01;31m"$(NAME)" binary file deleted\033[0m"

re: fclean all
