//generate_hello.cpp
//	purpose: to write other programs to greet a personby name
//	notes:none 
//
//Modified by Alexander Tsuetaki
//Date modified: 9/9/18
//

#include <iostream>

using namespace std;
// the main function
int main(){

        // variable for the name to be entered
	string name;
	// input for the name
	cin >> name;

	// header comment
	cout << "/*" << endl << "* prints a greeting for " 
	<< name << endl << "*/" << endl << endl;
	
	// import statements
	cout << "#include <iostream>" << endl << endl 
	<< "using namespace std;" << endl << endl;
	
	// main function up to return statment
	cout << "int main()"<< endl << "{" << endl 
	<< "\t cout << \"Hello, " << name << "!\" << endl;";
	
	// return statement and end of main function
	cout << endl << endl << "\t return 0;" << endl << "}" << endl;  
}
