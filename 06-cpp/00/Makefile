# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 18:00:00 by rsaueia           #+#    #+#              #
#    Updated: 2025/10/08 18:25:16 by rsaueia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = convert
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
RM          = rm -f


SRC         = main.cpp ScalarConverter.cpp

OBJ         = $(SRC:.cpp=.o)


all: $(NAME)


$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Compilation successful: $(NAME)"


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJ)
	@echo "🧹 Object files removed."


fclean: clean
	$(RM) $(NAME)
	@echo "🧼 Executable removed."

re: fclean all

.PHONY: all clean fclean re
