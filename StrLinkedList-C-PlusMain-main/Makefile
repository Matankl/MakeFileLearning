CC = gcc
CFLAGS = -Wall -Wextra -g

OBJS = StrList.o Main.o

all: StrList

StrList: $(OBJS)
	$(CC) $(CFLAGS) -o StrList $(OBJS)

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c

Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c

clean:
	rm -f $(OBJS) StrList
