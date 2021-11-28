CC = gcc
AR = ar
Flags = -Wall -g
Maths = -lm
Objects_mat  = my_mat.o
Objects_main = main.o

all = makematrix.a connections

makematrix.a: $(Objects_mat)
	$(AR) -rcs makematrix.a $(Objects_mat)

connections: $(Objects_mat) makematrix.a
	$(CC) $(Flags) -o connections $(Objects_mat) makematrix.a $(Maths)

.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections
