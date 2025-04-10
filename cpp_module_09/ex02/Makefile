# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 21:15:29 by ahomari           #+#    #+#              #
#    Updated: 2025/01/31 19:37:56 by ahomari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC					= c++
FLAGS				= -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address
RM					= rm -rf
NAME				= PmergeMe
SRC					= main.cpp PmergeMe.cpp
S_OBJ				= ${SRC:.cpp=.o}

all :				${NAME}
 
${NAME}:			${S_OBJ} PmergeMe.hpp
					@${CC} ${FLAGS} ${S_OBJ} -o ${NAME}
					@echo "${GREEN}${NAME} Created!${DEFAULT}"

%.o: %.cpp			PmergeMe.hpp
					${CC} ${FLAGS} -c $< -o $@

clean:
					@${RM} ${S_OBJ}
					@echo "${YELLOW}Object Files deleted!${DEFAULT}"

fclean:				clean
					@${RM} ${NAME}
					@echo "${RED}All Deleted!${DEFAULT}"

re:					fclean ${NAME}

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m