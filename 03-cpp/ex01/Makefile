# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 19:12:06 by rsaueia           #+#    #+#              #
#    Updated: 2025/06/02 19:12:27 by rsaueia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := scavtrap
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

SRCS    := main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS    := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
