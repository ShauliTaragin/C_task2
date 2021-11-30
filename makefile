CC = gcc
AR = ar -rcs
Flags = -Wall -g
Objects_mat  = my_mat.o
Objects_main = main.o

all: connections

connections: $(Objects_main) makematrix.a
	$(CC) $(Flags) -o connections $(Objects_main) makematrix.a

makematrix.a: $(Objects_mat)
	$(AR) makematrix.a $(Objects_mat)

main.o: main.c my_mat.h
	$(CC) $(Flags) -c main.c
	
my_mat.o: my_mat.c my_mat.h
	$(CC) $(Flags) -c my_mat.c -o $(Objects_mat)

.PHONY: clean all

clean:
	rm -f *.o *.a connections

run:
	./connections