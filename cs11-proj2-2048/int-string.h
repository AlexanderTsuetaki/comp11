#ifndef INTSTRING_H
#define INTSTRING_H

#include <string>

/* Convert a string to an int. Returns the int form of the given string.
   Throw logic error if the string is not numerical. */
int string2int(std::string s);


/* Converts an int to string.
   Returns the string form of the given int */
std::string int2string(int num);

#endif
