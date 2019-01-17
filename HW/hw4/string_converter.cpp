// string_converter.cpp
//        purpose: to parse a string and output just the numbers
//        notes: outputs the number in the order they appear
// Author: Alexander Tsuetaki
// Date Modified: 10/7/18
//

#include <iostream>

using namespace std;

int string_to_int(string);

int main(){
        bool parsing = true;
        string s1 = "";
	cout  << "enter exit to exit" << endl;

	// while loop for user intergafe
        while(parsing){
	        cout << "input: ";
	        cin >> s1;
		if(s1 == "exit"){
		        parsing = false;
		}
		else{
		        cout << "SUCCESS: " << string_to_int(s1) << endl;
		}
	}
	return 0;
}

// string_to_int
//         arguments: a string to be parsed for integers
//         returns: the integer concatinated from the parsed integers
// notes: N/A works as expected
int string_to_int(string s1){
        int temp = s1.length();
	int number = 0;
	for(int i = 0; i < temp; i++){
	        if(s1[i] > 47 and s1[i] < 58){
	                number *= 10;
		        number += (int)s1[i]-48;
	        }      
	}
	return number;
}
