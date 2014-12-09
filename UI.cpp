//PROJ 3 UI.cpp
//By Alexis Benter, Elana Bobelis, Patric Bradley, Tyler Gersbach, and Ryan Lieblein
#include "UI.h"

int main()
{
	UI gomoku;
	gomoku.run();
}

void UI::run()
{
	bool done = false;
	while(!done)
	{ 
		//Main Menu
		cout<<"   ___        __       _    _      __    _   _    _    _  _"<<endl; 
		cout<<"0//   \\\\0000/    \\0000/  \\/  \\ 00/    \\00||//00000||  ||0||0"<<endl; 
		cout<<"0||   ___000| || |000/ /0\\/0\\ \\00| || |00||\\ 00000||  ||0||0"<<endl; 
		cout<<"0\\\\___//0000\\ __ /00/_/000000\\_\\0\\ __ /00||\\\\_0000\\\\__//0()0"<<endl; 
		cout<<"Choose one."<<endl;
		cout<<"(1) Play a local game (two players)"<<endl;
		cout<<"(2) Change settings"<<endl;
		cout<<"(3) Exit"<<endl;
		int choice = 0;
		cin >>choice;

		if(choice == 1)
		{this->playGameTwoPlayer();}
		if(choice == 2)
		{this->changeSettings();}
		if(choice == 3)
		{done = true;}
	}
}

void UI::playGameTwoPlayer()
{
	Board basicBoard(this->boardSize);			//The board on which we're playing
	basicBoard.changeCurChar(this->cursorChar); //Sets the cursor used by the board to the one selected
    char i = 0;			//Input
	int x = 0;			//Current cursor x component
	int y = 0;			//Current cursor y component
	int tieCount = 0;	//A background count just in case there is a full-board tie 
    bool one = false;	//Has player one won? 
    bool two = false;	//Has player two won? 

	//While neither player has won, run
	while(one == false && two == false){
        
			system("CLS");		//Clears the previous menus
            cout << "Player 1 turn: " << endl;
			basicBoard.printBoard(); 
            cout << "Choose a direction by using the 'wasd'." << endl;
			cout << "Select your move by hitting enter." << endl; 
			cout << "Press escape to return to the main menu."<<endl; 
            i = 0;  
		do{	//Do this while the user has not hit enter
			if(kbhit()) 
			{ 
				i = getch(); //Input is the most recent keyboard press
				if(i == char(27)){system("CLS"); return;}//If the user has pressed escape, return

				//The following algorithms are the resposes to the different actions a player can take
				if(i == 'w' && y != 0){
					basicBoard.changeCur(x, y);
					y = y-1;
					basicBoard.changeCur(x, y);
					system("CLS"); 
					cout << "Player 1 turn: " << endl;
					basicBoard.printBoard(); 
					cout << "Choose a direction by using the 'wasd'." << endl;
					cout << "Select your move by hitting enter." << endl;
					cout << "Press escape to return to the main menu."<<endl; 
				}
				else if(i == 'a' && x!=0){
					basicBoard.changeCur(x, y);
					x = x-1;
					basicBoard.changeCur(x, y);
					system("CLS"); 
					cout << "Player 1 turn: " << endl;
					basicBoard.printBoard(); 
					cout << "Choose a direction by using the 'wasd'." << endl;
					cout << "Select your move by hitting enter." << endl; 
					cout << "Press escape to return to the main menu."<<endl; 
				}
				else if(i == 's' && y!=18){
					basicBoard.changeCur(x, y);
					y = y+1;
					basicBoard.changeCur(x, y);
					system("CLS"); 
					cout << "Player 1 turn: " << endl;
					basicBoard.printBoard(); 
					cout << "Choose a direction by using the 'wasd'." << endl;
					cout << "Select your move by hitting enter." << endl; 
					cout << "Press escape to return to the main menu."<<endl; 
				}
				else if(i == 'd' && x!=18){
					basicBoard.changeCur(x, y);
					x = x+1;
					basicBoard.changeCur(x, y);
					system("CLS"); 
					cout << "Player 1 turn: " << endl;
					basicBoard.printBoard(); 
					cout << "Choose a direction by using the 'wasd'." << endl;
					cout << "Select your move by hitting enter." << endl; 
					cout << "Press escape to return to the main menu."<<endl; 

				}
				else if(i == char(13)){
					bool check = basicBoard.change(x, y, '1');
					if(check){one = basicBoard.checkWin(x, y, winSize);tieCount++;}
					else{i = '0';}
			}}
        }while(i != char(13)); 

		if(one == true)//If player one wins, declare it and return to the main menu
		{
			system("CLS"); 
			cout << "Player 1 wins!" << endl; return; 
		}

		if(tieCount == (19*19))//If we've tied, return to the main menu
		{
			cout << "Game is a tie!" << endl; return; 
		}

 			system("CLS"); 
            cout << "Player 2 turn: " << endl;
			basicBoard.printBoard(); 
            cout << "Choose a direction by using the 'wasd'." << endl;
			cout << "Select your move by hitting enter." << endl; 
			cout << "Press escape to return to the main menu."<<endl; 
			i = 0;  
		do{	if(kbhit()) 
			{
				i = getch(); 
				if(i == char(27)){system("CLS"); return;}
				if(i == 'w' && y != 0){
					basicBoard.changeCur(x, y);
					y = y-1;
					basicBoard.changeCur(x, y);
					system("CLS"); 
					cout << "Player 2 turn: " << endl;
					basicBoard.printBoard(); 
					cout << "Choose a direction by using the 'wasd'." << endl;
					cout << "Select your move by hitting enter." << endl; 
					cout << "Press escape to return to the main menu."<<endl; 
				}
				else if(i == 'a' && x!=0){
					basicBoard.changeCur(x, y);
					x = x-1;
					basicBoard.changeCur(x, y);
					system("CLS"); 
					cout << "Player 2 turn: " << endl;
					basicBoard.printBoard(); 
					cout << "Choose a direction by using the 'wasd'." << endl;
					cout << "Select your move by hitting enter." << endl; 
					cout << "Press escape to return to the main menu."<<endl; 
				}
				else if(i == 's' && y!=18){
					basicBoard.changeCur(x, y);
					y = y+1;
					basicBoard.changeCur(x, y);
					system("CLS"); 
					cout << "Player 2 turn: " << endl;
					basicBoard.printBoard(); 
					cout << "Choose a direction by using the 'wasd'." << endl;
					cout << "Select your move by hitting enter." << endl; 
					cout << "Press escape to return to the main menu."<<endl; 
				}
				else if(i == 'd' && x!=18){
					basicBoard.changeCur(x, y);
					x = x+1;
					basicBoard.changeCur(x, y);
					system("CLS"); 
					cout << "Player 2 turn: " << endl;
					basicBoard.printBoard(); 
					cout << "Choose a direction by using the 'wasd'." << endl;
					cout << "Select your move by hitting enter." << endl; 
					cout << "Press escape to return to the main menu."<<endl; 

				}
				else if(i == char(13)){
					bool check = basicBoard.change(x, y, '2');
					if(check){two = basicBoard.checkWin(x, y, winSize); tieCount++;}
					else{i = '0';}
			}}
        }while(i != char(13)); 

    if(two == true)
	{
		system("CLS"); 
        cout << "Player 2 wins!" << endl; return; 
	}
	
	if(tieCount == (19*19))
	{
		cout << "Game is a tie!" << endl; return; 
	}

}

}

void UI::changeSettings(){
	while(1==1){
	system("CLS"); 
	cout<<"Welcome to the settings menu"<<endl;
	cout<<"Choose one (enter the number):"<<endl;
	cout<<"(1) Change cursor [Default cursor is * ]"<<endl;
	cout<<"(2) Change font color of console." <<endl;
	cout<<"(3) Change win size [Default is 5]"<<endl; 
	cout<<"(4) Revert to default settings." <<endl;
	cout<<"(5) Back to main menu." <<endl;
	int option;
	cin >> option;

	if(option == 1){//Change the cursor
	while(1==1){
	system("CLS"); 
	cout<<"Select one of the following cursors:"<<endl;
	cout<< "(1) ! , (2) X , (3) & "<<endl;
	cout<< "(4) % , (5) + , (6) ="<<endl;
	cout<< "(7) ? , (8) # , (9) * [Default]" << endl;
	cout<< "(10) Exit"<<endl; 
	int cursorChoice;
	cin>>cursorChoice; 	
		if(cursorChoice == 1){this->cursorChar = '! ';}
		if(cursorChoice == 2){this->cursorChar = 'X';}
		if(cursorChoice == 3){this->cursorChar = '&';}
		if(cursorChoice == 4){this->cursorChar = '%';}
		if(cursorChoice == 5){this->cursorChar = '+';}
		if(cursorChoice == 6){this->cursorChar = '=';}
		if(cursorChoice == 7){this->cursorChar = '?';	}
		if(cursorChoice == 8){this->cursorChar = '#';}
		if(cursorChoice == 9){this-> cursorChar = '*';}
		if(cursorChoice == 10){system("CLS"); break; }
	}}
	
	if(option == 2){//Change the color
	while(1 == 1){
	system("CLS"); 
	cout<<"Select one of the following console font colors:"<<endl;
	cout<<"(1) GREEN" <<endl;
	cout<<"(2) BLUE" <<endl;
	cout<<"(3) PURPLE"<<endl;
	cout<<"(4) BLACK Font, WHITE Background"<<endl;
	cout<<"(5) WHITE Font, BLACK Background [Default]"<<endl;
	cout<<"(6) Exit"<<endl; 
	int colorChoice;
	cin>> colorChoice;
		if(colorChoice == 1){system("COLOR 02");}
		if(colorChoice == 2){system("COLOR 01");}
		if(colorChoice == 3){system("COLOR 05");}
		if(colorChoice == 4){system("COLOR 70");}
		if(colorChoice == 5){system("COLOR 07");}
		if(colorChoice == 6){system("CLS"); break; }
	}}
	
	if(option == 3){//Change the win size
	while(1==1){
	system("CLS"); 
	cout<<"Select one of the following win sizes:"<<endl; 
	cout<<"(3) Consecutive pieces"<<endl; 
	cout<<"(4) Consecutive pieces"<<endl; 
	cout<<"(5) Consecutive pieces [Default]"<<endl; 
	cout<<"(6) Consecutive pieces"<<endl; 
	cout<<"(7) Exit"<<endl; 
	int winChoice = 0; 
	cin>>winChoice; 
		if(winChoice == 3){this->winSize = 3;}
		if(winChoice == 4){this->winSize = 4;}
		if(winChoice == 5){this->winSize = 5;}
		if(winChoice == 6){this->winSize = 6;}
		if(winChoice == 7){system("CLS"); break;}
	}}

	if(option == 4)//Our default settings 
	{system("Color 07"); winSize = 5; this->cursorChar = '*'; }
	
	if(option == 5){system("CLS");break; }//Exit
}
}

