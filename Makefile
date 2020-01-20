# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 11:34:23 by ykalashn          #+#    #+#              #
#    Updated: 2020/01/20 13:39:44 by kpesonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

DIR = ./fillitsrcs/

SRCS = $(DIR)main.c $(DIR)valid.c $(DIR)makelist.c $(DIR)map.c $(DIR)solve.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I ./fillitsrcs/includes -I ./libft/includes

LIBFT = libft/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@ make -C $(LIBFT)
	@ gcc $(FLAGS) $(SRCS) -o $(NAME) $(INCLUDES) -L $(LIBFT) -lft
	@ echo "fillit make done"

clean:
	@ rm -f $(OBJS)
	@ make -C $(LIBFT) clean
	@ echo "fillit clean objs"
	
fclean: clean
	@ rm -f $(NAME)
	@ make -C $(LIBFT) fclean
	@ echo "fillit clean bin"

re: fclean all
