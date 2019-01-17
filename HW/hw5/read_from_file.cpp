/* 
 * read_from_file.cpp
 * Small program to read in a file of 10 numbers and prints those 10 numbers.
 * Compile with: 
 *      clang++ -Wall -Wextra -std=c++11 -o read_from_file read_from_file.cpp
 * 
 * Julie Jiang
 * COMP11 2018F 
 */

#include <iostream>
#include <fstream>

using namespace std;

// File that we are reading from. Contains 10 integers.
const string FILENAME = "10numbers.txt";

int main() {

    // Open a file 
    ifstream inFile;
    inFile.open(FILENAME);
    
    // File did not open successfully. Maybe the file doesn't exist.
    if (not inFile.is_open()) {
        cout << "Unable to find file" << FILENAME << endl;
        return 0;
    }
 
    // Read the contents of the file into an array
    int numbers [10];
    for (int i = 0; i < 10; i++) {
        inFile >> numbers[i];
    }
    
    // Close the opened file
    inFile.close();
    
    // Print the contents of the file to cout   
    cout << "These are the numbers in file " << FILENAME << ": ";
    
    for (int i = 0; i < 10; i++ ) {
        cout << numbers[i] << " ";
    }
    cout << endl;
 
    return 0;
}
