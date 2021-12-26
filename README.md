# Linked List implementation in C language

---
## Requirements

For development, you will need `build-essential` dependencies installed in your environement.

### Dependencies installation

    $ sudo apt-get install build-essential make gcc

## Compilation the project

    $ make all
    gcc -c -std=c11 -Werror -Wall -Wconversion -lm main.c
    gcc -c -std=c11 -Werror -Wall -Wconversion -lm  arraylist.c 
    gcc main.o arraylist.o -o app

## Running the project

    $ ./app
