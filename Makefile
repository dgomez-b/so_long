# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 11:01:46 by dgomez-b          #+#    #+#              #
#    Updated: 2024/06/23 15:53:53 by dgomez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
SRC			=	./src/
MLX			=	./minilibx-linux/mlx.a
SRCS		=	main.c
OBJS		=	$(SRCS:.c=.o)
C			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3

all			:	$(MLX) $(NAME)
$(BIN)%.o	:	$(SRC)%.c
				@ mkdir -p $(dir $@)
				@ $(C) $(CFLAGS) -c -o $@ $^ -I$(dir $(MLX))
%.a			:
				@ make -C $(dir $@)
$(NAME)		:	$(OBJS)
				@ $(C) $(CFLAGS) -o $@ $^ -L$(dir $(MLX)) -lmlx -lXext -lX11 \
				-lm -lz
clean		:
				@ rm -rfv $(OBJS)
fclean		:	clean
				@ rm -rfv $(NAME)
re			:	fclean all
.PHONY		:	all clean fclean re
