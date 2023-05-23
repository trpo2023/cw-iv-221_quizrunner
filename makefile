CC=gcc
CFLAGS=-Wall -o
SOURCE = main.c
OBJECTS=$(SOURCE:.c=.o)
EXECUTABLE= quiz
all:
	$(CC) $(CFLAGS) $(EXECUTABLE) $(SOURCE)

clean:
	rm -rf *.o quiz