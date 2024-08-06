NAME = Replace

SRC =

MAIN = main.cpp

FLAGS = -Wall -Wextra -Werror -g -std=c++98

OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

CC = c++

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<

all : ${NAME}

${NAME}: ${OBJ}
	@echo "Compiling into object files"
	@${CC} ${FLAGS} ${SRC} ${MAIN} -o ${NAME} > /dev/null
	@echo "Compiled successfuly!"

fclean :
	rm -rf ${NAME}

re:
	make fclean
	c++ ${FLAGS} ${SRC} ${MAIN} -o ${NAME}
