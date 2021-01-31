#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "ItemType.h"

using namespace std;

class LinkedItem {
private:
	ItemType value;
	LinkedItem* child;
	LinkedItem* parent;
public:
	void setChild(LinkedItem* newChild) { child = newChild; }
	void setParent(LinkedItem* newParent) { parent = newParent; }
	LinkedItem* getChild() { return child; }
	LinkedItem* getParent() { return parent; }
	LinkedItem(ItemType newValue) { value = newValue; }
	void setValue(ItemType newValue) { value = newValue; }
	ItemType getValue() { return value; }
};


class LinkedList {
private:
	LinkedItem* start = NULL;
	LinkedItem* end = NULL;
	int length = 0;
	const int MAX_LENGTH = 999;
public:
	//getItemByIndex is much handier than using the position pointer in my opinion but it was required in the specifications
	LinkedItem* position = NULL;
	void getNextItem();
	void resetList() { position = start; }
	void insertItem(ItemType value);
	void makeEmpty();
	void deleteItem(ItemType value);
	bool isFull() { return MAX_LENGTH == length; }
	LinkedItem* search(ItemType value);
	int getLength() { return length; }
	LinkedList Union(LinkedList otherList);
	//Returns the item at the specified index
	LinkedItem* getItemByIndex(int index);
	//Creates a string that displays all values in the list
	string visualize();
};

#endif