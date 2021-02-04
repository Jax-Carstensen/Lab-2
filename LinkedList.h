 /*
	Name:         Jax Carstensen
	Semester:     2
	Due:          02/03/2021
	Lab:          Lab 2 (Unsorted Linked List)
	Description:  A data structure of objects arranged in a linear order. The order is determined by a pointer in each object. 
	See definition on pg. 134 and implementation on pg. 167 of the 6th edition of C++ Plus Data Structures. Your welcome to 
	learn from the books implementation, however, make sure to write your own code. This unsorted list must be implemented 
	with pointers. You will then write a client code that will have a function that will take two unsorted lists and perform 
	the union set operation. The resulting new unsorted list will consist of all the unique items from the original two lists 
	with no duplicates.
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "ItemType.h"

using namespace std;

class LinkedItem {
private:
	ItemType value;
	LinkedItem* child = NULL;
	LinkedItem* parent = NULL;
public:
	~LinkedItem() {
		return;
		delete child;
		delete parent;
	}
	LinkedItem() { value = ItemType(); }
	LinkedItem(ItemType newValue) { value = newValue; }

	void setChild(LinkedItem* newChild) { child = newChild; }
	//Pre:  Another LinkedItem to replace the current child
	//Post: Replaces the current child item with the provided one

	void setParent(LinkedItem* newParent) { parent = newParent; }
	//Pre:  Another LinkedItem to replace the current parent
	//Post: Replaces the current parent item with the provided one

	LinkedItem* getChild() { return child; }
	//Pre:  None
	//Post: Returns this item's child

	LinkedItem* getParent() { return parent; }
	//Pre:  None
	//Post: Returns this item's parent

	void setValue(ItemType newValue) { value = newValue; }
	//Pre:  ItemType to set this LinkedItem's value to
	//Post: Sets this LinkedItem's value

	ItemType getValue() { return value; }
	//Pre:  None
	//Post: Returns this ItemType's value
};


class LinkedList {
private:
	LinkedItem* start = NULL;
	LinkedItem* end = NULL;
	int length = 0;
	const int MAX_LENGTH = 999;
public:
	LinkedList() {}
	~LinkedList() {}
	LinkedItem* position = NULL;

	void getNextItem();
	//Pre:  None
	//Post: Sets the value of position to the next item in the list (or 0 if it reached the end)

	void resetList() { position = start; }
	//Pre:  None
	//Post: Resets the current position in the list

	void insertItem(ItemType value);
	//Pre:  A value to insert into the list
	//Post: Adds that value to the end of the list

	void makeEmpty();
	//Pre:  None
	//Post: Removes all items in the list

	void deleteItem(ItemType value);
	//Pre:  An ItemType to delete
	//Post: Deletes the first occurence of the provided value in the list

	bool isFull() { return MAX_LENGTH == length; }
	//Pre:  None
	//Post: Returns true if the list is at max capacity, and false if it is not

	LinkedItem* search(ItemType value);
	//Pre:  An ItemType to search through the list for
	//Post: Returns the first node in the list containing the value, or NULL if the list doesn't contain the value

	int getLength() { return length; }
	//Pre:  None
	//Post: Returns the length of the list

	LinkedList* Union(LinkedList otherList);
	//Pre:  A second linked list to combine with the current one
	//Post: A list contatining all values from both lists without any duplicates

	LinkedItem* getItemByIndex(int index);
	//Pre:  The index in the list at which a specific item resides
	//Post: The node at the provided position, or NULL if the position is too high or low

	string visualize();
	//Pre:  None
	//Post: Returns a string visualizing all values in the list
};

#endif
