/*
 * printlist.cpp  -- shows how to read a list of numbers into an array
 *
 *      1. read in data
 *      2. then prints out the list with line numbers using another loop
 *
 *   TODO:
 *    [a] change loop to print out only the birthdays in October
 *    [b] after printing out the October bdays, print a count of how many
 *    [c] change to print the count for each month, not the actual bdays
 *    [d] use a function to do [c]
 *    [e] EXTRA: print which month has the MOST birthdays
 */
#include <iostream>

using namespace std;

const int CAPACITY = 5;         // change as needed

int main() 
{
        int bdays[CAPACITY];    // birthday data
        int used;               // number of spaces used so far
        int pos;                // position in array

        // read in CAPACITY values
        pos = 0;
        while (pos < CAPACITY) {
                cin >> bdays[pos];
                pos++;
        }
        used = pos;             // position is how far we got

        // now to print out the list, use a for loop for a change
        for (pos = 0; pos < used ; pos = pos + 1) {
                cout << pos << ". " << bdays[pos] << endl;
        }
        return 0;
}
