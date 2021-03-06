//pattern.cpp
//         purpose:to make a pretty pattern of inputed words
//         notes:
// Author: Alexander Tsuetaki
// Date Modified: 9/30/18
//

#include <iostream>
#include <string>

using namespace std;

void message();
void pattern(string,string,int);
string linePattern(string, string,int);

//the main, gets the input after outputing the 
int main(){
	string part1;
	string part2;
	int lines;
	message();
	getline (cin, part1);
	getline (cin, part2);
	cin >> lines;
	pattern(part1, part2, lines);
}

// message
//        arguments: none
//        returns: none
//        notes: outputs a message to explain how to input
//
void message(){
	cout << "please enter your two patern components and the "
	     << "number of lines" <<endl
	     << "(press enter after each component):" << endl;
}

// pattern
//        arguments: first string part, second string part, number of line 
//        retruns: none
//        notes: prints the line pattern 
void pattern(string part1, string part2,int lines){
	if(lines <= 1){
	        cout << linePattern(part1,part2,5) << endl;
	}else{
	        cout << linePattern(part1,part2,5) << endl;
	        pattern(part2, part1, lines-1);
	}
}
	
// linePattern
//        arguments: first string part, second string part, number of lines
//        returns: the combines string of string one and 
//               : two row number of times
//        notes:NA;
string linePattern(string one, string two,int rows){
	string temp = "";
	if(rows <=1 ){
	        temp+= one;
		temp+= two;
	}
	else{
	        temp += linePattern(one,two,rows-1);
		temp += one;
		temp += two;
	}
	return temp;
}
