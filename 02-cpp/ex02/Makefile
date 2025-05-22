# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 18:22:37 by rsaueia           #+#    #+#              #
#    Updated: 2025/05/22 18:23:23 by rsaueia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the final executable
NAME    = ex02

# Compiler and flags
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

# Source files
SRCS    = Fixed.cpp main.cpp

# Object files (replace .cpp by .o)
OBJS    = $(SRCS:.cpp=.o)

# Default target: build the executable
all: $(NAME)

# Link object files into the executable
$(NAME): $(OBJS)
	@echo "Linking $(OBJS) into $(NAME)..."
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile .cpp files into .o
# $< is the source file, $@ is the target object
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove object files
clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)

# Remove object files and the executable
fclean: clean
	@echo "Removing executable $(NAME)..."
	rm -f $(NAME)

# Rebuild from scratch
re: fclean all

.PHONY: all clean fclean re