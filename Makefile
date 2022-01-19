SRC    = clean.c\
	 debug.c\
	 init.c\
	 init2.c\
	 loop.c\
	 loop2.c\
	 main.c\
	 time.c\
	 utils.c

OBJ    = ${SRC:.c=.o} -lpthread

RM      = rm -rf

CC      = clang
CFLAGS  = -Wall -Wextra -Werror 

NAME    = Philosophers

all:    $(NAME)

$(NAME):        ${OBJ}
	$(CC) $(CFLAGS) $(OBJ) -I ./include/Philosophers.h -o $(NAME)

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re:     fclean all

.PHONY: all fclean clean re
