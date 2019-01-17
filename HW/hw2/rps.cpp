// rps.cpp
//	purpose: plays rps with you 
//	notes:just returns that it is a draw when you and
//	notes(cont): the comp pick the same
//
// Created by: Alexander Tsuetaki
// Date Modified: 9/15/18
//

#include <iostream>
#include <stdlib.h>

using namespace std;


// its the main...
int main(){
	

	// creates a new randome point to initialize rand()
	srand (time(NULL));

	// a array of who wins based on if the comp or user choose r,p,s
	string winCondition[4][3] = {{"Nobody","You", "Computer"},//'p'
				{"Computer","Nobody","You"},//'r'
				{"You", "Computer","Nobody"},//'s'
				{"paper","rock","scissors"}};//computer choice
				//p   ,    r   ,    s

	// initialize other variables
	char userChoice = 'r';
	int compChoice = rand() % 3;
	bool incorrect = true;

	//user input, if the user input is invalid, asks the user for it again
	while(incorrect){
		incorrect = false;
		cout << "please input r for rock, p for paper,"
		<< " or s for scissors" << endl;
		cin >> userChoice;
		
		// changes capitals to lowercase
		if(userChoice < 97)
			userChoice += 32;

		if(userChoice != 'r' and userChoice !='p' and userChoice != 's'){
			cout << "please enter a real input(r,p,s)" << endl;
			incorrect = true;
		}
	}

	

	// gives what the computer randomly played
	cout << "computer chose: " << winCondition[3][compChoice] << endl;
	
	//cleans the user data to use for the array
	if (userChoice =='p'){
		userChoice = 0;
	}
	else{
		userChoice -= 113;
	}
	

	// returns who won the game
	cout << winCondition[(int)userChoice][compChoice] << " won" << endl;

	return 0;


}
