NAME = ex01

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

FILES = main.cpp Span.cpp

HEADERS = Span.hpp

all: ${NAME}

${NAME}: ${FILES} ${HEADERS}
	${CPP} ${FLAGS} ${FILES} -o ${NAME}

fclean:
	rm ${NAME}

re:
	make fclean
	make