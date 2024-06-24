# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 11:01:46 by dgomez-b          #+#    #+#              #
#    Updated: 2024/06/24 01:48:54 by dgomez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
INC			=	./includes/
BIN			=	./.bin/
SRC			=	./src/
SRCS		=	main.c \
				build_map.c \
				chk_file_path.c \
				file_errors.c \
				general_error.c \
				generate_map.c \
				load_images.c \
				map_checkers.c \
				map_checkers2.c \
				map_errors.c \
				map_utils.c \
				player_utils.c \
				printers.c \
				string_length.c \
				close_program.c

OBJS		=	$(addprefix $(BIN), $(SRCS:.c=.o))
MLX			=	$(INC)minilibx-linux/libmlx.a
LIBFT		=	$(INC)libft/libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3

all			:	$(NAME)

$(BIN)%.o	:	$(SRC)%.c
				@ $(CC) $(CFLAGS) -c -o $@ $^ -I$(INC)

%.a			:
				@ make -sC $(dir $@)

$(NAME)		:	$(MLX) $(LIBFT) $(OBJS)
				@ $(CC) $(CFLAGS) -o $@ $^ -L$(dir $(MLX)) -lmlx -lXext -lX11 \
				-lm -lz -L$(dir $(LIBFT)) -lft

clean		:
				@ rm -rfv $(OBJS)
				@ make -sC $(dir $(MLX)) clean
				@ make -sC $(dir $(LIBFT)) clean

fclean		:	clean
				@ rm -rfv $(NAME)
				@ make -sC $(dir $(LIBFT)) fclean

re			:	fclean all

.PHONY		:	all clean fclean re
