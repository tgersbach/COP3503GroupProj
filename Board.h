#include <iostream>
using namespace std; 

class Piece
{
  private:
    //Each 'piece' on the board has two components, which player it belongs to
    //(0 = no player, 1 = main player, 2 = second player/AI), and if that position
    //is where the cursor is.
    char player;
    bool isCursor;

  public:
    //Constructors
    Piece() { this->player = '0'; this->isCursor = false; }
    Piece(char playerType) { this->player = playerType; this->isCursor = false; }

    //Standard get and mutator methods
    virtual char getPlayer() { return this->player; }
    virtual void changePlayer(char newPlayer) { this->player = newPlayer; }
    virtual bool cursor() { return isCursor; }
    virtual bool changeCursor(bool arg) { this->isCursor = arg; }
};

class Board
{
  private:
    int cursor[2];
    static const int boardSize = 19;
    Piece board[boardSize][boardSize];
    char cursorChar;
  
    /* checkWin() related */
    bool win;
    int winSize, winCount, sectorSize, numDiags;
  
    /* Start positions for diagonals */
    int lsf_row, lsf_col;
    int mf_row, mf_col;
    int rsf_row, rsf_col;
    int lsb_row, lsb_col;
    int mb_row, mb_col;
    int rsb_row, rsb_col;
  
    /* Counters for diagonals */
    int lsf_count, rsf_count, lsb_count, rsb_count;

  public:
    Board(int winSize);
    ~Board();

    virtual void change(int row, int column, int player);
    virtual void checkWin();
    virtual void printBoard(); 
};