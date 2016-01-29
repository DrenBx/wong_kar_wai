# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/28 15:20:11 by fkalb             #+#    #+#              #
#    Updated: 2015/03/01 17:33:27 by glavanan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=game_2048
FLAGS= -W -Wall -Wextra -Werror -lncurses -O2

INC_DIR=./includes/

SRCS=$(addprefix ./srcs/, $(addsuffix .c, $(SRC_LIST)))
SRC_LIST=main_test\
		init\
		menu\
		game\
		clear\
		resize\
		bot\
		top\
		right\
		left\
		ft_random\
		ft_init_tab\
		ft_valid_moove\
		ft_loose\
		ft_save_save\
		win\
		ft_free\


.SILENT: all $(NAME) clean fclean re

all : $(NAME)

$(NAME):
	echo "[ \033[0;33;mcompiling\033[0m ]"
	$(CC) $(FLAGS) $(SRCS) -I$(INC_DIR) -o $(NAME)
	echo "[ \033[0;32;msuccessfuly\033[0m ]" $(NAME) "was created"

clean:
	echo "[ \033[0;33;mcleaning\033[0m ]"

fclean: clean
	rm -f $(NAME)
	echo "[ \033[0;31;mdel\033[0m ]"$(NAME)

re: fclean all
