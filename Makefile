CC=gcc
CFLAGS= -c -std=c11 -Werror -Wall -Wconversion

all: app

app: main.o arraylist.o #ui.o
	$(CC) main.o arraylist.o -o app
	
main.o: main.c
	$(CC) $(CFLAGS) main.c

arraylist.o: arraylist.c
	$(CC) $(CFLAGS)  arraylist.c 

clean:
	rm -rf *.o app