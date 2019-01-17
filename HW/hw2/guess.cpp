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

// it's the main function, nuff said
int main(){

	// initializes the variables and randomizes the rand() function
	srand (time(NULL));
	int rnumber = rand()%10+5;
	int unumber = 0;
	int tries = 3;

	cout << " what do you think the number is?  ";

	// determins if the user got the number or if they ran out of tires
	while(unumber != rnumber and tries > 0){
		cin >> unumber;
		if(unumber == rnumber){
			cout << endl << "you got it!" << endl ;
		}else if (tries > 1){
			cout << endl <<  "guess again ";
			
			// determins if the real number is higher or lower
			if(unumber-rnumber > 0){
				cout << " (lower)";
			}else{
				cout << " (higher)";
			}
			cout << " enter your next guess"<< endl;
		}
		tries-=1;
	}
	return 0;
}
