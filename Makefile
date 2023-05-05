CC = g++
CFLAGS = -Wall -g
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = saper

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(EXEC)

main.o: main.cpp MinesweeperBoard.h
	$(CC) $(CFLAGS) -c main.cpp

MinesweeperBoard.o: MinesweeperBoard.cpp MinesweeperBoard.h
	$(CC) $(CFLAGS) -c MinesweeperBoard.cpp

clean:
	rm -f $(OBJS) $(EXEC)
