// int_to_string.cpp
//         Purpose: to change an integer into a string
//         Notes: take out comment to change type of action
// Author: Alexander Tsuetaki
// Date Modified: 10/8/17
//

#include <iostream>
#include <iomanip>

using namespace std;

string int_to_string(int);
string int_to_stringL(int);

int main(){
        int tests[5] = {-1337,515,41800,01776,0000};
	int test = 00072;
	cout << dec << test + 10;
	for(int i = 0; i < 5; i++){
	        cout << setbase(10);
		cout << dec << tests[i] << endl;
	        cout << int_to_string(tests[i]) << endl;
		cout << int_to_stringL(tests[i]) << endl;
	}
	return 0;
}

// int_to_string 
//         arguments: an integer
//         returns: a string of that integer value
// notes: preforms the int to string with recursion
// adds characters to a string throughout a recursive program and returns 
// the number
string int_to_string(int test){
        string str = "";
        if(test/10 == 0){
	        str += char(test+48);
	        return str;
	}
	if(test < 0 ){
	        return "-" + int_to_string(test*-1);
	}
	return int_to_string(test/10) + (char)(test%10+48);
}

// int_to_stringL
//         arguments: an integer
//         returns: a string saying the integer value
// notes: preforms the int to string with loops by adding each number to a 
// string on each iteration : utilizes do while so 0 works
string int_to_stringL(int test){
        int temp = test;
	if(test < 0){
	        temp *= -1;
	}
	string rStr = "";
	do{
	        rStr = (char)(temp%10+48) + rStr;
		temp /= 10;
	}while(temp != 0);
	if(test < 0){
	        rStr = "-" + rStr;
		temp *= -1;
	}
	return rStr;  
}
