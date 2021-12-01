CC = gcc
AR = ar -rcs
Flags = -Wall -g
Objects_mat = my_mat.o
Objects_main = main.o

all: connections my_lib

connections: $(Objects_main) makematrix.a 
	$(CC) $(Flags) connections -o $(Objects_main) makematrix.a  
my_lib: makematrix.a
makematrix.a: $(Objects_mat)
	$(AR) makematrix.a $(Objects_mat) -lm

main.o: main.c my_mat.h
	$(CC) $(Flags) -c main.c
	
my_mat.o: my_mat.c my_mat.h
	$(CC) $(Flags) -c my_mat.c

.PHONY: clean all

clean:
	rm -f *.o *.a  connections

