# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 14:33:36 by ntan              #+#    #+#              #
#    Updated: 2022/03/09 16:39:32 by ntan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	src/main.c \
					src/check_file.c \
					src/update.c \
					src/window.c \
					src/ending.c \
					src/ft_itoa.c \
					src/le_mechant.c \
					src/directions.c \
					src/display.c \
					src/pok_anim.c \
					src/input.c \
					src/check_map.c \
					src/map_parsing.c \
					src/init_sprites.c \
					src/gnl/get_next_line.c \
					src/gnl/get_next_line_utils.c
OBJS			= 	$(SRCS:.c=.o)

SRCS_BONUS		=	src_bonus/main.c \
					src_bonus/check_file.c \
					src_bonus/update.c \
					src_bonus/window.c \
					src_bonus/ending.c \
					src_bonus/ft_itoa.c \
					src_bonus/le_mechant.c \
					src_bonus/directions.c \
					src_bonus/display.c \
					src_bonus/pok_anim.c \
					src_bonus/input.c \
					src_bonus/check_map.c \
					src_bonus/map_parsing.c \
					src_bonus/init_sprites.c \
					src_bonus/gnl/get_next_line.c \
					src_bonus/gnl/get_next_line_utils.c
OBJS_BONUS		= 	$(SRCS_BONUS:.c=.o)

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	so_long
BONUS_NAME		=	so_long_bonus

%.o: %.c
				$(CC) $(CFLAGS) -I./mlx_linux -I/usr/include -c $< -o $@

all:			$(NAME)

$(NAME): 		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -L ./mlx_linux -lmlx_Linux -L/usr/lib -I./mlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus :			$(BONUS_NAME)

$(BONUS_NAME):	$(OBJS_BONUS)
				$(CC) $(CFLAGS) $(OBJS_BONUS) -L ./mlx_linux -lmlx_Linux -L/usr/lib -I./mlx_linux -lXext -lX11 -lm -lz -o $(BONUS_NAME)
				
clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS_BONUS)
				
fclean:			clean
				$(RM) $(NAME)
				$(RM) $(BONUS_NAME)

re:				fclean all