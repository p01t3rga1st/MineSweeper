#ifndef MSBOARDTEXTVIEW_H
#define MSBOARDTEXTVIEW_H


class MSBoardTextView
{
    

    private:
    MinesweeperBoard &board;
    int width = board.getBoardWidth();
    int height = board.getBoardHeight();

    public:
    MSBoardTextView(MinesweeperBoard &board);
    void text_display();
    bool change_detection;
    

};



#endif //MSBOARDTEXTVIEW_H