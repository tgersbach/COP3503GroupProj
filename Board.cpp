#include "Board.h"

Board::Board(int boardSize)
{
	//Setting the cursor to the default position in the board
	this->cursor[0] = 0; 
	this->cursor[1] = 0; 

	//Setting each piece on the board to a default piece 
	for(int x = 0; x < this->boardSize; x++)
	{
		for(int y = 0; y < this->boardSize; y++)
		{this->board[x][y] = Piece(); }
	}

	//The piece (zero, zero) on the board is the cursor
	this->board[cursor[0]][cursor[1]].changeCursor(true); 

	//What the representation of the cursor is (to be used for later)
	this->cursorChar = '*'; 
}

void Board::change(int row, int column, int player)
{
	//Convert the int value into a character
	char thePlayer = (char)player; 

	//If this piece on the board is already taken by a player, don't change it!
	if(this->board[row][column].getPlayer() != '0')
	{cout << "Piece cannot be changed!" << endl;}

	//Else, change the piece
	else{this->board[row][column].changePlayer(thePlayer);}
}

void Board::checkWin(int rowStart, int columnStart, int winSize)
{
	/*This method is a bit tricky. Essentially, it needs to check each cardinal direction for exacly 5 pieces consecutively owned
	by player who placed the piece at rowStart, columnStart. I believe the best format is as follows:

	2    3   4				These are the 4 'routes' you can win in. Go through 1 through 4, one after another. 
	  \  |  /				Use a while loop, end looping through the while loop once you hit a piece not owned by the owner of start. 
	1-(start)-1				Keep in mind, the amount wins must be EXACTLY winSize. By default, winSize is 5. 
      /  |  \
	4	 3   2

	*/
}

void Board::printBoard()
{
	/*This function, on the otherhand, is very simple. All that's neccessary is to print out the board by iterating
	through the matrix. Keep checking whether a piece is the cursor, and if it is, print out cursorChar instead. */
}