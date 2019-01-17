// prof_printer.cpp
//         purpose: to iterate over all numbers between 0 ant 100 and find the
//                : numbers that are divisible by 5 and 3 and replace them with
//                : sam and mark respectivly
//         notes: to iterate over more numbers change the variable at the top
//
// Author: Alexander Tsuetaki
// Date Modified: 9/6/18
//

#include <iostream>

using namespace std;

string returnName(int, string, string);

// main
int main(){
        int max = 100;
	string S1 = "";
	string S2 = "";
	// gets the words to replace Sam and Mark
        cout << "enter two words to replace %3 and %5 respectivly ";
	cin >> S1 >> S2;
	// prints either the names or the number
	for( int i = 0; i <= max; i++){
	        if(returnName(i, S1, S2) == ""){
			cout << i;
		}
		else{
		        cout << returnName(i, S1, S2);
		}
		cout << endl;
	}
	return 0;
}


// returnName
//         Arguments: the the integer, the two strings to repalce Sam and Mark
//         returns: a string of Sam, Mark, SamMark or "" 
// notes: Sam and Mark will be replaced by the words input
string returnName(int name, string first, string second){
	string replacement = "";
	if(name % 3 == 0){
		replacement += first;
	}
	if(name % 5 == 0){
		replacement += second;
	}
	return replacement;
}

       
