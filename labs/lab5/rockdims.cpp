/*
 * rockdims.cpp -- analyze height and width of a digital image
 *
 *  input has "." background  and "x" for rock
 */

#include <iostream>
using namespace std;

const int WIDTH  = 200;
const int HEIGHT = 50;

const char SPACE = '.';
const char ROCK  = 'x';

// declarations go here

int top(char[50][200]);
int bottom(char[50][200]);
int left(char[50][200]);
int right(char[50][200]);


// main should be very short, just an outline

int main() 
{
        char image[HEIGHT][WIDTH];
	image[0][0] = SPACE;
	for(int i = 0; i < HEIGHT; i++){
	        cin >> image[i];
	}
	cout << "the height is " << bottom(image) - top(image) << endl;
        cout << "the width is " << right(image) - left(image) << endl;
}

// helper functions go here

// top 
//         arguments: a copy of the master array
//         returns: the top most value that is a 'i'
// notes : searches from the top down and left to right
int top(char image[HEIGHT][WIDTH]){
        for(int i = 0; i < HEIGHT ; i++){
                for(int j = 0; j< WIDTH; j++){
                        if(image[i][j] == ROCK)
	                        return i;
		}
	}
	return 50;
}
// bottom
//         arguments: copy of the master array
//         returns: the bottom most value in the array that is a 'x'
// notes: searches from the bottom up and left to right
int bottom(char image[HEIGHT][WIDTH]){
       for(int i = 0; i < HEIGHT; i++){
	        for(int j = 0; j < WIDTH; j++){
	                if(image[49-i][j] == ROCK){
	                        return (HEIGHT - i);
			}
		}		
       }
       return 0;
}

// left
//         arguments: copy of the master array
//         returns: the left most value in the array that is a 'x'
// notes: searches from left to right and from top to bottom
int left(char image[HEIGHT][WIDTH]){
        for(int j = 0; j < WIDTH; j++){
                for(int i = 0; i < HEIGHT; i++){
		        if(image[i][j] == ROCK){
			        return j;
		        }
		}
	}
	return 200;
}
// right
//         arguments: copy of the master array
//         returns the right most value 
// notes: searches from the right to left and top to bottom. 
int right(char image[HEIGHT][WIDTH]){
        for(int j = 0; j < WIDTH; j++){
	        for(int i = 0; i< HEIGHT; i++){
		        if (image[i][199-j] == ROCK){
			        return (WIDTH - j);
			}
		}
	}
	return 0;
}
