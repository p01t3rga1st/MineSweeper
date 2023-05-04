CC = g++
CFLAGS = -Wall -g

SRCS = main.cpp MinesweeperBoard.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = saper

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

main.o: main.cpp MinesweeperBoard.h
	$(CC) $(CFLAGS) -c main.cpp

MinesweeperBoard.o: MinesweeperBoard.cpp MinesweeperBoard.h
	$(CC) $(CFLAGS) -c MinesweeperBoard.cpp

clean:
	rm -f $(OBJS) $(EXEC)