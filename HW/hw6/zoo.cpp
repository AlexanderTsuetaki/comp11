/*
 *  Author:Alexander Tsuetaki
 *  Date:11/11/18
 *
 *  Purpose: To be a zookeeper, organiza a series of animal structs into 
 *           an array of exhibit classes
 *  Known bugs: when putting in multiple animals at the same time the print 
 *              statement will put the question and responce on the same line
 *
 *  Testing performed: correct input(for all habitats)
 *                     incorrect input(animal not in list)
 *                     incorrect input(multiple inputs)
 *                     correct input(multiple at the same time)
 *                     incorrect and correct inputs(at the same time)
 *                     incorrect inputs(multiple at the same time)
 */
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "AnimalArrayList.h"
#include "Exhibit.h"

using namespace std;

static int ZOO_SIZE = 6; 

// initialize Zoo
// 
// initializes the AnimalArrayList zoo with the contense of the file "filename"
void initializeZoo(string filename, AnimalArrayList *list);

// fills exhibits from the AnimalArrayList zoo by means the desired variable
void fillExhibits(Exhibit * exhibits[ZOO_SIZE], AnimalArrayList *list);

// prints each exhibit
void printZoo(Exhibit * exhibits[ZOO_SIZE]);

// finds an animal from each exhibit
void findAnimal(string a, Exhibit * exhibits[ZOO_SIZE]);

int main()
{
    // Your code here
	Exhibit * exhibits[ZOO_SIZE];
	exhibits[0] = new Exhibit("African habitat", 1, "africa");
	exhibits[1] = new Exhibit("Asian Habitat", 1, "asia");
	exhibits[2] = new Exhibit("European Habitat", 1, "europe");
	exhibits[3] = new Exhibit("North American Habitat", 
				  1, "north_america");
	exhibits[4] = new Exhibit("Oceana Habitat", 1, "oceania");
	exhibits[5] = new Exhibit("South American Habitat", 
				  1, "south_america");
	AnimalArrayList * zooPoint = new AnimalArrayList; 
	initializeZoo("animals.db", zooPoint);
	fillExhibits(exhibits, zooPoint);
	printZoo(exhibits);
	bool go = true;
	string a = "";
	while(go){
		cout << "enter an animal: ";
		cin >> a;
		if( a == "quit"){
			go = false;
		}
		else{
			findAnimal(a, exhibits);
		}
	}
}

/*  initializeZoo
 *
 *  Reads animal data from the given file, and stores it in the array list
 *
 *  Parameters:  Filename to read data from, a list to store the animals in
 *  Outputs:     None
 *  Effects:     Fills the passed list with animals, adding them to the back
 */
void initializeZoo(string filename, AnimalArrayList *list)
{
        ifstream file;
        Animal a;

        file.open(filename);
        
        if (not file.is_open()) {
            std::cerr << "File " << filename << " could not be opened!" 
                      << std::endl;
            exit(1);
        }

        file >> a.name >> a.origin >> a.diet >> a.ear_size >> a.type;
        while (not file.eof()) {
            list->add(a);
            file >> a.name >> a.origin >> a.diet >> a.ear_size >> a.type;
        }
        file.close();
}

// fillExhibits
//      arguments:a pointer to the array of exhibits and
//                a pointer to an AnimalArrayList
//      returns: none
// purpose: to fill each Exhibit in exhibits with coorisponding animals 
// notes: none
void fillExhibits(Exhibit * exhibits[ZOO_SIZE], AnimalArrayList *list)
{
    // Your code here
	for(int i = 0; i < ZOO_SIZE; i++){
		for(int j = 0; j < (*list).get_num_animals(); j++){
			if(((*list).get_animal_at(j)).origin
			   == (*(exhibits[i])).returnType()){ 
				(*(exhibits[i])).add_animal(
					   (*list).get_animal_at(j));
				(*(exhibits[i])).print_list();
			}
		}
	}
}

// printZoo
//      arguments:a pointer to the array of exhibits
//      returns: none
// purpose: prints out each Exhibit in exhibits 
// notes: none
void printZoo(Exhibit * exhibits[ZOO_SIZE])
{
	for(int i = 0; i < ZOO_SIZE; i++){
		(*(exhibits[i])).print_list();
	}
	cout << endl;
}


// findAnimal
//      arguments: a string animal name and a pointer to the array of exhibits
//      returns: none
// purpose: prints what exhibit(s) the animal is in 
// notes: none
void findAnimal(string a, Exhibit * exhibits[ZOO_SIZE])
{
	int count = ZOO_SIZE;
	for(int i = 0; i < ZOO_SIZE; i++){
		if((*(exhibits[i])).in_Exhibit_name(a)){
			cout << " contains a " << a;
			count -= 1;
		}
	}
	if(count ==  ZOO_SIZE){
		cout << "Animal not found";
	}
	cout << endl;
}
