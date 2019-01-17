#include <cstdlib>
#include <iostream>
#include <fstream>
//
//  Note: this leaks memory
//

using namespace std;

static const int  SEED       = 1124;
static const int  LEN        = 100;
static       char wordlist[] = "/usr/share/dict/words";

struct Item {
        int      num;
        string  *wordptr;
};

struct Link {
        Item  data;
        Link *next;
};

//
// this file contains 
//
static void setup();
int     *numgen();
string **strptrgen();
Item    *itemlistgen();
Item   **itemptrlistgen(bool singles);
Link    *ll_gen();

string words[LEN];

//
// generates an array of integers
//
int *numgen()
{
        int *list = new int[LEN];

        setup();

        for (int i = 0; i < LEN; i++) {
                list[i] = rand() % 1000;
        }
        return list;
}

//
// generate an array of pointers to strings
//
string **strptrgen()
{
        string **list = new string * [LEN];
        int      jumbos;
        int      spot;
        string  *strptr;
        
        setup();

        for (int i = 0; i < LEN; i++)
                list[i] = NULL;

        jumbos = ( 1 + (rand() % 20) );
        // cout << "Dropping " << jumbos << endl;
        
        for (int i = 0; i < jumbos; i++ ) {
                spot        = rand() % LEN;
                list[spot]  = new string;
                *list[spot] = "Jumbo";
        }

        for (int i = 0; i < LEN; i++) {
                if (list[i] != NULL)
                        continue;
                if ((rand() % 8) != 0) {
                        strptr = new string;
                        *strptr = words[(rand() % LEN)];
                        list[i] = strptr;
                }
        }
        return list;
}

//
// build the two lists, merge them, free the two lists
//
Item *itemlistgen_(int);

Item *itemlistgen()
{
        setup();

        return itemlistgen_(LEN);
}

//
// make an array of structs of size len
//
Item *itemlistgen_(int len)
{

        int      *nums;
        string  **ptrs;
        Item     *list = new Item[len];

        nums = numgen();
        ptrs = strptrgen();

        for (int i = 0; i < len; i++) {
                list[i].num     = nums[i];
                list[i].wordptr = ptrs[i];
        }
        return list;
}

//
// create an array of pointers to single structs
// or to arrays of structs
//
Item **itemptrlistgen(bool singles)
{
        Item **list  = new Item * [LEN];
        Item  *nodes = itemlistgen();
        int    numnulls;
        int    spot;

        setup();

        if (singles) {
                //
                // make pointers to the structs already in the
                // list of structs
                //
                for (int i = 0; i < LEN; i++) {
                        list[i] = &(nodes[i]);
                }
                
                // then drop nulls in a few places
                numnulls = rand() % 10;
                while (numnulls != 0) {
                        spot = rand() % LEN;
                        if (list[spot] == NULL)
                                continue;
                        if (list[spot]->wordptr == NULL)
                                continue;
                        if (*(list[spot]->wordptr) == "Jumbo")
                                continue;
                        list[spot] = NULL;
                        numnulls--;
                }
        } else {
                int     row;
                int     cols;

                for (row = 0; row < LEN; row++) {
                        if ((rand() % 15) == 0) {
                                list[row] = NULL;
                                continue;
                        }
                        // get an array of nodes
                        cols = 1 + (rand() % 6);
                        nodes = itemlistgen_(cols);
                        nodes[cols - 1].wordptr = NULL;
                        nodes[cols - 1].num     = 0;
                        list[row] = nodes;
                }
        }
        return list;
}

//
// make a linked list of nodes holding an Item and a next ptr
//
Link *ll_gen()
{
        Link    *head = NULL;
        Link    *newone;
        int     *nums = numgen();

        int     num = LEN;
        int     i;
        int     r;

        setup();

        for (i = 0; i < num; i++) {
                newone       = new Link;
                newone->next = head;
                head         = newone;
                r            = rand() % 20;

                if (r == 0) {
                        newone->data.wordptr = NULL;
                } else {
                        newone->data.wordptr = new string;
                        newone->data.num     = nums[i];
                        if (r < 5) {
                                *(newone->data.wordptr) = "Jumbo";
                        } else {
                                *(newone->data.wordptr) = words[i];
                        }
                }
        }
        return head;
}
                
                
static void setup()
{
        static bool was_set = false;
        ifstream   input;
        int        pos;
        int        skip;
        string     str;

        if (was_set)
                return;
        was_set = true;
        srand(SEED);
        pos = 0;
        input.open(wordlist);
        if (input.fail()) {
                cerr << "Cannot open wordlist\n";
                exit(1);
        }
        while (pos < LEN) {
                skip = rand() % 100;
                for (int i = 0; i < skip; i++)
                        getline(input, str);
                words[pos++] = str;
        }
        input.close();
}
