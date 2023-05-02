CC=gcc
CFLAGS=-I.

all: hang

hang: hang.c STRING.c DRAW.c TEXTCONVERTER.c SCORE.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f hang
