CFLAGS=-g -Wall -Wextra -std=c11 -O3

.PHONY: all
all: main
main: main.c saxpy.S

.PHONY: clean
clean:
	rm -f main
