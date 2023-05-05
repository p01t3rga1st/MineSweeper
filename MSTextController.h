#ifndef MSTEXTCONTROLLER_H
#define MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{
    public:
    MSTextController(MinesweeperBoard& board, MSBoardTextView& view);
    int gamemode;
    
    void play();
    private:
    MinesweeperBoard &board;
    MSBoardTextView &view;
    int x;
    int y;
};






#endif //MSTEXTCONTROLLER_H