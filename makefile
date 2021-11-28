CC = gcc
AR = ar
Flags = -Wall -g
Maths = -lm
Objects_mat  = my_mat.o
Objects_main = main.o

all =


makematrix.a: $(Objects_mat)
	$(AR) -rcs makematrix.a $(Objects_mat)

