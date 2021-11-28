CC = gcc
AR = ar
Flags = -Wall -g
Maths = -lm
Objects_mat  = my_mat.o
Objects_main = main.o

all: makematrix.a connections

makematrix.a: $(Objects_mat)
	$(AR) -rcs makematrix.a $(Objects_mat)

connections: $(Objects_main) makematrix.a
	$(CC) $(Flags) -o connections $(Objects_main) makematrix.a $(Maths)

main.o: main.c my_mat.h
	$(CC) $(Flags) -c main.c $(Maths)
	
my_mat.o: my_mat.c
	$(CC) $(Flags) my_mat.c $(Maths)

.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections
