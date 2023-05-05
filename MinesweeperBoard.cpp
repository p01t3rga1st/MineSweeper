#include <iostream>
#include <cstdlib>
#include <string>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

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
      mine_remaning = mines_num;
      break;
    case NORMAL:
      mines_num = width * height * 0.2;
      mine_remaning = mines_num;
      break;
    case HARD:
      mines_num = width * height * 0.3;
      mine_remaning = mines_num;
      break;
    case DEBUG:
      

      int x = 0;
      int y = 0;

      

      for (x = 0; x < width; x++) 
      {
         board[0][x].hasMine = true;
         mines_num ++;
      }

      // zapelanianie pierwszego rzedu bobmami

      for (y = 0; y < height; y++) 
      {
         if (y % 2 == 0) 
         {
            board[y][0].hasMine = true;
            mines_num ++;
         }
      }

      // zapelanianie pierwszej kolumny bombami co druga pozycje (modulo od 2)

      
         for (int i = 0; i < height; i++) 
         {
            board[i][i].hasMine = true;
            mines_num ++;
         }

      // zapelnanie bombami po skosie 

      mines_num = mines_num -2;
      

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
   std::cout << "NUMBER OF MINES: ";
   std::cout << mine_remaning << std::endl;

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

void MinesweeperBoard::check_win()
{
   int width = getBoardWidth();
   int height = getBoardHeight();

   for (int j = 0; j < height; j++) 
   {
      for (int i = 0; i < width; i++) 
      {
         if(board[i][j].hasMine == true && board[i][j].hasFlag == true)
         {
            mine_remaning = getMineCount(); - 1;

            if(mine_remaning = 0)
            win(); 
         }
      }
   }

   if(current_game_mode == DEBUG)
   {
      std::cout << "Zostalo min ";
      std::cout << mine_remaning << std::endl;
   }
}

void MinesweeperBoard::die()
{
   MSBoardTextView death_view();
   
   current_game_state = FINISHED_LOSS;
   return;
}

void MinesweeperBoard::win()
{
   current_game_state = FINISHED_WIN;
   return;
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
}
