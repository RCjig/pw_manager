CXX=g++
CXXFLAGS=-std=c++11 -g -Wall
LDFLAGS=-g
INCLUDES=-I/usr/include/python2.7
LIBRARY=-lpython2.7 -l sqlite3

all: main

main: SiteData.o main.cpp
	${CXX} ${CXXFLAGS} ${INCLUDES} -o main main.cpp SiteData.cpp ${LIBRARY}

SiteData.o: SiteData.h SiteData.cpp

clean:
	rm -f main *.o *.db
