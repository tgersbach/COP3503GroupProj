#include <iostream>
#include "Board.h"
using namespace std; 

class UI
{
protected:
	int winSize; 
	int boardSize; 

public:
	virtual void run(); 
	virtual void playGameTwoPlayer(); 
	virtual void changeSettings(); 
}; 