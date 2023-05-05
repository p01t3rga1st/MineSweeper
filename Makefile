CC = g++
CFLAGS = -Wall -g
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp MinesweeperBoard.cpp MSBoardTextView.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = saper

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(EXEC)

main.o: main.cpp MinesweeperBoard.h MSBoardTextView.h
	$(CC) $(CFLAGS) -c main.cpp

MinesweeperBoard.o: MinesweeperBoard.cpp MinesweeperBoard.h
	$(CC) $(CFLAGS) -c MinesweeperBoard.cpp

MSBoardTextView.o: MSBoardTextView.cpp MSBoardTextView.h MinesweeperBoard.h
	$(CC) $(CFLAGS) -c MSBoardTextView.cpp

$(OBJS): MinesweeperBoard.h MSBoardTextView.h

clean:
	rm -f $(OBJS) $(EXEC)
