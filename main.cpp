#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

int main() 
{   
    
    MinesweeperBoard board(10, 20, DEBUG);
    MSBoardTextView view(board);
    view.text_display();

    MSTextController ctrl(board, view);

    ctrl.play();
    
      
};