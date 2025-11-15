# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 14:03:27 by rsaueia           #+#    #+#              #
#    Updated: 2025/11/15 14:23:45 by rsaueia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
NAME     := RPN

SRCS := main.cpp RPN.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
