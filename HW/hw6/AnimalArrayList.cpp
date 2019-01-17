#include "AnimalArrayList.h"
#include <iostream>
#include <string>
// AnimalArrayList()
//      arguments: none
//      returns: none
// purpose: constructs the class
// notes: its a constructor
AnimalArrayList::AnimalArrayList(){
	animals = new Animal[INITIAL_CAPACITY];
        num_animals = 0;
        capacity = INITIAL_CAPACITY;
}
// ~AnimalArrayList()
//      arguments: none
//      returns: none
// purpose: deconstructs the class
// notes: its a deconstructor
AnimalArrayList::~AnimalArrayList(){
	delete [] animals;
	delete animals;
}

// add()
//      arguments: animal a
//      returns: none
// purpose: adds an animal to the array of animals
// notes: if the array runs out of room, extend function is called to get a new
//        array.
void AnimalArrayList::add(Animal a){
	std::cout << num_animals << " " << capacity;
        if(num_animals == capacity){
                expand();
        }
        animals[num_animals] = a;
        num_animals += 1;
}

// get_num_animals()
//       arguments: none
//       returns: an num_animals value of the AnimalArrayList
// purpose: return how many animals are in the AnimalArrayList
// notes : none
int AnimalArrayList::get_num_animals(){
        return num_animals;
}

// get_animal_at()
//       arguments: an integer for the index of the animal you want
//       returns: the Animal at that index
// purpose: to return the animal that was at that index
// notes: none
Animal AnimalArrayList::get_animal_at(int index){
        return *(animals+index);
}

// expand()
//       arguments: none
//       returns: none
// purpose: to reassign the animals array to a new memory location that can
//         store the number of values needed by assigning a memory location 
//         with the storage space after it to hold double the current capacity 
void AnimalArrayList::expand(){
        Animal *temp = new Animal[capacity*2];
        for(int i = 0; i < num_animals; i++)
                temp[i] = animals[i];
        capacity *= 2;
        delete [] animals;
        animals = temp;
}
