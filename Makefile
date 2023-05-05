CC = g++
CFLAGS = -Wall -g
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp MinesweeperBoard.cpp MSBoardTextView.cpp MSTextController.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = saper

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(EXEC)

main.o: main.cpp MinesweeperBoard.h MSBoardTextView.h MSTextController.h
	$(CC) $(CFLAGS) -c main.cpp

MinesweeperBoard.o: MinesweeperBoard.cpp MinesweeperBoard.h
	$(CC) $(CFLAGS) -c MinesweeperBoard.cpp

MSBoardTextView.o: MSBoardTextView.cpp MSBoardTextView.h MinesweeperBoard.h
	$(CC) $(CFLAGS) -c MSBoardTextView.cpp

MSTextController.o: MSTextController.cpp MSTextController.h MSBoardTextView.h MinesweeperBoard.h
	$(CC) $(CFLAGS) -c MSTextController.cpp

$(OBJS): MinesweeperBoard.h MSBoardTextView.h MSTextController.h

clean:
	rm -f $(OBJS) $(EXEC)
