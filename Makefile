# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 16:41:26 by llacsivy          #+#    #+#              #
#    Updated: 2024/08/02 13:58:13 by llacsivy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CFLAGS		=	-Wall -Wextra -Werror -pthread
SRCS		=	philo.c monitoring_functions.c init_functions.c \
				utils_functions.c input_check_functions.c 
OBJS 		=	${SRCS:.c=.o}
%.o : %.c
	cc -g $(CFLAGS)  -c $< -o $@
# cc $(CFLAGS)  -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
# cc $(CFLAGS) $(OBJS) -o $(NAME) /Users/llacsivy/LeakSanitizer/liblsan.dylib
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)
	
re:	fclean all

.PHONY:	all clean fclean re