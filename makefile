CC = gcc
AR = ar -rcs
Flags = -Wall -g
Objects_mat  = my_mat.o
Objects_main = main.o

all: connections matlib

connections: $(Objects_main) makematrix.a my_mat.h
	$(CC) $(Flags) -o connections $(Objects_main) makematrix.a

matlib: makematrix.a

makematrix.a: $(Objects_mat)
	$(AR) makematrix.a $(Objects_mat)

main.o: main.c my_mat.h
	$(CC) $(Flags) -c main.c
	
my_mat.o: my_mat.c 
	$(CC) $(Flags) -c my_mat.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections

