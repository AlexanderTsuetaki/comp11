// testHighScores.cpp
//           notes: tests the highScoresList.cpp file
//          
// Date Modified: 10/6/18
// Author: Alexander Tsuetaki
//
#include <iostream>
#include <fstream>

#include <highScoresList.h>

int main(){
	highScoresList testList;
	//testList.load();
	testList.clear();// tests clear with nothing
        testList.print();// tests print with nothing
	testList.printTop5(); // test print5 with nothing
	testList.keepTop10(); // tests keepTop10 with nothing
	testList.insert("first", 6900); //seeds list
	testList.insert("second",100);
	testList.insert("third", 1050);
	testList.insert("fourth", 50);
	testList.insert("fifth", 200);
	testList.insert("sixth", 8);
	testList.insert("seventh" , 300);
	testList.insert("eight", 2048);
	testList.insert("ninth", 100030);
	testList.insert("tenth", 290);
	testList.insert("eleventh", 24059);
	testList.insert("first", 2000);
	testList.print(); // prints with full list
	testList.printTop5(); // print5 with full list
	testList.keepTop10(); // keepTop10 with full list
	testList.print(); // print with full list
	testList.save(); // saves list to file
	testList.printUser("first"); // searches for first values
	testList.print(); // prints full list again after search
	testList.clear(); // clears list with full list
	testList.print(); // prints liest after clear
	return 0;
}
