//flights.cpp
//     purpose: to compute and display the amount fo time to chage plane
//     purpose(cont): and the amount of time the total trip took
//     notes: does the calculation in minutes, then converts to hours in output
//		
//Author:Alexander Tsuetaki
//date modified: 9/30/18
//

#include<iostream>

using namespace std;

int convertionT(int,int);
void readTime(int);
int elapsed(int,int);
int carryover(int,int);

// this be the main
int main(){

	//initializes all the variables
	int flight[2][4];
	int layover = 0;
	int total = 0;


	// gets user input
	cout << "Flight 1: ";
	cin >> flight[0][0] >> flight[0][1] >> flight[0][2] >> flight[0][3];
	cout << "Flight 2: ";
	cin >> flight[1][0] >> flight[1][1] >> flight[1][2] >> flight[1][3];
	

	// if the time lapses to another day, it adds 24*60 minutes to adjust
	// for the negative time.->23->1 = 1-23+24 or two hour difference
	// adds the time between flight1 and flight2 two by subtracting the
	// hours and minutes of flight1 arrival from flight2 departure
	// then adding it to layover in terms of minutes
	layover += elapsed(convertionT(flight[0][2],flight[0][3]),
			   convertionT(flight[1][0],flight[1][1]));

	cout << "Layover ";
        readTime(layover);	


	// like layover, but adding each flight
	// for each flight, adds 24*60 mins if passes to a new day
	// adds the difference between arrival and departure times too total
	// then after adding both flights, adds the layover time
	for(int i = 0; i<2; i++){	
	         total += elapsed(convertionT(flight[i][0],flight[i][1]),
			         convertionT(flight[i][2],flight[i][3]));

	}
	total += layover;

	// outputs the amount of total time the trip took
	cout << "Total ";
        readTime(total);
	
	return 0;
}

// convertionT
//        arguments: hours, minutes(kinda self explanitory
//        returns: total minutes = to number of hours + minutes
//        notes:N/A
int convertionT(int hours, int minutes ){
	return hours*60+minutes;
}

// readTime
//        arguments: time in minutes
//        returns: N/A
//        notes: uses cout to give __ hr, __ min
void readTime(int time){
	cout << time/60 << " hr " << time%60 << " min" << endl;
}

// elapsed
//        arguments: start, end time
//        returns: difference between the times
//        notes: N/A
int elapsed(int start, int end){
	int time = 0;
        time += carryover(start,end);
	time += end - start;
	return time;
}

// carryover 
//        arguments: start, end times
//        returns: 60*24
//        notes: will only return one day in minutes (to compensate)
int carryover(int time1, int time2){
	int change = 0;
	if(time1 > time2){
		change += 60*24;
	}
	return change;
}
