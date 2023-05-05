#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

int main() 
{
    
    MinesweeperBoard board(10, 20, DEBUG);
    MSBoardTextView view(board);
    view.text_display();

    //MSTextController(board, view);

    //ctrl.play();
    
      
};