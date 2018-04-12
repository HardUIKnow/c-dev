CC = g++
CFLAGS = -W -Wall -g
LDFLAGS =

SRC = $(wildcard *.cpp)
OBJS = $(SRC:.c=.o)
AOUT = prog

all : $(AOUT)

prog : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean :
	@rm *.o
cleaner : clean
	@rm $(AOUT)

run :
	$(AOUT)
