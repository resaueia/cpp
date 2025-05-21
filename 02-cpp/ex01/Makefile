# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 18:46:45 by rsaueia           #+#    #+#              #
#    Updated: 2025/05/21 18:48:16 by rsaueia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Fixed.cpp main.cpp

# Generate object filenames by replacing .cpp with .o
OBJ = $(SRC:.cpp=.o)

NAME = ex01

# Default NAME (builds the executable)
all: $(NAME)

# Link object files into the final executable
$(NAME): $(OBJ)
	@echo "Linking objects to create $(NAME)..."
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Rule to compile .cpp files into .o object files
# $< is the first prerequisite (the .cpp file)
# $@ is the NAME (the .o file)
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove all object files
clean:
	@echo "Removing object files..."
	rm -f $(OBJ)

# Remove object files and the executable
fclean: clean
	@echo "Removing executable $(NAME)..."
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Declare "phony" NAMEs (not real files)
.PHONY: all clean fclean re
