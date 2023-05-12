#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "MSSFMLController.h"
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

MSSFMLController::MSSFMLController(MinesweeperBoard& board, MSSFMLView& view) : board(board), view(view) {}

void MSSFMLController::play()
{
    view.grahpic_display();
}