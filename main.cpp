#include "MinesweeperBoard.h"
//#include "MinesweeperBoard.cpp"
#include "MSBoardTextView.h"
//#include "MSBoardTextView.cpp"

int main() 
{
    
    MinesweeperBoard board(10, 20, DEBUG);
    MSBoardTextView view(board);
    view.text_display();

    //MSTextController(board, view);

    //ctrl.play();
    
      
};