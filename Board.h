#include <iostream>
using namespace std; 

class Board
{
private:
	
	int cursor[2]; 
	int const boardSize = 19; 
	int board[boardSize][boardSize]; 

public:
	Board(int size); 
	~Board(); 

	virtual void change(int row, int column, int player); 
	virtual void checkWin(int rowStart, int columnStart, int winSize); 
	virtual void printBoard(); 
}