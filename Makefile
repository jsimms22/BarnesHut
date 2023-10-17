CC = gcc
CFLAGS = -O3 -Wall
LIBS = 

TARGETS = serial

all: $(TARGETS)

serial: forcepairs.o quadTree.o
	$(CC) -o $@ $(LIBS) forcepairs.o quadTree.o

serial.o: serial.cpp body.h quadTree.cpp
	$(CC) -c $(CFLAGS) serial.cpp

clean:
	rm -f *.o $(TARGETS) *.stdout *.txt
