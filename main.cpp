
#include "MinesweeperBoard.h"
#include "MinesweeperBoard.cpp"


int main() {
    std::cout<< "start" << std::endl;
    MinesweeperBoard board(10, 10, DEBUG); 
    board.debug_display();
    std::cout<< "done" << std::endl;
    

    board.revealField( 1, 1);
    char symbol = board.getFieldInfo( 1, 1);
    std::cout << symbol << std::endl;

    return 0;
};