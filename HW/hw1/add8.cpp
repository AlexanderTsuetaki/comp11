//add8.cpp
//	purpose:adds 8 numbers together
//	notes: you can add any number of numbers together if you wish
//      notes(cont): change the integer count if you wish to do this. 
//	notes(cont): asks for numbers one at a time
//
//Modified by: Alexander Tsuetaki
//Date modified: 9/7/18
//

#include <iostream>

using namespace std;

// runs the program
int main(){

	//total (what is returned)
	float total = 0;

	//temp variable for cin
	float temp = 0;

	//counter for amount of numbers to be added together
	int count = 8 ;

	// Gets the number of numbers to be added together
	//cout << "Enter the number of numbers you want to add: ";
	//cin >> count;
	cout << "Ok, give me the first of " << count << " numbers";

	// adds numbers for the number of time you designate. 
	while (count > 0){

		cout << endl << "Enter the next number: ";
		cin >> temp;
		total += temp;
		count -= 1;
		cout << count << " more numbers needed";
	
	}

	//return
	cout << endl << "The total of your numbers is " << total << endl;
	return 0;

}

