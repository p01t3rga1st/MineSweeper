
#include "MinesweeperBoard.h"
#include "MinesweeperBoard.cpp"


int main() {
    std::cout<< "start" << std::endl;
    MinesweeperBoard board(10, 10, EASY); 
    board.debug_display();
    std::cout<< "done" << std::endl;
    return 0;
};