//bicycles.cpp
//        purpose:gets the # of wheels frames and links and outputs # of bikes
//        notes:Had to change from numbers and words to numbers
//        notes(cont): submitted version with numbers and words originaly
//
//
//Author: Alexander Tsuetaki
//Date Modified: 9/7/18
//

#include <iostream>

using namespace std;

//its the main, it runs the program
int main(){
        
	// initialises the variables needed 
	// comp is the number of components
	// need is the amount of each component is needed
       	// temp is a variable to dump the uneeded components of the input
	int comp[3] = {0,0,0};
	int need[3] = {2,1,50};
        int bikes;
	//string temp = " ";
	bool inval = true;
	//gets input data for the comp array and in a ceritian format
	//use to have to input X wheels, Y frames, Z links
	//now takes X Y Z
	while(inval){
	        inval = false;
		cout << "Please enter input in the form:"
			<<"wheels frames links" << endl;
		//originally had temp between comp0, comp1 and comp2 
		cin >> comp[0] >> comp[1] >> comp[2];
		
		//determines if the inputs are valid(>0)
		if(comp[0] < 0 or comp[1] < 0 or comp[2] < 0){
  		        cout << "you must enter a postive integer" << endl;
			inval = true;
		}
 	}

	// computes how many bikes by setting the # of bikes to how many the
	// limiting factor will allow
	bikes = comp[0];
	for(int i = 0; i<3; i++){
		if( bikes > comp[i]/need[i]){
			bikes = comp[i]/need[i];
		}	
	}	
	
	// outputs the number of bikes followed by the leftover parts
	cout << bikes << " bikes, ";
	if(comp[0]-need[0]*bikes == 0 and comp[1]-need[1]*bikes == 0 
	and comp[2]-need[2]*bikes == 0){
		cout << "0 leftover."<< endl;
	}else{
		cout << "leftover: " << comp[0]-need[0]*bikes << " wheels " 
			<< comp[1]-(need[1]*bikes) << " frames " 
			<< comp[2]-(need[2]*bikes) << " links" << endl;
	}
	return 0;
}

	
