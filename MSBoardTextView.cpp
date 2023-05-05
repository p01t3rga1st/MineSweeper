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

   
   
   std::cout << "   ";
   
   for (int i = 0; i < width; i++) 
   {
      std::cout << "  " << i << "  ";
   }
   std::cout << std::endl;

   for (int i = 0; i < height; i++) 
   {
      if(i<10)
      std::cout << i << "  ";
      else
      std::cout << i << " ";
      for (int j = 0; j < width; j++) 
      {
         std::cout << "[";
         if (board.board[i][j].hasMine == true && board.board[i][j].isRevealed == true)
            std::cout << "M";
         else
            std::cout << ".";
         if (board.board[i][j].isRevealed == true && board.board[i][j].hasMine == false)
            std::cout << board.countMines(i,j);
         else
            std::cout << ".";
         if (board.board[i][j].hasFlag == true)
            std::cout << "f";
         else
            std::cout << ".";
            std::cout << "]";
      }
      std::cout << std::endl;
   }

   
   
}

void MSBoardTextView::death_view()
{
   std::cout << std:: endl;
   std::cout << std:: endl;
   std::cout << "Rozlozenie min" << std:: endl;

   int width = board.getBoardWidth();
   int height = board.getBoardHeight();
   

   for (int j = 0; j < height; j++) 
   {
      for (int i = 0; i < width; i++) 
      {
         //std::cout << i << j << std::endl;
         board.revealField(j,i);
      }
   }

   for (int i = 0; i < width; i++) 
   {
      std::cout << "  " << i << "  ";
   }
   std::cout << std::endl;

   for (int i = 0; i < height; i++) 
   {
      if(i<10)
      std::cout << i << "  ";
      else
      std::cout << i << " ";
      for (int j = 0; j < width; j++) 
      {
         std::cout << "[";
         if (board.board[i][j].hasMine == true)
            std::cout << "M";
         else
            std::cout << ".";
         if (board.board[i][j].isRevealed == true && board.board[i][j].hasMine == false)
            std::cout << "o";
         else
            std::cout << ".";
         if (board.board[i][j].hasFlag == true)
            std::cout << "f";
         else
            std::cout << ".";
         std::cout << "]";
      }
      std::cout << std::endl;
   }
}