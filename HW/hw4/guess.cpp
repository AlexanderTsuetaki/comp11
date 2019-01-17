// guess.cpp 
//	purpose: generate an int between 5-15
//	notes:N/A
//
// Written by: Alexander Tsuetaki
// Date modified: 9/15/18
//

#include <iostream>
#include <stdlib.h>

using namespace std;


// it's the main function, nuff said , it is also < 20 lines 
int main(){

	// initializes the variables and randomizes the rand() function
	srand (time(NULL));
	int rnumber = rand()%11+5;
	int unumber = 0;
	int tries = 0;
	bool giveUp = false;

	cout << "Guess a number in the range 5...15 (enter -1 to exit) ";

	// determins if the user got the number or if they want to exit
	while(unumber != rnumber and not giveUp){
		cin >> unumber;
		if(unumber < 0){
		          giveUp = true;
		}
		else if(unumber == rnumber){
			cout << endl << "you got it!" << endl ;
		}else {
			cout << endl <<  "guess again ";
			
			// determins if the real number is higher or lower
			if(unumber-rnumber > 0){
				cout << " (lower)";
			}else{
				cout << " (higher)";
			}
			cout << " enter your next guess"<< endl;
		}
		tries += 1;
	}
	cout << "You guessed the correct number in " << tries << " guesses"
	     << " - great job!" << endl;

	return 0;
}
