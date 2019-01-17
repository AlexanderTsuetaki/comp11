// Exhibit.cpp
//      purpose: to hold the function of the Exhibit.h header
// Author: Alexander Tsuetaki
// Date modified: 11/17/19

#include "Exhibit.h"
//#include <string>
#include <iostream> 

// Exhibit()
//      arguments: none
//      returns: none
// purpose: to construct the function
// notes: none
Exhibit::Exhibit(std::string n, int th, std::string ty){
	name = n;
	exhibitAnimals = new AnimalArrayList;
	theme = th;
	type = ty;
}


// ~Exhibit()
//      arguments: none
//      returns: none
// purpose: to deconstruct the function
// notes: none
Exhibit::~Exhibit(){
	delete [] exhibitAnimals;
	delete exhibitAnimals;
	theme = 0;
}


// themeChange
//      arguments: an int relating to the theme value of Exhibit
//      returns: a string corresponding to what theme the int vaue is for
// purpose: to change a theme int into a theme string (for printing)
// notes: none
std::string Exhibit::themeChange(int t){
	if(t == 0)
		return "name";
	if(t == 1)
		return "origin";
	if(t == 2)
		return "diet";
	if(t == 3)
		return "ear_size";
	if(t == 4)
		return "type";
	return NULL;
}


// returnType()
//      arguments: none
//      returns: a string relating to the type of the exhibit
// purpose: for comparison of the type of the function and for printing
// notes: none
std::string Exhibit::returnType(){
	return type;
}

// belongs()
//      argumenets: an animal to be determined if it belongs
//      returns: a true of false to answer if it belongs
// purpose: to determine if a cetrian animal belongs in this exhibit
// notes: none
bool Exhibit::belongs(Animal a){
	if(theme == 0){
		return in_Exhibit_name(a.name);
	}
	if(theme == 1){
		return (type == a.origin);
	}
	if(theme == 2){
		return (type == a.diet);
	}
	if(theme == 3){
		return (type == a.ear_size);
	}
	if(theme == 4){
		return (type == a.type);
	}
	return false;
}


// add_animal
//      arguments: an animal to be added to the internal AnimalArrayList
//      returns: none
// purpose: to add an animal to the Exhibits AnimalArrayList
// notes: none
void Exhibit::add_animal(Animal a){
	(*exhibitAnimals).add(a);
}


// in_Exhibit_name
//      arguments: the name of an animal
//      returns: a boolean of wether tha animal is in this exhibit
// purpose: to determine if an animal is in this exhibit by the name of the
//          animal. Also prints out the name of the animal if it is in the 
//          Exhibit
// notes: none
bool Exhibit::in_Exhibit_name(std::string animal_name){
        for(int i = 0; i < (*exhibitAnimals).get_num_animals(); i++){
                if(animal_name == (*exhibitAnimals).get_animal_at(i).name){
			std::cout << name;
			return true;
                }
        }
        return false;
}



// print_list
//      arguments: none
//      returns: none
// purpose: to print a list in a specific way as according to the rubric
// notes: none
void Exhibit::print_list(){
	std::string themec = themeChange(theme);
	std::cout << "Exhibit: " << name << std::endl;
	std::cout << "Characteristic: "<< themec << std::endl;
	std::cout << "Characterisitc Value " << type << std:: endl;
        for(int i = 0; i < (*exhibitAnimals).get_num_animals(); i++){
		std::cout << "---- Animal : "
                          << (*exhibitAnimals).get_animal_at(i).name
                          << std::endl;

        }
}


