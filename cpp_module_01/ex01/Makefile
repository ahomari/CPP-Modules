# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 10:47:21 by ahomari           #+#    #+#              #
#    Updated: 2024/10/12 12:11:11 by ahomari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= c++
FLAGS				= -Wall -Wextra -Werror -std=c++98
RM					= rm -rf
NAME				= zombie
SRC					= main.cpp Zombie.cpp zombieHorde.cpp
S_OBJ				= ${SRC:.cpp=.o}

all :				${NAME}
 
${NAME}:			${S_OBJ} Zombie.hpp
					@${CC} ${FLAGS} ${S_OBJ} -o ${NAME}
					@echo "${GREEN}${NAME} Created!${DEFAULT}"

%.o: %.cpp			
					${CC} ${FLAGS} -c $< -o $@

clean:
					@${RM} ${S_OBJ}
					@echo "${YELLOW}Object Files deleted!${DEFAULT}"

fclean:				clean
					@${RM} ${NAME}
					@echo "${RED}All Deleted!${DEFAULT}"

re:					fclean ${NAME}

.PHONY: 			fclean re  clean

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m