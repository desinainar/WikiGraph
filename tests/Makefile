CC=g++
CFLAGS=-g -o

.RECIPEPREFIX := $(.RECIPEPREFIX) 

test: node.o graph.o; \
$(CC) $(CFLAGS) -o tests.cpp

node.o: ../src/Node.h; \
$(CC) $(CFLAGS) -c ../src/Node.h

graph.o: ../src/Graph.h; \
$(CC) $(CFLAGS) -c ../src/Graph.h