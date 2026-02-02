CC := gcc
CFLAGS := -Wall -std=c99 -Wno-missing-braces
INC = -I include/
LIB = -L lib/ -lraylib -lgdi32 -lwinmm
SUP = -Wl,--subsystem,windows

lmusiclayout: lmusiclayout.o
	$(CC) lmusiclayout.o $(SUP) -o lmusiclayout $(LIB)

lmusiclayout.o: lmusiclayout.c
	$(CC) -c lmusiclayout.c $(CFLAGS) $(INC)

clean:
	rm *.o
