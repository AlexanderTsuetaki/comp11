/*
 * realtor.cpp
 * compile with:
 *     clang++ -Wall -Wextra -std=c++11 -o realtor realtor.cpp
 * Edited by: Alexander Tsuetaki
 * Date: 10.15.18
 */

#include <iostream>
#include <fstream>

using namespace std;


struct House {
	int bedrooms;
	float bathrooms;
	int floors;
	string address;
	bool occupied;
};

struct Client_Data {
	int desireFloors;
	int desireBedrooms;
	float desireBathrooms;
};

const int NUM_HOUSES = 10;

// Function prototypes go here
void print_house(House);
void load_array(House[], string);
int calculate_cost(House);
int calculate_rental_cost(House);
void list_houses_with(House[],Client_Data);
bool quit(char);
void print_true_house(House);

int main()
{
	House houses[10]; 
	Client_Data c1;
	bool running = true;
	string database;
	char end;

	cout << "Welcome!" << endl << "Please provide a housing database: ";
	cin >> database;

	load_array(houses, database);	
	while(running){
		cout << "What kind of house are you looking to buy or";
		cout << " rent today" << endl;
		cout << "Number of bedrooms?" << endl;
		cin >> c1.desireBedrooms;
		cout << "Number of baths?" << endl;
		cin >> c1.desireBathrooms;
		cout << "Number of floors" << endl;
		cin >> c1.desireFloors;
		list_houses_with(houses,c1);
		cout << "Quit? (Y/N)" << endl;
		cin >> end;
		running = quit(end);
	}
	return 0;
}


// Function definitions go here
//
// print house
//         Argument: a house to be printed
//         retruns: n/a
// notes: n/a returns 
void print_house(House test){
	cout << test.bedrooms << " bedrooms" << endl;
	cout << test.bathrooms << " bathrooms" << endl;
	cout << test.floors << " floors" << endl;
	cout << "address " << test.address << endl;
	cout << "occupied ";
	if(test.occupied)
		cout << " true" << endl;
	else
		cout << " false" << endl;
	cout << calculate_cost(test) << endl;
	cout << calculate_rental_cost(test) << endl;
}


// load_array
//         arguments: an array of houses and a string representing the name of
//                    a file
//         returns: none
// notes: n/a
void load_array(House test[], string file){
	ifstream inFile;
	inFile.open(file);
	
	char c = 'f';
	if(not inFile.is_open()){
		cout << "unable to find file " << file << endl;
	}
	for (int i = 0; i < 10; i++){
		inFile >> test[i].bedrooms >> test[i].bathrooms 
		       >> test[i].floors >> test[i].address;
	        inFile >> c;
		if(c == 'f' or c == 'F'){
			test[i].occupied = false;
		}
		else if (c == 't' or c == 'T'){
			test[i].occupied = true;
		}
		else
			cout << "enter a correct house occupied value";
	        //debug statement
		//print_house(test[i]); 
	}
}

// calculate_cost
//         arguments: a house object which cost is to be anaylized
//         returns: an int representing the cost of the house
// notes: n/a
int calculate_cost(House test){
	int cost = 0;
	cost += test.bedrooms * 100000;
	cost += test.bathrooms * 20000;
	cost += test.floors * -30000;
	if(cost < 150000)
		cost = 150000;
	if(cost > 1000000)
		cost = 1000000;
	return cost;
}

// calculate_rental_cost
//         arguments: a house object which is to be anaylized
//         returns: an int represnting the cost to rent the house
// notes: n/a
int calculate_rental_cost(House test){
	int cost = 0;
	cost += test.bedrooms * 500;
	cost += test.bathrooms * 200;
	cost += test.floors * 100;
	return cost;
}

// list_houses_with
//         arguments: an array of houses and a client object
//         returns: none
// notes: N/A
void list_houses_with(House test[], Client_Data client){
	bool found = false;
	for(int i = 0; i < NUM_HOUSES; i++){
		if ((client.desireFloors == test[i].floors or 
		     client.desireFloors == -1) and
		    (client.desireBedrooms == test[i].bedrooms or
		     client.desireBedrooms == -1) and
		    (client.desireBathrooms == test[i].bathrooms or
		     client.desireBathrooms == -1)){
			found = true;
			print_true_house(test[i]);
		}
	}
	if(not found){
		cout << "No matching houses found!" << endl;
	}
}

// quit
//         arguments: a character
//.        returns: returns a boolean to be used to determins continuation
// notes: realtor _reference crashes if a string like "yes" is input
// notes(cont): the code after "return true" is to prevent this
bool quit (char c){
	if(c == 'Y' or c == 'y')
		return false;
	else if (c == 'N' or c == 'n')
		return true;
	cout << "please enter Y for yes or N for no" << endl;
	cin >> c;
	return quit(c);
}

// print_true_house
//         arguement: a house object to be printed
//         returns: none
// notes: its just a helper function
void print_true_house(House test){
	cout << "House at " << test.address <<":" << endl;
	cout << test.bedrooms << " beds, "
	     << test.bathrooms << " baths, and "
	     << test.floors << " floors" << endl;
	if(test.occupied){
		cout << "Occupied. Not for Sale.";
	}
	else{
		cout << "Not occupied, for sale!";
	}
	cout << endl;
	cout << "Cost to buy: "
	     <<calculate_cost(test) << endl;
	cout << "Cost to rent: "
	     << calculate_rental_cost(test) << " per month" 
	     << endl << endl;
}
