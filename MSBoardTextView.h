#ifndef MSBOARDTEXTVIEW_H
#define MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"


class MSBoardTextView
{
    

    private:
    MinesweeperBoard &board;
    

    public:
    MSBoardTextView(MinesweeperBoard &board);
    void text_display();
    bool change_detection;
    int height;
    int width;
    

};



#endif //MSBOARDTEXTVIEW_H