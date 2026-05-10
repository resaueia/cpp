# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/23 19:24:21 by rsaueia-          #+#    #+#              #
#    Updated: 2025/08/23 19:24:45 by rsaueia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source and object files
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all
