# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 12:11:52 by dimbrea           #+#    #+#              #
#    Updated: 2022/05/10 15:51:31 by dimbrea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

RM = rm -f

# CFLAGS = -Wall -Werror -Wextra

AF = ar rcs

SRCS = \
map_utils/check_map.c \
main.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
				$(CC) $(OBJS) -o $(NAME)
				$(MAKE) -C libft/

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft/make clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re