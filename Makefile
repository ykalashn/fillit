# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykalashn <ykalashn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 11:34:23 by ykalashn          #+#    #+#              #
#    Updated: 2020/01/07 17:16:05 by kpesonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS = main.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I ./ -I ./libft/includes

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
