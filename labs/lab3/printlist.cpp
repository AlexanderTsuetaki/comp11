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

const int CAPACITY = 1001;         // change as needed

int findMaxMonth(int[]);

int main() 
{
        int bdays[CAPACITY];    // birthday data
        int used;               // number of spaces used so far
        int pos;                // position in array
	int month[12];
        // read in CAPACITY values
        pos = 0;
        while (pos < CAPACITY) {
                cin >> bdays[pos];
                pos++;
        }
        used = pos;             // position is how far we got
	// for each birthday, determins the month and adds it to an array
	// with the number of birthdays in the corrorsponing month.
	for(int i=0; i<CAPACITY; i++){
	        for(int j=0; j<12; j++){
		        if((bdays[i]/100) == (j+1)){
	                        month[j]+=1;
	                }
                }
	}
        // now to print out the list, use a for loop for a change
        for (pos = 0; pos < 12; pos = pos + 1) {
	        cout << "In month "<< pos+1  << " there are " 
		     << month[pos] << " birthdays" << endl;
        }
	cout << "The month with the most birthdays is month: " 
	     << findMaxMonth(month)+1 << endl;
        return 0;
}
// findMaxMonth
//      arguments: an array of the number of birthdays in each month
//      returns:the number coorisponding to the month in the array
//      (i.e.) for april it would return 3 as 3 represents april in the array
int findMaxMonth(int months[12]){
        int max = 0;
	int month = 0;
        for(int i = 0; i<12; i++){
	        if(months[i]>max){
	                max = months[i];
	                month = i;
        
		}
	}
	return month;
}
