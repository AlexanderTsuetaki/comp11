// most_common_int.cpp
//         purpose: to return themost common integer in an array
//         notes: N/A
// Author: Alexaner Tsuetaki
// Date Modified: 10/7/18
//

#include <iostream>

using namespace std;

void MCI(int[],int);

int main(){
        int length = 0;
	// arrays to test
        int testArrays[4][9] = {{1,3,2,2,3,4,4,2,7},
				{1,4,4,2,1,2,4,2,0},
				{0,0,1,1,1,1,5,5,5},
				{10,10,10,10,10,10,10,9,9}};
	for(int i = 0; i < 4; i++){
	        length = *(&testArrays[i] + 1) - testArrays[i];
	        MCI(testArrays[i], length);
		cout << endl;
	}
        return 0;
}


// MCI 
//         (shortened from most_common_int)
//         arguments: an array of integers and the arrays length
//         returns: none :prints out the number within the program
// notes:finds the number that occures the most and 
// then get the smallest value of that has the max amount of instances
void MCI(int test[], int length){
	int used[2][length];
	for(int a = 0; a < length; a++){
	        used[1][a] = 0;
		used[0][a] = test[a];
	}
	int min = 2147483647;
	int max = 0;
	//finds the intigers with max instances
	for(int i = 0; i < length; i++){
	        for(int j = 0; j < length; j++){
	                if(used[0][i] == test[j]){
	                        used[1][i] += 1;
				if(used[1][i] > max){
				        max = used[1][i];
				}
			}
		} 
	}
	//finds the intiger within the max intigers that has the smallest value
	for(int k = 0; k < length; k++){
	        if(used[1][k] == max){
	                if(used[0][k] < min){
	                        min = used[0][k];
			}
		}
	}
	//prints to screen
	cout << "most common int is" << min;
}       
