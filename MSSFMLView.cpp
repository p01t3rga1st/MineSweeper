#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : board(board){}

void MSSFMLView::grahpic_display()
{
    int width = board.getBoardWidth();
    int height = board.getBoardHeight();

    int windowWidth = width * 75;
    int windowHeight = height * 75;

    tileSize = windowWidth / width;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Minesweeper");
        
    // główna pętla gry
    while (window.isOpen())
    {
        renderBoard(window, tileSize, width, height);
        renderFlags(window);
        renderMines(window);
        renderCountedMines(window);


        if(board.getGameState() == FINISHED_LOSS)
        {
            graphic_death_view(window);         
        }
        if(board.getGameState() == FINISHED_WIN)
        {
            graphic_win_view(window);      
        }

        // obsługa zdarzeń
        sf::Event event;
        while (window.pollEvent(event))
        {
            

            // zamknięcie okna
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            

            if (event.type == sf::Event::MouseButtonPressed)
            {
                int y = event.mouseButton.y / tileSize;
                int x = event.mouseButton.x / tileSize;

                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    board.revealField(x,y);
                    board.check_win();
                    std::cout << "left click: " << x << y << std::endl;
                    std::cout << "Game Status"<< std::endl;
                    std::cout << board.getGameState() << std::endl;
                    

                }
                if(event.mouseButton.button == sf::Mouse::Right)
                {
                    board.toggleFlag(x,y);
                    board.check_win();
                    std::cout << "right click: " << x << y << std::endl;
                    std::cout << "Game Status"<< std::endl;
                    std::cout << board.getGameState() << std::endl;
                    
                    
                }
                
                
            }
        }
        
        
        
        window.display();
    }
    
    return;
}

void MSSFMLView::renderBoard(sf::RenderWindow &window, int tileSize, int width, int height)
{
    sf::RectangleShape tiles[width][height];

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {

            sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
            tile.setPosition(x * tileSize, y * tileSize);
            tile.setFillColor(sf::Color::Black);
            tile.setOutlineColor(sf::Color::White);
            tile.setOutlineThickness(1.0f);
            
            tiles[x][y] = tile;
        }
    }
    
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            window.draw(tiles[x][y]);
        }
    }
}

void MSSFMLView::drawMine(sf::RenderWindow &window, int tileSize, int x, int y)
{
    float posx_fixed = x * tileSize + tileSize/4;
    float posy_fixed = y * tileSize + tileSize/4;

    float mineRadius = tileSize / 4;
    sf::CircleShape mine(mineRadius, 8);
    mine.setFillColor(sf::Color::Red);
    mine.setOutlineThickness(2.0f);
    mine.setOutlineColor(sf::Color::Red);
    mine.setPosition(posx_fixed, posy_fixed);

    window.draw(mine);
}

void MSSFMLView::drawFlag(sf::RenderWindow &window,MinesweeperBoard &board, int tileSize, int x, int y, int windowWidth, int windowHeight)
{
    float posx_fixed = x * tileSize + tileSize/4;
    float posy_fixed = y * tileSize + tileSize/4;

    int width = board.getBoardWidth();
    int height = board.getBoardHeight();
    sf::RectangleShape flag(sf::Vector2f(width*2, height*2));
    flag.setFillColor(sf::Color::Blue);
    flag.setOutlineThickness(2.0f);
    flag.setOutlineColor(sf::Color::Blue);
    flag.setPosition(posx_fixed, posy_fixed);

    window.draw(flag);
}


void MSSFMLView::renderFlags(sf::RenderWindow &window)
{
    int width = board.getBoardWidth();
    int height = board.getBoardHeight();
    
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            if(board.board[x][y].hasFlag == true)
            {
                drawFlag(window, board, tileSize, x, y, windowWidth, windowHeight);  
            }
        }
    }
}

void MSSFMLView::renderMines(sf::RenderWindow &window)
{   
    int width = board.getBoardWidth();
    int height = board.getBoardHeight();

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            if(board.board[x][y].hasMine == true && board.board[x][y].isRevealed == true)
            {
                drawMine(window, tileSize, x, y);
            }
        }
    }

}

void MSSFMLView::renderAllMines_win(sf::RenderWindow &window)
{   
    int width = board.getBoardWidth();
    int height = board.getBoardHeight();

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            if(board.board[x][y].hasMine == true)
            {
                float posx_fixed = x * tileSize + tileSize/4;
                float posy_fixed = y * tileSize + tileSize/4;

                float mineRadius = tileSize / 4;
                sf::CircleShape mine(mineRadius, 8);
                mine.setFillColor(sf::Color::Green);
                mine.setOutlineThickness(2.0f);
                mine.setOutlineColor(sf::Color::Green);
                mine.setPosition(posx_fixed, posy_fixed);

                window.draw(mine);
            }
        }
    }

}

void MSSFMLView::renderAllMines_loss(sf::RenderWindow &window)
{   
    int width = board.getBoardWidth();
    int height = board.getBoardHeight();

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            if(board.board[x][y].hasMine == true)
            {
                float posx_fixed = x * tileSize + tileSize/4;
                float posy_fixed = y * tileSize + tileSize/4;

                float mineRadius = tileSize / 4;
                sf::CircleShape mine(mineRadius, 8);
                mine.setFillColor(sf::Color::Red);
                mine.setOutlineThickness(2.0f);
                mine.setOutlineColor(sf::Color::Red);
                mine.setPosition(posx_fixed, posy_fixed);

                window.draw(mine);
            }
        }
    }

}

void MSSFMLView::drawCountedMines(sf::RenderWindow &window, int tileSize, int x, int y)
{
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(tileSize / 2);
    text.setFillColor(sf::Color::White);
    text.setString(std::to_string(board.countMines(x, y)));       

    float posx_fixed = x * tileSize + tileSize/2 - text.getLocalBounds().width/2;
    float posy_fixed = y * tileSize + tileSize/2 - text.getLocalBounds().height/2;
    text.setPosition(posx_fixed, posy_fixed);

    window.draw(text);
}

void MSSFMLView::renderCountedMines(sf::RenderWindow &window)
{   
    int width = board.getBoardWidth();
    int height = board.getBoardHeight();

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            if(board.board[x][y].isRevealed == true && board.board[x][y].hasMine == false)
            {
                drawCountedMines(window, tileSize , x, y);
            }
        }
    }

}

void MSSFMLView::graphic_death_view(sf::RenderWindow &window)
{
    renderAllMines_loss(window);  
}

void MSSFMLView::graphic_win_view(sf::RenderWindow &window)
{
   renderAllMines_win(window);
}