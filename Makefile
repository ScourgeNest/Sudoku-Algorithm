#Niculici Mihai-Daniel 315 CA
# compiler setup
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# define targets
TARGETS = another_queries

build: $(TARGETS)

another_queries: another_queries.c
	$(CC) $(CFLAGS) another_queries.c -o another_queries

pack:
	zip -FSr 315CA_NiculiciMihai-Daniel_Tema1.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean