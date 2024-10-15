NAME = Bank

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = Account.cpp tests.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<

HEADERS = Account.hpp

all : ${NAME}

${NAME}: ${OBJ}
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
