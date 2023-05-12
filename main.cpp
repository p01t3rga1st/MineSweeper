#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"

using std::cout;
using std::endl;
using std::cin;

int main() 
{
    MinesweeperBoard board(5, 5, HARD);

    char choice;
    cout << "       Minesweeper     " << std::endl;
    cout << "Choose mode: t - TEXT g - GUI" << std::endl;
    cin >> choice;

    if(choice =='t')
    {
        MSBoardTextView view_textmode(board);
        view_textmode.text_display();
        MSTextController ctrl_textmode(board, view_textmode);
        ctrl_textmode.play();
    }
    else if(choice == 'g')
    {
        MSSFMLView view_graphicmode(board);
        MSSFMLController ctrl_graphicmode(board, view_graphicmode);
        ctrl_graphicmode.play();
    }
       
};