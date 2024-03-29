
#include <iostream>
#include <fstream>

#include "highScoresList.h"

using namespace std;
/* Constructor */
highScoresList::highScoresList() {

	start = new Score;
	load();
}

highScoresList::~highScoresList(){
	save();
	clear();
	start = nullptr;
}
/* 
 * load()
 * Reads the HIGH_SCORE_FILE and loads the contents of the file
 * into the linked list.
 * If the file does not exist, do nothing. 
 */
void highScoresList::load() {
    ifstream inFile;
    inFile.open(HIGH_SCORE_FILE);
    if (not inFile) {
        return;
    }
    string user;
    int score;
    Score* temp = start;
    while (inFile >> user and user != SENTINEL){
	    inFile >> score;
	    (*temp).name = user;
	    (*temp).score = score;
	    (*temp).next = new Score;
	    temp = (*temp).next;
    }
    inFile.close();
}

/* 
 * save()
 * Writes the names and scores to the HIGH_SCORE_FILE, followed by the 
 * sentinel.
 * This will overwrite what was originally in HIGH_SCORE_FILE.
 */
void highScoresList::save() {
    ofstream outFile;
    outFile.open(HIGH_SCORE_FILE);    
    string name = "";
    int score = 0;
    Score* temp = start;
    while(temp != nullptr){
	    name = (*temp).name;
	    score = (*temp).score;
	    outFile << name << " " << score << endl;
	    if((*temp).name == ""){
		    temp = nullptr;
	    }
	    else{
		    temp = (*temp).next;
	    }
    }
    outFile << SENTINEL << endl;
    outFile.close();
    print();
}   

//returns Highest Score;
int highScoresList::highestScore(){
	return (*start).score;
}

// prints the entire array list
void highScoresList::print(){
	Score *temp = start;
	while(temp != nullptr and temp != 0){
		cout <<(*temp).name << " " << (*temp).score << endl;
		temp = (*temp).next;
	}
}

// prints the top 5 entrys in the array list
void highScoresList::printTop5(){
	Score *temp = start;
	if((*temp).next != nullptr){
		for(int i = 0; i < 5; i++){
			if(temp != nullptr and (*temp).name != ""){
				cout << (*temp).name << " " 
				     << (*temp).score << endl;
				temp = (*temp).next;
			}			      
		}
	}
}

// keeps only the top 10 score;
void highScoresList::keepTop10(){
	Score *temp = start;
	Score *del = nullptr;
	for(int i = 0; i < 9; i++){
		if((*temp).next != nullptr)
			temp = (*temp).next;
	}
	if((*temp).next == nullptr)
		del = nullptr;
	else if ((*temp).next != nullptr){
		del = (*temp).next;
		(*temp).next = nullptr;
	}
	while(del != nullptr){
		if ((*del).next != nullptr){
			temp = (*del).next;
			delete del;
			del = temp;
		}		
		else{
			delete del;
			del = nullptr;
		}
	}
}

// inserts a new score into the array list by its score;
void highScoresList::insert(string user, int score){
	Score *nScore = new Score;
	(*nScore).score = score;
	(*nScore).name = user;
	Score *temp = start;
	if((*temp).score == 0 and (*temp).name == "" 
	   and (*temp).next == nullptr){
		(*start).name = user;
		(*start).score = score;
	}
	else if(temp == start and (*temp).score < score 
		and (*temp).name != ""){
		(*nScore).next = start;
		start = nScore;
	}
	else{
		while((*temp).next != nullptr and 
		      (*((*temp).next)).score > score and
		      (*temp).name != ""){	
			temp = (*temp).next;
		}
		(*nScore).next = (*temp).next;
		(*temp).next = nScore;
	} 
	temp = start;
	while(temp != nullptr and (*temp).next != nullptr){
		if((*((*temp).next)).name == ""){
			(*temp).next = nullptr;
		}
		temp = (*temp).next;
	}
	keepTop10();
}

// deletes the lists heap memory
void highScoresList::clear(){
	Score *currScore = start;
	Score *nextScore = nullptr;
	if((*currScore).next != nullptr)
		nextScore = (*start).next;
	while(currScore != nullptr){
		if((*currScore).next != nullptr){
			nextScore = (*currScore).next;
			delete currScore;
			currScore = nextScore;
		}     
		else{
			delete currScore;
			break;
			//currScore = nullptr;
		}
	}
	start = new Score;
	//(*start).name = "";
	//(*start).score = -1;
	//(*start).next = nullptr;
	//set next node later;

}

// prints all the socres of a user
void highScoresList::printUser(string user){
	Score *temp = start;
	cout << user << endl;
	while(temp != nullptr){
		if((*temp).name == user){
			cout << (*temp).score << endl;
		}
		temp = (*temp).next;
	}
}
//not implimented;
void highScoresList::deleteUser(string user){
	cout << "NOT IMPLIMENTED YET KAPPA" << user;
}




