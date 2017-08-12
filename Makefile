CXX=g++
CXXFLAGS=-std=c++11 -g -Wall
LDFLAGS=-g
INCLUDES=-I/usr/include/python2.7
LIBRARY=-lpython2.7

all: main

main: SiteData.o
	${CXX} ${INCLUDES} main.cpp -lpython2.7

SiteData.o: SiteData.h

clean:
	rm -f *.o
