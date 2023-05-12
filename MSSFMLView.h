#ifndef MSSFMLVIEW_H
#define MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>


class MSSFMLView
{
    private:
    MinesweeperBoard &board;
    

    public:
    int tileSize;
    void drawCountedMines(sf::RenderWindow &window, int tileSize, int x, int y);
    MSSFMLView(MinesweeperBoard &board);
    void renderCountedMines(sf::RenderWindow &window);
    void grahpic_display();
    void drawMine(sf::RenderWindow &window, int tileSize, int x, int y);
    void drawFlag(sf::RenderWindow &window,MinesweeperBoard &board, int tileSize, int x, int y, int windowWidth, int windowHeight);
    void renderFlags(sf::RenderWindow &window);
    void renderMines(sf::RenderWindow &window);
    void renderBoard(sf::RenderWindow &window, int tileSize, int width, int height);
    void renderAllMines_win(sf::RenderWindow &window);
    void renderAllMines_loss(sf::RenderWindow &window);
    void graphic_death_view(sf::RenderWindow &window);
    void graphic_win_view(sf::RenderWindow &window);
    
    int windowWidth, windowHeight;

};







#endif //MSSFMLVIEW_H