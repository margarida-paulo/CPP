NAME = clapTrap

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = ClapTrap.cpp

INCLUDES = ClapTrap.hpp

MAIN = main.cpp

OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<

HEADERS = Contact.hpp PhoneBook.hpp

all : ${NAME}

${NAME}: ${OBJ} ${INCLUDES}
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
