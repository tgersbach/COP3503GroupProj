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

}

void Board::printBoard()
{
	/*This function, on the otherhand, is very simple. All that's neccessary is to print out the board by iterating
	through the matrix. Keep checking whether a piece is the cursor, and if it is, print out cursorChar instead. */
}