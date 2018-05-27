all: wordsearch

wordsearch: bst.o main.o node.o
	g++ main.o node.o bst.o -o wordsearch

main.o: main.cpp node.h bst.h
	g++ -c main.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

bst.o: bst.cpp bst.h node.h
	g++ -c bst.cpp

clean:
	rm *.o wordsearch *~
