//PROJ 3 Board.h
//By Alexis Benter, Elana Bobelis, Patric Bradley, Tyler Gersbach, and Ryan Lieblein
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
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
	Piece(){this->player = '0'; this->isCursor = false;};
	Piece(char playerType){this->player = playerType; this->isCursor = false;};

	//Standard get and mutator methods
	virtual char getPlayer(){return this->player;};
	virtual void changePlayer(char newPlayer){this->player = newPlayer;};
	virtual bool cursor(){return isCursor;};
	virtual void changeCursor(bool arg){this->isCursor = arg;};
};

class Board
{
private:

	int cursor[2];	//Where the cursor is
	int boardSize;	//What size the board is
	Piece board[19][19];//The default board
	char cursorChar;	//What this board's cursor is

public:
	Board(int size); //Constructor
   
	virtual bool change(int row, int column, char player);	//Change a pieces value
	virtual void changeCur(int row, int column);			//Change the cursor's position
	virtual bool checkWin(int rowStart, int columnStart, int winSize);	//Check is a piece is a winning one
	virtual void printBoard();								//Print out the board to console
	virtual void changeCurChar(char theCur){this->cursorChar = theCur;};	//Change the character that is used for the cursor
};


