/*
 * A test program for StringLinkedLists
 * 
 * (c) Mark A. Sheldon, Tufts University, Spring 2018
 *
 * This program is a driver for some interactive testing.  There
 * are some tests here.  You should add testing code for each 
 * additional list function you write.
 * You will also need to add additional prompts in
 * prompt_for_command(). 
 *
 * Do not worry about the functions getting too long in lab.
 * Concentrate on implementing and testing the functions.
 */


#include <iostream>
#include <fstream>

#include "StringLinkedList.h"

using namespace std;

void   command_loop();
string get_command();
void   prompt_for_command();
void   read_from_file(string fileName, StringLinkedList *strings);
string get_string(string prompt);
int    get_int(string prompt);

int main()
{
        command_loop();
        return 0;
}

/*
 * This is the main command loop.
 * Prompt for a command and then execute it.
 */
void command_loop()
{
        string cmd;
        StringLinkedList strings;

        while ((cmd = get_command()) != "quit") {
                if (cmd == "isEmpty") {
                        if (strings.isEmpty())
                                cout << "yes" << endl;
                        else
                                cout << "no" << endl;
                } else if (cmd == "print") {
                        strings.print();
                        cout << endl;
                } else if (cmd == "prepend") {
                        strings.addToFront(get_string("String?"));
                } else if (cmd == "remove") {
                        strings.removeFirst();
                }
                else if (cmd == "length") {
                        cout << "list has " << strings.length()
                             << " elements" << endl;
                } else if (cmd == "postpend") {
                        strings.addToBack(get_string("String?"));
                } else if (cmd == "addAt") {
                        strings.addAtPosition(get_string("String?"),
                                              get_int("Position?"));
                } else if (cmd == "readFile") {
                        read_from_file(get_string("File?"),
                                       &strings);
                } else if (cmd == "printArtistically") {
                        strings.printArtistically();
                        cout << endl;
                }
                // TODO:  add more cases if you come up with more

        }
}

/*
 * Prompt for and read command from user
 */
string get_command()
{
        string cmd;

        prompt_for_command();
        cin >> cmd;

        return cmd;
}

/*
 * Print the command menu and prompt
 */
void prompt_for_command()
{
        cout << "  isEmpty"                  << endl
             << "  print      the list"      << endl
             << "  prepend    to list"       << endl
             << "  remove     first element" << endl
             << "  length     of list"       << endl
             << "  postpend   to list"       << endl
             << "  addAt      position"      << endl
             << "  printArtistically"        << endl
             << "  readFile"                 << endl
             << "  quit"                     << endl
             << ":  ";
}

/*
 * Prompt for a string and return the user's response
 */
string get_string(string prompt)
{
        string s;

        cout << prompt << ' ';
        cin  >> s;

        return s;
}

/*
 * Prompt for an integer and return the user's response
 */
int get_int(string prompt)
{
        int n;

        cout << prompt << ' ';
        cin  >> n;

        return n;
}

/*
 * Read all the (whitespace delimited) strings from the given file
 * and add them to the list.
 * Adds the strings at the front of the list, so list will have 
 * strings in reverse order.
 * Adding to the back is very slow.  It would be faster to read them
 * in this way, and then reverse the list, if we had such a function.
 */
void read_from_file(string fileName, StringLinkedList *strings)
{
        ifstream input;
        string   s;

        input.open(fileName);
        if (not input.is_open()) {
                cerr << "Could not open file:  " << fileName << endl;
                return;
        }
        for (input >> s; not input.eof(); input >> s)
                strings->addToFront(s);
}
