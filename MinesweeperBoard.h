#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H


struct Field 
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode {DEBUG, EASY, NORMAL, HARD};
enum GameState {RUNNING, FINISHED_WIN, FINISHED_LOSS};
void debug_play();



class MinesweeperBoard 
{
    int mines_num = 0;
    GameState current_game_state;
    GameMode current_game_mode;
    Field board[100][100];
    int width;
    int height;
    bool hasFlag(int row, int col) const;
    bool isRevealed(int row, int col) const;
    

    public:
    
    void clearBoard(int width, int height);
    void debug_display() const;
    MinesweeperBoard(int width, int height, GameMode mode);
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    int getGameState() const;
    int countMines(int row, int col) const;
    char getFieldInfo(int row, int col) const; 
    bool alreadyMoved;
    void die();

};
#endif //MINESWEEPERBOARD_H