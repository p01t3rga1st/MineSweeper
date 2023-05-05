#ifndef MSBOARDTEXTVIEW_H
#define MSBOARDTEXTVIEW_H
//#include "MinesweeperBoard.h"

class MSBoardTextView
{
    

    private:
    MinesweeperBoard &board;

    public:
    MSBoardTextView(MinesweeperBoard &board);
    void text_display();
    

};

class MSTextController
{
    void play();
};

#endif //MSBOARDTEXTVIEW_H