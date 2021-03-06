#include <iostream>
#include <fstream>

using namespace std;

// -- Introduce the Actor struct, just so we can use it in the Movie struct
struct Actor;

// -- Struct to hold data for one movie. Initially, the actors will be stored as
//    an array of names, but then we'll look up the names and point to Actor
//    structs.
struct Movie
{
  string title;
  int year;
  double gross;
  string director;
  string actor_names[5];
  Actor * actors[5];
};

// -- Struct to hold data about one actor. Since we don't know how many movies
//    an actor has been in, we will leave room for 100, but keep a count of the
//    actual number.
struct Actor
{
  string name;
  int num_movies;
  Movie * movies[100];
};

/** Read a line
 *
 *  This is a version that actually works as you would expect (arg!)
 *  DON'T WORRY about how this function works.
 */
string read_line(istream& in)
{
  // -- Consume any extraneous white-space (including newline) at the end
  //    of the previous line
  char t;
  t = in.peek();
  while (isspace(t) && ! in.eof()) {
    in.ignore();
    t = in.peek();
  }
  
// -- Now read the line
  string result;
  getline(in, result);
  return result;
}

/** Read one movie
 *
 *  Read in all the data about a single movie, store in a newly created Movie struct.
 */
Movie * read_movie(istream& file)
{
  // -- Create a new movie struct
  Movie * m = new Movie;
  
  // -- Read in the title, year, gross, and director
  m->title = read_line(file);
  file >> m->year;
  file >> m->gross;
  m->director = read_line(file);

  // -- Read in the five top-billed actors
  for (int i = 0; i < 5; i++) {
    m->actor_names[i] = read_line(file);
  }

  // -- For debugging: print out some info
  // cout << m->title << " starring " << m->actor_names[0] << endl;

  return m;
}

// Problem 1: Actor lookup

// ...PUT YOUR CODE HERE...
//lookup_actor

Actor * lookup_actor(string name, Actor * all_actors[], int num_actors){
	for(int i = 0; i < num_actors; i++){
		if (*all_actors)[i].name == name){
			return all_actors[i];
		}
	}
	return NULL;
}
// Problem 2: Make actor

// ...PUT YOUR CODE HERE...
//

Actor * make_actor(string name){
	Actor temp;
	temp.name = name;
	temp.num_movies = 0;
	for(int i = 0; i < 100; i++){
		temp.movies[i] = NULL;
	}
	return &temp;
}
// Problem 3: Add movie

// ...PUT YOUR CODE HERE...

void add_movie(Actor * actor, Movie * movie){
	((*actor).movie[(*actor).num_movies] = &movie;
	(*actor).num_movies += 1;
}

int main()
{
  // -- Read in the movie data
  ifstream file;
  Movie * movies[450];

  file.open("moviedata.txt");
  if ( ! file.fail()) {
    for (int i = 0; i < 450; i++) {
      movies[i] = read_movie(file);
    }
    file.close();
  } else {
    cout << "Could not open moviedata.txt" << endl;
    return -1;
  }

  // -- Problem 4: Build the database...
  Actor * all_actors[2000];
  int num_actors = 0;
  int k = 0;
  bool go = true;
  for(int i = 0; i < 450; i++){
	  for(int j < 5; j++){
		  if(lookup_actor((*movies)[i].(*actors)[j]; all_actors, num_actors)
		     == NULL){
			  (*all_actors)[num_actors] = 
				  make_actor((*movies)[i].(*actors)[j].name);
			  add_movie((*all_actors)[num_actors], (*movies)[i]);
			  k = 0;
			  while(k < 5 and go){
				  if((*movies)[i].actors[k] == NULL){
					  (*movies)[i].actors[k] = 
						  &(*all_actors)[num_actors];
					  go = false;
				  }
			  }			  
			  num_actors++;
		  }
		  
	  }
  }
  // ...PUT YOUR CODE HERE...

  // -- Problem 5: Actor filmography
  cout << "give the name of an actor (or actress) to lookup)" << endl;
  string act = read_line(cin);

  Actor * a = lookup_actor(act, all_actors, num_actors);
  for(int x = 0; x < (*a).num_movies; x++){
	  cout << (*(*a).movies[(*a).num_movies]).title << endl;
  }

  // -- Problem 6: Films in common
  cout << "type two actors names, to print all the films they have in common" << endl;
  string act1 = read_line(cin);
  string act2 = read_line(cin);
  
  // ...PUT YOUR CODE HERE...
  Actor * b = lookup_actor(act1, all_actors, num_actors);
  Actor * c = lookup_actor(act2, all_actors, num_actors);
  for(int y = 0; y < (*b).num_movies; y++){
	  for(int z = 0; z< (*c).num_movies; z++){
		  if((*(*b).movies[y]).title == (*(*c).movies[z]).title){
			  cout << ((*(*b).movies[y]).title) << endl;
		  }
	  }
  }

  return 0;
}

