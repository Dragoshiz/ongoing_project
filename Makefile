# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 12:11:52 by dimbrea           #+#    #+#              #
#    Updated: 2022/05/12 12:59:32 by dimbrea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

RM = rm -f

# CFLAGS = -Wall -Werror -Wextra

AF = ar rcs

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS =	map_utils/check_map.c \
		map_utils/map_err_msg.c \
		main.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
				make -C libft
				make -C mlx
				$(CC) $(OBJ)  libft/libft.a $(MLX) mlx/libmlx.a -o $(NAME)

clean:
	$(RM) $(OBJS) 
	make clean -C libft
	make clean -C mlx

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	

re: fclean all

PHONY: all clean fclean re