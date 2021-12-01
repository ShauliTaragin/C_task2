CC = gcc
AR = ar -rcs
Flags = -Wall -g
Objects_mat  = my_mat.o
Objects_main = main.o

all: connections main.o makematrix.a my_mat.h

connections: $(Objects_main) makematrix.a 
	$(CC) $(Flags) $(Objects_main) makematrix.a -o connections 

makematrix.a: $(Objects_mat)
	$(AR) makematrix.a $(Objects_mat)

main.o: main.c my_mat.h
	$(CC) $(Flags) -c main.c
	
my_mat.o: my_mat.c 
	$(CC) $(Flags) -c my_mat.c

.PHONY: clean all

clean:
	rm -f *.o *.a  connections

