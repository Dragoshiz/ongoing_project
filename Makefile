# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 12:11:52 by dimbrea           #+#    #+#              #
#    Updated: 2022/05/17 13:43:08 by dimbrea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

AF = ar rc

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS =	map_utils/check_map.c \
		map_utils/map_err_msg.c \
		map_utils/put_img.c\
		game_cmd/engine.c\
		game_cmd/movement.c\
		main.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
				make -C libft
				cp ./libft/libft.a libft_so_long.a
				$(AF) libft_so_long.a $(OBJS)
				$(CC) $(FLAGS) -L. ./libft_so_long.a ./mlx/libmlx.a $(MLX) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) 
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(RM) libft_so_long.a
	make fclean -C libft
	

re: fclean all

PHONY: all clean fclean re