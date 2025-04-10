# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/22 15:35:28 by ahomari           #+#    #+#              #
#    Updated: 2024/12/23 10:38:35 by ahomari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= c++
FLAGS				= -Wall -Wextra -Werror -std=c++98
RM					= rm -rf
NAME				= scalar
SRC					= main.cpp ScalarConverter.cpp
S_OBJ				= ${SRC:.cpp=.o}

all :				${NAME}
 
${NAME}:			${S_OBJ} ScalarConverter.hpp
					@${CC} ${FLAGS} ${S_OBJ} -o ${NAME}
					@echo "${GREEN}${NAME} Created!${DEFAULT}"

%.o: %.cpp			ScalarConverter.hpp
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