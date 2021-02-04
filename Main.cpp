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
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList list = LinkedList();
	list.insertItem(ItemType(5));
	list.insertItem(ItemType(7));
	list.insertItem(ItemType(9));
	list.insertItem(ItemType(3));
	list.insertItem(ItemType(1));
	cout << "List value:" << list.visualize() << endl;
	list.deleteItem(9);
	cout << "List value after deleting 9:" << list.visualize() << endl;
	list.makeEmpty();
	cout << "List value after clearing the list:" << list.visualize() << endl;
	list.insertItem(1);
	list.insertItem(3);
	list.insertItem(5);
	list.insertItem(6);
	LinkedList list2 = LinkedList();
	list2.insertItem(ItemType(2));
	list2.insertItem(ItemType(4));
	list2.insertItem(ItemType(6));
	list2.insertItem(ItemType(5));
	list2.insertItem(ItemType(8));
	cout << "List 1: " << list.visualize() << endl;
	cout << "List 2: " << list2.visualize() << endl;
	LinkedList* list3 = list.Union(list2);
	cout << "Union between List1 & List2: " << list3->visualize() << endl;
	delete list3;
	list.makeEmpty();
	list2.makeEmpty();
	return 0;
}
