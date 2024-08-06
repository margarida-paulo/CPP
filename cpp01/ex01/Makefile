NAME = Zombie

SRC = Zombie.cpp ZombieHorde.cpp

MAIN = main.cpp

FLAGS = -Wall -Wextra -Werror -g -std=c++98

OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

CC = c++

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<

all : ${NAME}

${NAME}: ${OBJ}
	@echo "Compiling into object files"
	@$(CC) $(STANDARD_FLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled successfuly!"

clean:
	@rm -rf ${OBJ}
	@echo "Object files deleted."

fclean : clean
	@rm -rf ${NAME}
	@echo "Object files and executable deleted."

re:
	@make fclean
	@make
