CFLAGS = -Wall -g
CC = gcc
SHELLOBJ = myshell.o parser.o shell_funcs.o pipeIt.o
PROGS =myshell

all: $(PROGS)
myshell:$(SHELLOBJ)

clean:
	rm -f $(PROGS) *.o*~
