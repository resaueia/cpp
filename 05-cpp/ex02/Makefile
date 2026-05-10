# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 14:26:44 by rsaueia           #+#    #+#              #
#    Updated: 2025/09/28 14:26:57 by rsaueia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = bureaucracy
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
RM          = rm -f

# Source files
SRCS        = main.cpp \
              Bureaucrat.cpp \
              AForm.cpp \
              ShrubberyCreationForm.cpp \
              RobotomyRequestForm.cpp \
              PresidentialPardonForm.cpp

# Object files (auto convert .cpp -> .o)
OBJS        = $(SRCS:.cpp=.o)

# Header dependencies
DEPS        = Bureaucrat.hpp \
              AForm.hpp \
              ShrubberyCreationForm.hpp \
              RobotomyRequestForm.hpp \
              PresidentialPardonForm.hpp

# Compile rule
all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Clean .o files
clean:
	$(RM) $(OBJS)

# Clean everything
fclean: clean
	$(RM) $(NAME)

# Recompile everything
re: fclean all

# Optional: don't treat these names as files
.PHONY: all clean fclean re
