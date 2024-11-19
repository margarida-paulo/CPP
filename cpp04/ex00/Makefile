NAME = animal

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = src/Animal.cpp src/Dog.cpp src/Cat.cpp src/WrongAnimal.cpp src/WrongCat.cpp

MAIN = main.cpp

OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<

HEADERS = include/Animal.hpp include/Cat.hpp include/Dog.hpp include/WrongAnimal.hpp include/WrongCat.hpp

all : ${NAME}

${NAME}: ${OBJ} ${HEADERS}
	@echo "Compiling into object files"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled successfuly!"

clean:
	@rm -rf ${OBJ}
	@echo "Object files deleted."

fclean : clean
	@rm -rf ${NAME}
	@echo "Executable deleted."

re:
	@make fclean
	@make
