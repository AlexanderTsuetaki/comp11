#ifndef GAME_H
#define GAME_H

#include <string>

#include "highScoresList.h"

class Game {
 public:
	Game();
        ~Game();
        void play();
 private:
        void print_number(std::string num);
	void setBoard();
	bool getUserInput();
	void newTile();
	void printBoard();
	bool go();
	void move();
        void combine();
	
	int getNext(int i);
	int getStart();
	int getEnd();
	int getCon();

	int Width;
	int Height;
	int score;
	std::string userInput;
	int **board;
	bool ok;
	highScoresList highScores;
};

#endif
