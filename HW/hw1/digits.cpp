// digits.cpp
//      purpose: report number of digits in an integer and if pos or neg
//        shows: use of output, input, conditional statements
//         note: no bugs, no work
//
// Modified by:Alexander Tsuetaki
// Date modified:9/6/18
//

#include <iostream>

using namespace std;

// the main function
int main()
{
    //variable for the input 
    int input;
   
    //obtaining the input number
    cout << "Enter a number: ";
    cin  >> input;
    
    // determins the number of digits
    if (input >= 100 or input <= -100) {
        cout << "input has at least three digits" << endl;
    } else if ( input >=  10 or input <= -10) {
        cout << "input has two digits" << endl;
    } else {
        cout<< "input has one digit" <<endl;
    }
    
    // determins if positive or negative       
    if ( input > 0) {
        cout << "input is positive" << endl;
    }else if( input == 0){
	cout << "input is 0 " << endl;
    } else {
        cout << "input is negative" << endl;
    }
    
    // return statement
    return 0;
}
