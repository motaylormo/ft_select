# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/01 15:15:59 by mtaylor           #+#    #+#              #
#    Updated: 2019/06/01 15:16:00 by mtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
FLAGS = -Wall -Wextra -Werror -g

LIBFT_PATH = ./libft/
LIB = -I $(LIBFT_PATH) $(addprefix $(LIBFT_PATH), libft.a) -lcurses

INC	= -I ./inc/

FILES = main.c \
		signals.c \
		terminal_settings.c \
		list_struct.c \
		print_choices.c \
		termcaps_delete.c \
		keys.c \
		singletons.c

SRC = $(addprefix ./src/, $(FILES))

# **************************************************************************** #

all: $(NAME)

$(NAME):
	make -s -C $(LIBFT_PATH)
	gcc -Wall -Wextra -Werror $(LIB) $(SRC) $(INC) -o $(NAME)

debug:
	make -s -C $(LIBFT_PATH)
	gcc $(FLAGS) $(LIB) $(SRC) $(INC) -o $(NAME)

fsan:
	make -s -C $(LIBFT_PATH)
	gcc $(FLAGS) -fsanitize=address $(LIB) $(SRC) $(INC) -o $(NAME)

clean:
	make -s -C $(LIBFT_PATH) clean

fclean: clean
	make -s -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	rm -f -R $(addsuffix .dSYM, $(NAME))

re: fclean all