// dictionary.cpp
//         purpose: to create a small dictionary 
//         notes:
// Author: Alexander Tsuetaki
// date modified: 9/30/18
//

#include <iostream>
#include <map>
#include <string>
#include <locale>

using namespace std;

// dictionary & definitions
map<string, string> dictionary;

void initializeDic();
void interaction();
void endMessage();
void errorMessage(string);

// this is the main function
int main(){	
	//user interaction
	interaction();
	return 0;
}

// intializeDic
//        arguments:N/A
//        returns:None
//        notes: initalizes the dictionary and the strings inside it
void initializeDic(){
        dictionary["variable"]="A location in memory"
                               " that can hold a value"; 
        dictionary["function"]="section of program that adds a new section on "
                               " the stack and does a task";
        dictionary["recursion"]= "repeating of a process in a process a " 
                                 "function activating in a function \n "
	                         " see recursion";
        dictionary["conditional"]="A statement that occures depending on if "
                                  "booleans are true or false";
        dictionary["comp11"]= "A fun and rewarding class that all should take";
        dictionary["alex"]="a great student who should get 101%";
	dictionary["exit"]="goodbye now lebe wohl!";
}
// interaction
//        arguments:none
//        returns:none
//        notes: does the user interaction for dictionary.cpp
//        notes(cont): takes lower and upper case words
void interaction(){
         initializeDic();
         bool userInt = true;
         while (userInt){
		string userInput = "";
		map<string,string>::iterator thing;
		string lowerInput = "";
		cout << "** What word would you like to look up"
		     <<" (type exit to exit):"<< endl;
		cin >> userInput;
		if(userInput == "exit"){
			endMessage();
			userInt = false;
		}
		locale loc;
		for(string::size_type i = 0; i < userInput.length(); i++)
		        lowerInput += tolower(userInput[i],loc);
		thing = dictionary.find(lowerInput);
		if(thing == dictionary.end()){
		        errorMessage(userInput);
		}else{
		        cout << thing->second << endl;
		}
	 }
}
// errorMessage
//         argurmnets:none
//         returns:none 
//         notes: outputs the error messgae if no definition was found
//         notes(cont):outputs the error message
void errorMessage(string temp){
	cout << temp << ": \n Definition Not Found \n";
}


// endMessage
//       arguments: none
//       returns:none
//       notes: outputs te end message for dictionary.cpp
void endMessage(){
	cout << "Thanks for working with me \n";
}
