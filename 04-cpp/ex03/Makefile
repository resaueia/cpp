# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 18:36:39 by rsaueia           #+#    #+#              #
#    Updated: 2025/06/27 18:37:52 by rsaueia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia_caster

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       AMateria.cpp Ice.cpp Cure.cpp \
       Character.cpp MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp \
          IMateriaSource.hpp MateriaSource.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
