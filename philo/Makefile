# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilovancandan <dilovancandan@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 13:15:27 by dcandan           #+#    #+#              #
#    Updated: 2023/07/24 18:07:38 by dilovancand      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCES = philo.c philo_utils.c philo_check_errors.c philo_malloc.c philo_action.c philo_free.c philo_ded.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

all: ${NAME}

philo: ${OBJECTS}
	$(CC) $(CFLAGS) ${OBJECTS} -o philo

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f ${OBJECTS}
	
fclean: clean
	rm -f ${NAME}

re: fclean all