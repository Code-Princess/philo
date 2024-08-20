# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 16:41:26 by llacsivy          #+#    #+#              #
#    Updated: 2024/08/20 18:10:16 by llacsivy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	OS_TYPE = MACOS
endif
ifeq ($(UNAME_S), Linux)
	OS_TYPE = LINUX
endif

ifeq ($(OS_TYPE), MACOS)
	LEAK_SANITIZER = /Users/llacsivy/LeakSanitizer/liblsan.dylib
endif
ifeq ($(OS_TYPE), LINUX)
	LEAK_SANITIZER = /Users/llacsivy/LeakSanitizer/liblsan.so
endif

NAME		:=	philo
CFLAGS		=	-Wall -Wextra -Werror -pthread
SRCS		:=	philo.c monitoring_functions.c init_functions.c \
				utils_functions.c input_check_functions.c routine_functions.c \
				free_functions.c monitoring_check_functions.c die_functions.c 
				
OBJS 		=	${SRCS:.c=.o}
%.o : %.c
	cc -g $(CFLAGS)  -c $< -o $@
# cc $(CFLAGS)  -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

# $(NAME):	$(OBJS)
# 	cc $(CFLAGS) $(OBJS) -o $(NAME) $(LEAK_SANITIZER)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re