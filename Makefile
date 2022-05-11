# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 12:11:52 by dimbrea           #+#    #+#              #
#    Updated: 2022/05/11 11:03:11 by dimbrea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

RM = rm -f

# CFLAGS = -Wall -Werror -Wextra

AF = ar rcs

SRCS =	map_utils/check_map.c \
		main.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
				make -C libft
				$(CC) $(OBJS) -g -o $(NAME) libft/libft.a

clean:
	$(RM) $(OBJS) 
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

PHONY: all clean fclean re