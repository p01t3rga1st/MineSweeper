#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"


void MinesweeperBoard::debug_display() const 
{

   int width = getBoardWidth();
   int height = getBoardHeight();

   if (height > 100 || width > 100) 
   {
      std::cout << "Size Error" << std::endl;
      std::cout << "debug_display " << height << std::endl;
      std::cout << "debug_display " << width << std::endl;

      exit(1);
   }

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

/*
void debug_play() 
{
   

   int menu_gamemode;
   int menu_height;
   int menu_width;

   std::cout << "LESS THAN 100! Height:" << std::endl;
   std::cin >> menu_height;

   std::cout << "LESS THAN 100! Width:" << std::endl;
   std::cin >> menu_width;

   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << std::endl;

   std::cout << "Gamemode:" << std::endl;
   std::cout << "Easy: '1'" << std::endl;
   std::cout << "Normal: '2'" << std::endl;
   std::cout << "Hard: '3'" << std::endl;
   std::cout << "Debug: '4'" << std::endl;

   std::cin >> menu_gamemode;

   


   switch(menu_gamemode)
   {
      case 1:
      {
         MinesweeperBoard board(menu_width, menu_height, EASY);
      }
         break;
      case 2:
      {
         MinesweeperBoard board(menu_width, menu_height, NORMAL);
      }   
         break;
      case 3:
      {
         MinesweeperBoard board(menu_width, menu_height, HARD);
      }
         break;
      case 4:
      {
         MinesweeperBoard board(menu_width, menu_height, DEBUG);
      }
         break;
   }

} */


void MinesweeperBoard::clearBoard(int width, int height) 
{
   for (int i = 0; i < width; i++) 
   {
      for (int j = 0; j < height; j++) 
      {
         board[i][j].hasMine = false;
         board[i][j].isRevealed = false;
         board[i][j].hasFlag = false;
      }
   }
   std::cout << "clearBoard DEBUG " << getBoardWidth() << std::endl;
   std::cout << "clearBoard DEBUG " << getBoardHeight() << std::endl;
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode): height(height) 
{

   //std::cout<< height << std::endl;
   //std::cout<< width << std::endl;

  this->width = width;
   
   alreadyMoved = false;
   current_game_state = RUNNING;

   MinesweeperBoard::clearBoard(width, height);

   switch (mode) 
   {
    case EASY:
      mines_num = width * height * 0.1;
      break;
    case NORMAL:
      mines_num = width * height * 0.2;
      break;
    case HARD:
      mines_num = width * height * 0.3;
      break;
    case DEBUG:
      mines_num = width * height * 0.3;

      int x = 0;
      int y = 0;

      for (x = 0; x < width; x++) 
      {
         board[0][x].hasMine = true;
      }

      // zapelanianie pierwszego rzedu bobmami

      for (y = 0; y < height; y++) 
      {
         if (y % 2 == 0) 
         {
            board[y][0].hasMine = true;
         }
      }

      // zapelanianie pierwszej kolumny bombami co druga pozycje (modulo od 2)

      
         for (int i = 0; i < height; i++) 
         {
            board[i][i].hasMine = true;
         }

      // zapelnanie bombami po skosie 

      break;

   }

   if (mode != DEBUG) 
   {
      while (mines_num > 0) 
      {
         int x = rand() % width;
         int y = rand() % height;
         if (!board[x][y].hasMine) 
         {
            board[x][y].hasMine = true;
            mines_num--;
         }

      }
   }
   else
   std::cout << "DEBUG MODE, NO RANDOM MINES PLACEMENT" << std::endl;

   // warunek while sprawdza czy pozostaly jakies miny w "magazynie"
   //wybiera losową pozycję z planszy 
   //warunek if sprawdza czy nie ma miny juz na polu
   //w if znajduje sie zmiana atrubutu hasmine na 1
   // odejmujemy bombe bo juz ja uzylismy dekrementacja

   std::cout << "MinesweeperBoard DEBUG " << getBoardWidth() << std::endl;
   std::cout << "MinesweeperBoard DEBUG " << getBoardHeight() << std::endl;
   return;
}

int MinesweeperBoard::getBoardWidth() const 
{
   return width;
};

int MinesweeperBoard::getBoardHeight() const 
{
   return height;
};

int MinesweeperBoard::getMineCount() const 
{
   return mines_num;
};

int MinesweeperBoard::countMines(int row, int col) const 
{
   // sprawdzenie czy pole nie jest juz odkryte
   if (!isRevealed(row, col)) {
      return -1;
   }

   // sprawdzenie czy pole nie zjaduje sie poza plansza
   if (row < 0 || row >= height || col < 0 || col >= width) {
      return -1;
   }

   int mines_count = 0;

   // Petla szukajaca wokol pola poczatkowego
   for (int i = row - 1; i <= row + 1; i++) {
      for (int j = col - 1; j <= col + 1; j++) {
         // Sprawdzenie czy pola sasiadujace sa w tablicy
         if (i >= 0 && i < height && j >= 0 && j < width) {
            // Sprawdzenie czy maja mine
            if (board[i][j].hasMine) {
               mines_count++;
            }
         }
      }
   }

   return mines_count;
}

bool MinesweeperBoard::hasFlag(int row, int col) const 
{
   // sprawdzenie czy pole nie wychodzi poza zakres
   if (row < 0 || row >= height || col < 0 || col >= width) {
      return false;
   }

   Field field = board[row][col];

   // sprawdzenie czy pole ma flage i czy jest odkryte
   if (field.hasFlag && !field.isRevealed) {
      return true;
   }

   return false;
}

void MinesweeperBoard::toggleFlag(int row, int col) 
{

   // check if game is already finished

   if (current_game_state != RUNNING) {
      return;
   }

   // check if row or col is outside the board
   if (row < 0 || row >= height || col < 0 || col >= width) {
      return;
   }

   // get the field at (row,col) position
   Field & field = board[row][col];

   // check if the field is already revealed
   if (field.isRevealed) {
      return;
   }

   // toggle the flag status of the field
   field.hasFlag = !field.hasFlag;
}

bool MinesweeperBoard::isRevealed(int row, int col) const 
{
   Field field = board[row][col];
   if (field.isRevealed) {
      return true;
   }
   return false;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const 
{
   // sprawdzenie czy kolumna i wiersz nie sa za plansza

   if (row < 0 || row >= height || col < 0 || col >= width) {
      return '#';
   }

   // Pozycja pola
   const Field & field = board[row][col];

   // Sprawdzenie czy pole ma falge i nie jest odkryte
   if (field.hasFlag && !field.isRevealed) {
      return 'F';
   }

   // Sprawdzenie czy pole nie jest odkryte
   if (field.isRevealed) {
      return '_';
   }

   // Sprawdzenie czy pole jest odkryte i czy ma mine
   if (field.hasMine) {
      return 'x';
   }

   // Sprawdzenie czy pole jest odkryte i czy ma zero min 
   if (countMines(row, col) == 0) {
      return ' ';
   }

   // Sprawdzenie czy pole jest odkryte i liczenie min
   return countMines(row, col);
}

void MinesweeperBoard::die()
{
   current_game_state = FINISHED_LOSS;
}

int MinesweeperBoard::getGameState() const 
{
   return current_game_state;
}

void MinesweeperBoard::revealField(int row, int col)
{
   const Field & field = board[row][col];
   
   if(field.isRevealed)
   {
      return;
   }

   if(row < 0 || row >= height || col < 0 || col >= width)
   {
      return;
   }

   if(getGameState() != RUNNING)
   {
      return;
   }

   if(field.hasFlag)
   {
      return;
   }

   if(!field.isRevealed)
   {
      board[row][col].isRevealed = true;
      alreadyMoved = true;
   }

   if(field.hasMine)
   {
      if(alreadyMoved == true || current_game_mode == DEBUG)
      {
         die();
         std::cout << "You died" << std::endl;
      }
      else
      {
         mines_num = 1;
         while(mines_num > 0)
         {
            int x = rand() % width;
            int y = rand() % height;
            if (!board[x][y].hasMine) 
            {
               board[x][y].hasMine = true;
               mines_num--;
            }
         }
      }
   }

   

   // try to reveal the field at (row,col)
  //
  // If the field was not revealed and there is no mine on it - reveal it
  // If the field was not revealed and there is a mine on it:  
  // - if its the first player action - move mine to another location, reveal field (not in DEBUG mode!)
  // - reveal it and finish game
}