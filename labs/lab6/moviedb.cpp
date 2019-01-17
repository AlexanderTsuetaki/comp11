// moviedb.cpp
//         purpose: stores and pulls movie data
//         notes:
// Author: Alexander Tsuetaki
// Data: 10/17/18
//

#include <iostream>
#include <fstream>

using namespace std;

const int Num_Movies = 450;

struct Movie{
	string title;
	int year;
	int gross;
	string director;
	string top_actors[5];
};

void fill_movie_array(Movie[], string);
void list_movie_year(Movie[], int);
void movie_grosses(Movie[]);
void print_movie(Movie);
void filmography(Movie[], string);

int main(){
	Movie movies[450];
	int year;
	fill_movie_array(movies,"moviedata.txt");
	cout << "name a year that you want to check for movies"<< endl;
	cin >> year;
	list_movie_year(movies, year);
	movie_grosses(movies);
	filmography(movies,"Tobey Maguire");
	return 0;
}

void print_movie(Movie movie){
	cout << movie.title << endl;
	cout << "     " << movie.year << endl;
	cout << "     " << movie.gross << endl;
	cout << "     " << movie.director << endl;
	cout << "     " << movie.top_actors[0] << endl;
}

void fill_movie_array(Movie movies[], string file){
	ifstream inFile;
	inFile.open(file);
	if(not inFile.is_open()){
	       	cout << "unable to find file" << file << endl;
	}
	for (int i = 0; i < Num_Movies; i++){
		getline (inFile, movies[i].title);
		inFile >> movies[i].year;
		inFile >> movies[i].gross;
		getline (inFile, movies[i].director);
		getline (inFile, movies[i].director);
		for(int j = 0; j < 5; j++){
			getline(inFile, movies[i].top_actors[j]);
		}
		print_movie(movies[i]);
	}
	
}

void list_movie_year(Movie movies[], int year){
	for(int i = 0; i < Num_Movies; i++){
		if(movies[i].year == year){
			cout << movies[i].title << endl;
		}
	}
}

void movie_grosses(Movie movies[]){
	string names[2] = {movies[0].title, movies[0].title};
	int most = movies[0].gross;
	int least = movies[0].gross;
	double total = 0;
	for(int i = 0; i < Num_Movies; i++){
		if(movies[i].gross > most){
			names[0] = movies[i].title;
		}
		else if(movies[i].gross < least){
			names[1] = movies[i].title;
		}
		total += movies[i].gross;
	}
	total = total/450;
	cout << "the higherst grossing film was: " << names[0] << endl;
	cout << "the lowest gorssing film was: " << names[1] << endl;
	cout << "the adverage of all films was: " << (total) << endl;
}
	

void filmography(Movie movies[], string actor){
	for(int i = 0; i < Num_Movies; i++){ 
		for(int j = 0; j < 5; j++){
			if(movies[i].top_actors[j] == actor){
				cout << movies[i].title << endl;
			}
		}
	}
}
