PROG = main.exe 
SRC = main.c menu.c cards.c door.c addRemove.c fakeTestScanCard.c
CFLAGS =-Wall -Werror -g
LIBS = 
all: $(PROG)
$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 
clean:
	rm -f $(PROG)
.PHONY: all clean