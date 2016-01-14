# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/05 02:12:10 by pbondoer          #+#    #+#              #
#    Updated: 2015/12/20 16:56:35 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
SRC		= main.c
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIBFT	= libft/libft.a
LIBINC	= -Ilibft
LIBLINK	= -Llibft -lft
all: libft $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(LIBINC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJ)
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
