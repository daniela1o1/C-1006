CC = gcc
PROG = card_simulator

CFLAGS = -Wall -Wextra -Werror -g -Iinclude
LDFLAGS =
LIBS =

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LIBS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(PROG)
	./$(PROG)

clean:
	rm -f $(OBJ) $(PROG)

.PHONY: all clean run
