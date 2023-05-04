
#include "MinesweeperBoard.h"
#include "MinesweeperBoard.cpp"


int main() 
{
    MinesweeperBoard board(10, 10, DEBUG);
    board.debug_display();
    return 0;
};