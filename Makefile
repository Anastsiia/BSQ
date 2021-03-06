.PHONY: all clean fclean

SRC = *.c
OBJ = *.o
NAME = bsq
CC = gcc -Wall -Wextra -Werror
RM = /bin/rm -f
INCL = *.h

c.o.: 
	${CC} -c ${SRC} ${INCL}
	${CC} -o ${NAME} ${OBJ} 
all: c.o.

clean:
	${RM} *.o
	${RM} *.txt

fclean: clean
	${RM} ${NAME}
