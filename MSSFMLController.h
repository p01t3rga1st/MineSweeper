#ifndef MSSFMLCONTROLLER_H
#define MSSFMLCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>

class MSSFMLController
{
    public:
    MSSFMLController(MinesweeperBoard& board, MSSFMLView& view);
    void play();
    MinesweeperBoard &board;
    MSSFMLView &view;

    private:
    
    
    
    
};





#endif //MSSFMLCONTROLLER_H