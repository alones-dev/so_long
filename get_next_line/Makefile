# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 09:49:28 by kdaumont          #+#    #+#              #
#    Updated: 2023/12/08 09:49:39 by kdaumont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

HEADER = get_next_line.h
SRCS = get_next_line_utils.c get_next_line.c
OBJS = $(SRCS:.c=.o)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS) -D BUFFER_SIZE=1000
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all