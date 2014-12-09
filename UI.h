#include <iostream>
#include "Board.h"
using namespace std; 

//PROJ 3 UI.h
//By Alexis Benter, Elana Bobelis, Patric Bradley, Tyler Gersbach, and Ryan Lieblein
class UI
{
protected:
	int winSize;		//The exact amount of consecutive pieces needed to win
	int boardSize;		//The size of the board (always 19)
	char cursorChar;	//The character used for the cursor

public:
	//Constructor
	UI(){winSize = 5; cursorChar = '*';};

	virtual void run();					//Runs the main menu
	virtual void playGameTwoPlayer();	//Plays a two player local game
	virtual void changeSettings();		//Changes the settings of Gomoku
}; 