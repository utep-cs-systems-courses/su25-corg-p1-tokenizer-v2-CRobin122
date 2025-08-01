CC = gcc
CFLAGS = -g -O3

all: tester

tester: tester.c tokenizer.h history.h
	$(CC) $(CFLAGS) -o tester tester.c

test: tester
	./tester

clean:
	rm -f *.0 tester
