NAME = a.out

SRC = Fixed.cpp Point.cpp bsp.cpp

MAIN = main.cpp

FLAGS = -Wall -Wextra -Werror -g -std=c++98

OBJ = $(MAIN:.cpp=.o) $(SRC:.cpp=.o)

CC = c++

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<

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
	@echo "Object files and executable deleted."

re:
	@make fclean
	@make
