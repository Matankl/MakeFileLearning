# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra -g


# Default target
all: my_graph my_Knapsack

my_Knapsack: my_Knapsack.o libmy_math.a
	$(CC) $(CFLAGS) -o $@ $^ 

my_graph: my_graph.o libmy_math.a
	$(CC) $(CFLAGS) -o $@ $^


# comple .o files into a static library
libmy_math.a: my_mat.o 
	ar rcs $@ $^
# ^this one fits for graph_my Knapsack_my both^



### comple .o files into a shared library
#rule to compile my_graph.c and my_mat.h into my_graph.o
my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c my_graph.c -o $@

#rule to compile my_Knapsack.c and my_mat.h into my_Knapsack.o
my_Knapsack.o: my_Knapsack.c my_mat.h
	$(CC) $(CFLAGS) -c my_Knapsack.c -o $@

#rule to compile my_mat.c and my_mat.h into my_mat.o
my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c -o $@




# Clean up object files and the target executable
clean:
	rm *.o *.a my_graph my_Knapsack

