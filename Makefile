# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 20:23:09 by akhodara          #+#    #+#              #
#    Updated: 2023/05/23 19:44:17 by akhodara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MLX_PATH	=	mlx/
MLX_LIB		=	$(MLX_PATH)libmlx.a
MLX_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH	=	./libft/
LIBFT_LIB	=	$(LIBFT_PATH)libft.a
CFILES		=	./game/check_all.c  ./game/ft_init.c  ./game/keys.c  \
				./game/move_mp.c  ./game/onechar_mp.c ./game/count.c\
				./game/path_mp.c  ./game/read_mp.c  ./game/rec_mp.c  \
				./game/rend_mp.c  ./game/show_mp.c \
				./game/so_long.c  ./game/utils.c  ./game/wall_mp.c
OBJECTS		=	$(CFILES:.c=.o)

all: subsystems $(NAME)

	@echo ""
	@echo ""
	@echo "compiling done. Now you can sort your numbers 😜"
	@echo ""
	@echo ""
	@echo "Have Written by Amin Khodarahmi"
	@echo ""
	@echo ""
	@curl https://icanhazdadjoke.com
	@echo ""
	@echo ""

%.o : %.c
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
	make -C $(MLX_PATH) all
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
