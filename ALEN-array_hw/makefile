SRC:= test.c array.c
OBJ:=$(SRC:.c=.o)
FLAGS:= -Werror -Wall -Wextra
EXE:=exe

$(EXE): $(OBJ)
	gcc -o $@ $^

%.o: %.c
	gcc -c $(FLAGS) -g -ggdb -o $@ $<

clean:
	rm *.o $(EXE)
