# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 16:53:13 by rsaueia           #+#    #+#              #
#    Updated: 2025/10/10 16:53:56 by rsaueia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = identify
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
RM          = rm -f

SRC         = main.cpp Base.cpp methods.cpp
OBJ         = $(SRC:.cpp=.o)

# Default target: compila o projeto
all: $(NAME)

# Linking phase
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Compilation successful: $(NAME)"

# Compilation phase
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove object files
clean:
	$(RM) $(OBJ)
	@echo "🧹 Object files removed."

# Remove objects and executable
fclean: clean
	$(RM) $(NAME)
	@echo "🧼 Executable removed."

# Rebuild everything from scratch
re: fclean all

# Prevents Make from confusing rule names with files
.PHONY: all clean fclean re
