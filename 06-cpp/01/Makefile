# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 15:27:30 by rsaueia           #+#    #+#              #
#    Updated: 2025/10/10 15:27:33 by rsaueia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = serialize
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
RM          = rm -f

SRC         = main.cpp Serializer.cpp
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
