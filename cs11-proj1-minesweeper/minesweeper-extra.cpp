/* 
 * minesweeper-extra.cpp 
 *
 * A text-based minesweeper game that runs in the terminal.
 *
 * COMP11 Fall 2018
 * Modified by: Alexander Tsuetaki
 * Date: 10/21/18
 */

#include <iostream>
#include <time.h> 
#include <cstdlib>

using namespace std;

/* Set random seed */
#ifdef TESTING
#define RANDOMSEED 1
#else
#define RANDOMSEED time(NULL)
#endif

// struct for each cell of
//        mines - the number of mines surrounding the cell(-1 if cell itself
//                is a mine)
//        show - a boolean to determine if the program should display the #
//               of mines value.
struct cell{
	int mines;
	bool show;
};
// userInput
//         n1- the first number input
//         n2- the second number input
//         mod- a string modifier to be used if i have the time to do the JFFE
// use: self explainitory
//
struct userInput{
	int n1;
	int n2;
	int prob;
	string mod;
};
//initialize functions
int makeMinefield(cell[9][9],int);
void printBoard(cell[9][9]);
void numberOfMines(cell[9][9],int,int);
void getUserInput(cell[9][9], userInput *ui);
void gameOver(bool);
void badInput(bool);
void showAll(cell[9][9]);
void getMod(userInput *ui);

// main- its the main function
int main() {
    // Seed the pseudo-random number generator
    srand(RANDOMSEED); 
    cell field[9][9];
    int totalMines = 0;
    bool go = true;
    userInput ui;
    // initialization 
    getMod(&ui);
    totalMines = makeMinefield(field, ui.prob);
    for(int i = 0; i < 9; i++){
	    for(int j = 0; j < 9; j++){
		    numberOfMines(field,i,j);
	    }
    }
    //main loop
    int i = 81;
    printBoard(field);
    while((i > totalMines) and go){
	    i--;
	    getUserInput(field, &ui);
	    if(field[ui.n1][ui.n2].mines == -1){
		    go = false;
		    showAll(field);
	    }
	    field[ui.n1][ui.n2].show = true;
	    printBoard(field);
    }
    gameOver(go);
    return 0;
}

// makeMinefield
//         arguments: an array of cells to be populated
//         returns: the number of mines placed in the array
// purpos: populates the field with mines by changing the mines value to -1. 
// used in the initialization in main.
int  makeMinefield(cell field[9][9], int prob){
	int numberOfMines = 0;
	for (int i = 0; i < 9;i++){
		for (int j = 0; j< 9; j++){
			if (rand()%100 < prob){
				field[i][j].mines = -1;
				numberOfMines += 1;
			}
			else{		       
				field[i][j].mines = 0;
			}
			field[i][j].show = false;
		}
	}
	return numberOfMines;
}

// printBoard
//         arguments: an array of cell's to be printed
//         returns: none
// purpose: to print the board
// printBoard prints the board in the main game loop after each input.
//
void printBoard(cell field[9][9]){
	cout << "  0 1 2 3 4 5 6 7 8" << endl;
	for(int i = 0; i < 9; i++){
		cout << i;
		for (int j = 0; j< 9; j++){
			if(field[i][j].show){
				cout << " ";
				if(field[i][j].mines == -1){
					cout << "x";
				}
				else{
					cout<< field[i][j].mines;	
				}
			}	     
			else
				cout << " -"; 
		}
		cout << endl;
	}
}


// numberOfMines
//         arguments: an array of cells to be quered
//                    the vertical value in the array to be populated
//                    the horizontal value in the array to be populated
//         returns: none
// purpose: populates the minefield(field) with the number of mines 
// that surround each cell. Cells that contain a mine are passed over.
// to be used in the initialization in the main function.
void numberOfMines(cell field[9][9], int i, int j){
	if(field[i][j].mines != -1){
		for(int a = i-1; a < i+2; a++){
			for(int b = j-1; b < j+2; b++){
				if((a >= 0 and a <= 8) and 
				   (b >= 0 and b <= 8)){
					if (field[a][b].mines == -1)
						field[i][j].mines += 1;
				}
			}
		}
	}
}

// getUserInput
//         argument: an array of cell's to be queried
//                   a user input to be changed to the inputed values
//         returns: none
// purpose:getUserInput will be used in the main function within the main 
// game loop. the user input to be gotten and will be tested to see if it is
// a valid input (if the input is out of range, or is already showing)
void getUserInput(cell field[9][9], userInput *input){
	string mod;
	int n1;
	int n2;
	bool go = true;
	do{
		go = false;
		cout << "Enter the row and column of the square to uncover: ";
		cin >> n1 >> n2;
		if((n1 < 0) or (n1 > 8) or (n2  < 0) or (n2 > 8)){
			badInput(true);
			go = true;
		}
		else if(field[n1][n2].show){
			badInput(false);
			go = true;
		}
	}while(go);
	(*input).n1 = n1;
	(*input).n2 = n2;
}

// gameOver
//         arguments: a boolean to determine which game over senerio to show
//         returns: none
// purpose: prints the game over states
// this is a helper function to be used in the main function. 
// the main function will pass in a boolean to tell what type of end game 
// senerio is nessisary.
void  gameOver(bool win){
	cout << "GAME OVER. ";
	if (win){
		cout << "YOU WON!" << endl;
	}
	else{
		cout << "YOU LOST!" << endl;
	}
}

// badInput
//         arguments: a boolean to determine what badInput statement to print.
//         returns: none
// purpose: to print out the bad input statements.
// to be used when a bad input is given in the getUserInput function.
// in the getUserInput function, a boolean that gives what type of bad input of
// it is passed to this function.
void badInput(bool Bounds){
	cout << "Bad input. ";
	if(Bounds){
		cout << "Row and col must be >= 0 and < 9."<< endl;
	}
	else{
		cout << "Select another square." << endl;
	}
}

// showAll
//         arguments: an array of cells to be modified
//         returns: none
// purpose: to change the show value fo all cells to be true so when the array
//          is printed, all values are shown. for debuging and one JFFE later.
void showAll(cell field[9][9]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(field[i][j].mines == -1)
				field[i][j].show = true;
		}
	}
}

// getMod
//         arguments: a user input to be edited
//         returns: none
// purpose: to get the probability to be used in the minefield initialization
//
void getMod(userInput *ui){
	cout << "Enter the probablility (0-100%)";
	cin >> (*ui).prob;
}
