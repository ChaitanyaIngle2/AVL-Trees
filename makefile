# Make file for tree assignment

OBJS	= words.o wordSearch.o
CC	= g++ -Wall -pedantic -g -std=c++11
DEPS	= wordSearch.h avlTree.h
DEPS1	= avlTree.h

all: words avlTest

avlTest.o: avlTest.cpp $(DEPS1)
	$(CC) -c avlTest.cpp

avlTest: avlTest.o $(DEPS1)
	$(CC) -o avlTest avlTest.o


wordSearch.o: wordSearch.cpp $(DEPS)
	$(CC) -c wordSearch.cpp

words.o: words.cpp $(DEPS)
	$(CC) -c words.cpp

words: words.o wordSearch.o $(DEPS)
	$(CC) -o words $(OBJS)

# -----
# clean by removing object files.

clean:
	rm	$(OBJS)

