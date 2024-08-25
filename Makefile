# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 16:41:26 by llacsivy          #+#    #+#              #
#    Updated: 2024/08/25 14:38:27 by llacsivy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philo
CFLAGS		=	-Wall -Wextra -Werror -pthread
SRCS		:=	philo.c monitoring_functions.c init_data_functions.c \
				utils_functions.c input_check_functions.c routine_functions.c \
				destroy_functions.c join_thread_functions.c \
				stop_simulation_check_functions.c init_philosophers_functions.c \
				routine_utils_functions.c
				
OBJS 		=	${SRCS:.c=.o}

%.o : %.c
	cc $(CFLAGS)  -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re