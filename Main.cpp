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
