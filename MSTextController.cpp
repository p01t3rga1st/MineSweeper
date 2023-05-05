#include <iostream>
#include <cstdlib>
#include <string>
#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view) : board(board), view(view) {}


void MSTextController::play()
{
    while(board.getGameState() == RUNNING)
    {

        std::cout << "Wpisz koordynaty np:x y aby onznaczyć flage wpisz po koordynatach 'f' jesli chcesz odkryc pole wpisz r" << std::endl;
        std::cin >> y;
        std::cin >> x;
        std::cin >> flag;

        if(flag == 'f')
        board.toggleFlag(x,y);
        else if(flag == 'r')
        board.revealField(x,y);

        view.text_display();

    }

    view.death_view();


}


/*
Kontroler

Rozbuduj aplikację do kompletnej, działającej w trybie tekstowym gry.

Dodaj do projektu kolejną klasę - MSTextController. Konstruktor tej klasy powinien otrzymać planszę oraz "widok". Klasa ma jedną funkcję - play() - w tej funkcji implementujemy "komunikację" z graczem (człowiekiem).

W tej klasie MOŻNA używać cin ;)

*/

