#include <iostream>
#include <cstdlib>
#include <string>
#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view) : board(board), view(view) {}


void MSTextController::play()
{
    std::cout << "Wybierz tryb gry:" << std::endl;
    std::cout << "EASY - 1" << std::endl;
    std::cout << "NORMAL - 2" << std::endl;
    std::cout << "HARD - 3" << std::endl;
    std::cout << "WYJSCIE - 4" << std::endl;
    std::cout << "DEBUG - 0" << std::endl;
    std::cin >> gamemode;

    std::cout << "Wybierz wysokosc planszy" << std::endl;
    std::cin >> y;

    std::cout << "Wybierz szerokosc planszy" << std::endl;
    std::cin >> x;


    if (gamemode == 0) 
    {
        MinesweeperBoard board(x, y, DEBUG);
    }
    else if (gamemode == 1) 
    {
        MinesweeperBoard board(x, y, EASY);
    }
    else if (gamemode == 2) 
    {
        MinesweeperBoard board(x, y, NORMAL);
    }
    else if (gamemode == 3) 
    {
        MinesweeperBoard board(x, y, HARD);
    }
    else if (gamemode == 4) 
    {
        exit(0);
    }


    
}


/*
Kontroler

Rozbuduj aplikację do kompletnej, działającej w trybie tekstowym gry.

Dodaj do projektu kolejną klasę - MSTextController. Konstruktor tej klasy powinien otrzymać planszę oraz "widok". Klasa ma jedną funkcję - play() - w tej funkcji implementujemy "komunikację" z graczem (człowiekiem).

W tej klasie MOŻNA używać cin ;)

*/

