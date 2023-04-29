CC=gcc
CFLAGS=-I.

all: hang

hang: hang.c STRING.c DRAW.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f hang
