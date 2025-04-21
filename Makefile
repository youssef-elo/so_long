# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 16:54:49 by yel-ouaz          #+#    #+#              #
#    Updated: 2024/06/27 13:37:56 by yel-ouaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS= so_long_bonus

CFLAGS = -Wall -Wextra -Werror

LIBS = -lmlx -framework OpenGL -framework AppKit

MHEADERS = mandatory/so_long.h mandatory/get_next_line.h

BHEADERS = bonus/so_long_bonus.h bonus/get_next_line_bonus.h

FILES= mandatory/key.c     \
	mandatory/exit.c        \
	mandatory/flood.c        \
	mandatory/struct.c        \
	mandatory/so_long.c        \
	mandatory/parsing.c         \
	mandatory/so_long_utils.c    \
	mandatory/get_next_line.c     \
	mandatory/get_next_line_utils.c\

OFILES =$(FILES:.c=.o)

BFILES = bonus/key_bonus.c  \
	bonus/exit_bonus.c       \
	bonus/enemy_bonus.c       \
	bonus/flood_bonus.c        \
	bonus/struct_bonus.c        \
	bonus/so_long_bonus.c        \
	bonus/parsing_bonus.c         \
	bonus/so_long_utils_bonus.c    \
	bonus/get_next_line_bonus.c     \
	bonus/animate_bonus.c			 \
	bonus/get_next_line_utils_bonus.c \
	bonus/so_long_utils_2_bonus.c      \

BOFILES = $(BFILES:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(BONUS) : $(BOFILES)
	cc $(CFLAGS) $(LIBS) $(BOFILES) -o $(BONUS)
	

$(NAME) : $(OFILES) 
	cc $(CFLAGS) $(LIBS) $(OFILES) -o $(NAME)

mandatory/%.o : mandatory/%.c $(MHEADERS)
	cc $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(BHEADERS)
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OFILES) $(BOFILES)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all