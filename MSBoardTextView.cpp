#include <iostream>
#include <cstdlib>
#include <string>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"


MSBoardTextView::MSBoardTextView(MinesweeperBoard &board) : board(board) {}



void MSBoardTextView::text_display()
{
   
   int width = board.getBoardWidth();
   int height = board.getBoardHeight();
   this->board = board;
   
   

   std::cout << "  ";
   
   for (int i = 0; i < width; i++) 
   {
      std::cout << "  " << i << "  ";
   }
   std::cout << std::endl;

   for (int i = 0; i < height; i++) 
   {
      std::cout << i << " ";
      for (int j = 0; j < width; j++) 
      {
         std::cout << "[";
         if (board[i][j].hasMine == true && board[i][j].isRevealed == true)
            std::cout << "M";
         else
            std::cout << ".";
         if (board[i][j].isRevealed == true && board[i][j].hasMine == false)
            std::cout << "o";
         else
            std::cout << ".";
         if (board[i][j].hasFlag == true)
            std::cout << "f";
         else
            std::cout << ".";
         std::cout << "]";
      }
      std::cout << std::endl;
   }
}