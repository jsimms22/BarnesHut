CC = gcc
CFLAGS = -O1 -std=gnu++11
LIBS = 

TARGETS = serial

all:	$(TARGETS)

serial: serial.o quadTree.o
	$(CC) -o $@ $(LIBS) serial.o quadTree.o

serial.o: serial.cpp body.h quadTree.cpp
	$(CC) -c $(CFLAGS) serial.cpp

clean:
	rm -f *.o $(TARGETS) *.stdout *.txt
