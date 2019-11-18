CC?=gcc
CPP?=g++
CFLAGS=
CPPFLAGS=
all:main.o reciprocal.o
	$(CC) -o $(CFLAGS) first.out main.o reciprocal.o
main.o:main.c reciprocal.hpp
	$(CC) -o $(CFLAGS) main.c
reciprocal.o:reciprocal.cpp reciprocal.hpp
	$(CPP) -o $(CPPFLAGS) reciprocal.cpp