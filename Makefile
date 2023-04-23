CC=gcc
CFLAGS=-I.

all: myprogram

myprogram: hang.c sport.c general.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f myprogram
