# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aazeroua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 14:31:24 by aazeroua          #+#    #+#              #
#    Updated: 2019/03/31 21:58:59 by aazeroua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c *.c libft.h
	ar rc $(NAME) *.o
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
