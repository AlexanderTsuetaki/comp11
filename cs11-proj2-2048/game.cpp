#include <string>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "game.h"
#include "highScoresList.h"
#include <random>

using namespace std;

//Constructor
Game::Game(){
	Width = 1;
	Height = 1;
	board = new int*[Height];
	for(int i = 0; i< Height; i++){
		board[i] = new int[Width];
	}
        userInput = "";
	ok = true;
	score = 0;
}
//destructor
Game::~Game(){
	delete []board;
	delete board;
}
//print function (premade)
//takes a num;
void Game::print_number(string num){
	printf("%-6s",num.c_str());
}

// play 
//      arguments: none
//      returns: none
// plays the game once through. 
void Game::play(){
	srand(time(NULL));
	cout << "Enter desired dimension of board: ";
	cin >> Width >> Height;
	if(Width < 2 or Height < 2){
		cerr << "Dimension must be at least 2" << endl;
		exit (1);
	}
	setBoard();
	cout << "Current score: 0 " << endl;
	printBoard();
	while(go()){
		if(getUserInput()){
			move();
			combine();
			move();
			cout << "Current score: " << score << endl;
			if(ok)
				newTile();
			printBoard();
		}
		ok = false;
	}
	cout << "Game over! Enter your name to record your score: ";
	cin >> userInput;
	highScores.insert(userInput, score);
	highScores.save();
	exit (0);
}
// setBoard()
//           arguments: none
//           returns: none;
// prints some pre-game material and initialized the board then seeds the 
// board;
void Game::setBoard(){
	cout << "Starting game! High score is "; 
	cout << highScores.highestScore() << endl;
	delete [] board;
	board = new int*[Height];
	for(int i = 0; i< Height; i++){
		board[i] = new int[Width];
	}
	for(int i = 0; i< Height; i++){
		for(int j = 0; j < Width ; j++){
			board[i][j] = 0;
		}
	}
	newTile();
	newTile();
}

// getsUserInput
//           arguments: none
//           returns: if a print function needs to be done in accordance to
//                    the user input
// gets the user input and determines the correct responce 
bool Game::getUserInput(){
	string temp = "";
	userInput = temp;
	getline(cin,temp);
	userInput = temp;
	if(userInput == "a" or userInput == "s" or userInput == "d" or
	   userInput == "w"){
		return true;
	}
	if(userInput == "q" or userInput == ""){
		return false;}
	else if(userInput == "h"){
		highScores.printTop5();
		return false;}
	else if(userInput.substr(0,4) == "show"){
		highScores.printUser(userInput.substr(5));
		return false;}
	else if(userInput.substr(0,5) == "clear"){
		highScores.clear();
		return false;}
	else if(userInput.substr(0,4) == "keep"){
		highScores.keepTop10();
		return false;}
	else{
		cout<< "Command not reconized. Please try again" << endl;
		return false;}
	return true;
}

// new Tile
//           arguments none
//           returns none
// sets a random tile and a random valus(2 or 4)
void Game::newTile(){
	int r1 = rand()%Height;
	int r2 = rand()%Width;
	int ten = 2;
	while(board[r1][r2] != 0){
		r1 = rand()%Height;
		r2 = rand()%Width;
	}
	if(rand()%10 > 8){
		ten = 4;
	}
	board[r1][r2] = ten;
}

// printBoard
//           arguments none
//           returns none
// prints the board
void Game::printBoard(){
	string temp = "";
	for(int i = 0; i < Height; i++){
		for(int j = 0; j < Width; j++){
			if(board[i][j] == 0)
				print_number("-");
			else{
				temp = to_string(board[i][j]);
				print_number(temp);
			}
		}
		cout << endl;
	}
}

// go 
//            arguments none
//            returns none
// returns false if 2048 is accomplished or the board in completely filled and
// no merges can occur. 
bool Game::go(){
	if(userInput == "q"){
		return false;
	}
	for(int i = 0; i < Height; i++){
		for(int j = 0; j < Width; j++){
			if(board[i][j] == 2048){
				return false;
			}			     
		}
	}
	for(int i = 0; i < Height; i++){
		for(int j= 0; j < Width; j++){
			if(board[i][j] == 0)
				return true;
			if((j < Width-1)and(board[i][j] == board[i][j+1]))
				return true;
			if((i < Height-1)and(board[i][j] == board[i+1][j]))
				return true;
			   
		}
	}
	return false;
}

// getNext 
//           arguments: a number to get the next value for
//           returns the next interationvalue(int)
// notes : used to get the next value
int Game::getNext(int i){
	if(userInput == "a" or userInput == "w")
		return (i+1);
	if(userInput == "s" or userInput == "d")
		return (i-1);
	return 0;
}

// getsStart
//          arguments none
//          returns the start value for the search
//
int Game::getStart(){
	if(userInput == "a" or userInput == "w")
		return 0;
	if(userInput == "s")
		return Height-1;
	if(userInput == "d")
		return Width-1;
	return 0;
}
// getEnd
//       arguments none
//       returns the end value of the loop
//
int Game::getEnd(){
	if(userInput == "s" or userInput == "d")
		return -1;
	if(userInput == "w")
		return Height;
	if(userInput == "a")
		return Width;
	return 0;
}
// getCon
//        arguments none
//        returns the constant value for the first loop
//
int Game::getCon(){
	if(userInput == "a" or userInput == "d")
		return Height;
	if(userInput == "w" or userInput == "s")
		return Width;
	return 0;
}

// combine
//           arguments none
//           returns none
// combines the elements if they are of the same value and next to eachother
void Game::combine(){
	int start = getStart();
	int end = getEnd();
	int con = getCon();
	int mod = getNext(0);
	for(int i = 0; i < con; i++){
		for(int j = start; j != end - mod; j += mod){
			if(userInput == "w" or userInput == "s"){
				if(board[j][i] == board[getNext(j)][i]
				   and board[j][i] != 0){
					board[j][i]+=board[getNext(j)][i];
					board[getNext(j)][i] = 0;
					ok = true;
					score += board[j][i];
				}
			}
			else{ 
				if(board[i][j] == board[i][getNext(j)]
				   and board[i][j] != 0){
					board[i][j] +=board[i][getNext(j)];
					board[i][getNext(j)] = 0;
					ok = true;
					score += board[i][j];
				}
			}
		}
	}
}

// move
//        arguments none
//        returns none
// moves a value to a blank spot 
void Game::move(){
	int t = 0;
	int mod = getNext(0);
	bool going = true;
	int start = getStart();
	int end = getEnd();
	int con = getCon();
	for(int i = 0; i < con; i++){	
		for(int j =start; j != end; j += mod){
			going = true;
			if(board[j][i] == 0
			   and(userInput == "w" or userInput == "s")){
				t = j;
			        while(t != getEnd() and going){
					if(board[t][i]!=0){
						board[j][i] += board[t][i];
				 		board[t][i] = 0;
						going = false;
						ok = true;
					}
					t+= mod;
				}
			}
			else if(board[i][j] == 0
				and (userInput == "a" or userInput == "d")){
				t = j;
			        while(t !=  getEnd() and going){
					if(board[i][t]!=0){
						board[i][j] += board[i][t];
						board[i][t] = 0;
						going = false;
						ok = true;
					}
					t += mod;
				}
				
			}
		}
	}
}
