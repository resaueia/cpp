NAME = zombiehorde

# Compilador e flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Arquivos-fonte
SRCS = main.cpp Zombie.cpp zombieHorde.cpp

# Objetos correspondentes
OBJS = $(SRCS:.cpp=.o)

# Regra principal
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Regra para compilar .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar objetos
clean:
	rm -f $(OBJS)

# Limpar tudo
fclean: clean
	rm -f $(NAME)

# Recompilar
re: fclean all

# Evita conflito com arquivos chamados "clean", "fclean", etc.
.PHONY: all clean fclean re
