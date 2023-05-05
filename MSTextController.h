#ifndef MSTEXTCONTROLLER_H
#define MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{
    public:
    MSTextController(MinesweeperBoard& board, MSBoardTextView& view);
    int gamemode;
    int x;
    int y;
    char flag;
    void play();

    private:
    bool change_detection;
    MinesweeperBoard &board;
    MSBoardTextView &view;
    
};






#endif //MSTEXTCONTROLLER_H