/*
 * An interface to a linked list of strings.
 *
 * (c) Mark A. Sheldon, Tufts University, Spring 2018
 */

#ifndef STRING_LINKED_LIST_H
#define STRING_LINKED_LIST_H

#include <string>

class StringLinkedList
{
public:
        StringLinkedList();
        ~StringLinkedList();

        bool isEmpty();
        void addToFront(std::string s);
        std::string firstElement();
        int  length();
        void removeFirst();
        void remove(std::string s);
        void print();
        void printArtistically();
        void addToBack(std::string s);
        void addAtPosition(std::string s, int position);
        
private:
        /*
         * TODO:  Add your Node definition here:
         */
	struct Node{
		std::string element = "";
		Node* next = nullptr; 
	};
	
        /*
         * TODO:  Add your front pointer here:
         */
	Node *ptr;

        /*
         * I defined the following helper functions.
         * You can define them, too, or you can ignore them.
         * If you add additional helper functions, you should
         * add those declarations here.
         */
        Node *newNode(std::string s, Node *next);
        Node *newNode(std::string s);
        Node *addAtPosition(std::string s, int position, Node *current);
        int  length(Node *current);
        void printArtistically(Node *current);
        Node *removeRec(std::string s, Node *firstNode);

        /*
         * Making copy constructor and assignment operator private
         * because we're not implementing them.
         * You do not have to know about these, but you should
         * not pass or return your linked lists by value.
         */
        StringLinkedList(const StringLinkedList &other);
        StringLinkedList &operator=(const StringLinkedList &rhs);
};

#endif
