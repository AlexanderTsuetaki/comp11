//Change.cpp
//	purpose: gives the least number of coins needed for a given input value
//	effects: prints to standard output
//	notes: none
//
//Modified by Alexander Tsuetaki
//Date modified: 9/8/18
//

#include <iostream>

using namespace std;

// main function
int main(){

	//int money how much money remains to be processed
 	int money;
	cout << "Amount of change in cents? ";
	cin >> money;
	
	//int's when divided by ints return int value (trunkated)
	cout <<  money/25 << " quarters ";
	//% or modulo returns the remainder after dividing by a number
	money = money%25;
	cout << money/10 << " dimes ";
	money = money%10;
	cout << money/5 << " nickels ";
	money = money%5;
	cout << money << " pennies " << endl;
	return 0;

}
	
