CFLAGS=-c -Wall -O2
CC=gcc
OBJ=sense_hat.o
LIB=libsense.a

all: 
	$(CC) $(CFLAGS) src/sense_hat.c
	ar -rc $(LIB) $(OBJ)
	sudo cp $(LIB) /usr/local/lib
	sudo cp src/sense_hat.h /usr/local/include

example:
	$(CC) $(CFLAGS) demo/demo.c
	$(CC) demo.o -lsense -lpthread -lm -o sense_demo

remove:
	sudo rm /usr/local/lib/$(LIB)
	sudo rm /usr/local/include/sense_hat.h

clean:
	rm *.o *.a