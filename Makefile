# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 14:43:19 by dlima-li          #+#    #+#              #
#    Updated: 2026/04/21 16:32:37 by dlima-li         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		srcs/ft_calloc.c srcs/ft_split.c srcs/main.c srcs/parsing.c srcs/push.c srcs/swap.c srcs/rotate.c srcs/reverserotate.c srcs/sort_small.c srcs/sort_three.c srcs/turk_algo.c srcs/turk_exec.c srcs/utils_find.c srcs/utils_stack.c srcs/utils.c srcs/validation.c

OFILES =	$(SRCS:.c=.o)

CC =		cc
CFLAGS =	-Wall -Wextra -Werror

NAME =		push_swap

all:		$(NAME)

$(NAME):	$(OFILES)
			$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

clean:
			rm -f $(OFILES)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re

