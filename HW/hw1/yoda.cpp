// yoda.cpp
// 	purpose:reverses word order to sound like yoda
//	shows: use of output, input, conditional statements
//	notes:can be used for more or less than four words. 
//
// Modified by Alexander Tsuetaki
// Date modified: 9/7/18
//

#include <iostream>

using namespace std;
// main function
int main(){
	
	// variable that holds the postition of the space
	int temp = 0;
	// variable that holds the sentence to be fliped
	string inputSpeech;
	
	// input for the sentence and variables related to the sentence
	cout << "Type in four words:";
	getline(cin, inputSpeech);
	
	// finds the last space then prints the word that comes after it
	// after printing the word it deletes from the space to the end 
	while (inputSpeech.length() > 0){
		
		//Finds the last instance of a space and
		//prints what comes after it
		temp = inputSpeech.rfind(" ");
		cout <<  inputSpeech.substr(temp+1)<< " ";
		
		// if else statement to assure that if if there is
		// no space character that the loop ends
		if ( temp >= 0){
			inputSpeech.erase(temp, inputSpeech.length());
		}else{
			inputSpeech.erase(0, inputSpeech.length());
		}

	}
	
	// return statment and end line for housekeeping
	cout << endl;
	return 0;
}

