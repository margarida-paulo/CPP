NAME = Zombie

SRC = Zombie.cpp ZombieHorde.cpp

MAIN = main.cpp

FLAGS = -Wall -Wextra -Werror -g -std=c++98

all : ${NAME}

${NAME}:
	c++ ${FLAGS} ${SRC} ${MAIN} -o ${NAME}

fclean :
	rm -rf ${NAME}

re:
	make fclean
	c++ ${FLAGS} ${SRC} ${MAIN} -o ${NAME}
