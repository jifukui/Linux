CC?=gcc
CPP?=g++
all:main.o reciprocal.o
	$(CC) -o first.out main.o reciprocal.o
main.o:main.c reciprocal.hpp
	$(CC) -o main.c
reciprocal.o:reciprocal.cpp reciprocal.hpp
	$(CPP) -o reciprocal.cpp