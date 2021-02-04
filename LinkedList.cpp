#include "LinkedList.h"
#include "ItemType.h"

using namespace std;

LinkedList* LinkedList::Union(LinkedList otherList) {
	//List to return
	LinkedList* newLinkedList = new LinkedList();
	//Current item we are testing
	LinkedItem* item = NULL;
	//Iterates through every item in the list
	for (int i = 0; i < getLength(); i++) {
		//If the item is null, we get the first item on the list
		if (item == NULL)
			item = start;
		//Otherwise we get the next item
		else
			item = item->getChild();
		//If the item is not in the list, add it to the list
		if (newLinkedList->search(item->getValue()) == NULL)
			newLinkedList->insertItem(item->getValue());
	}
	//Same thing as the previous loop but for the second list
	for (int j = 0; j < otherList.getLength(); j++) {
		item = otherList.getItemByIndex(j);
		if (newLinkedList->search(item->getValue()) == NULL)
			newLinkedList->insertItem(item->getValue());
	}
	return newLinkedList;
}
void LinkedList::getNextItem() {
	if (length == 0) return;
	position = position->getChild();
	if (position == NULL)
		position = start;
}
void LinkedList::makeEmpty() {
	//While the list is not empty, delete the first item in it
	while (getLength() > 0) {
		deleteItem(getItemByIndex(0)->getValue());
	}
}
void LinkedList::insertItem(ItemType value) {
	//If the list is at max capacity, return
	if (length == MAX_LENGTH) return;
	LinkedItem* newItem = new LinkedItem(value);
	//If the list is empty
	if (start == NULL) {
		//Create the list with just one item
		start = newItem;
		position = start;
		end = newItem;
	}
	else {
		//Set the current last item's child to the new item
		newItem->setParent(end);
		end->setChild(newItem);
	}
	end = newItem;
	length++;
}
LinkedItem* LinkedList::getItemByIndex(int index) {
	if (index < 0 || index > length) return NULL;
	LinkedItem* currentItem = NULL;
	for (int i = 0; i <= length; i++) {
		if (i == 0)
			currentItem = start;
		else
			currentItem = currentItem->getChild();
		if (i == index)
			return currentItem;
	}
	return NULL;
}
string LinkedList::visualize() {
	string toReturn = "";
	for (int i = 0; i < length; i++) {
		toReturn += "  " + to_string(getItemByIndex(i)->getValue().getValue());
	}
	return toReturn;
}
LinkedItem* LinkedList::search(ItemType value) {
	//Iterates over the list searching for a value that equals the provided one
	for (int i = 0; i < length; i++) {
		LinkedItem* currentItem = getItemByIndex(i);
		if (currentItem->getValue().ComparedTo(value) == EQUAL)
			return currentItem;
	}
	return NULL;
}
void LinkedList::deleteItem(ItemType value) {
	LinkedItem* found = search(value);
	if (found == NULL) return;
	//If our list only has one item, reset the list
	if (length == 1) {
		delete getItemByIndex(0);
		start = NULL;
		end = NULL;
		length = 0;
		return;
	}
	//If the item is the last one on the list
	if (found == end) {
		found->getParent()->setChild(NULL);
		end = found->getParent();
		//If the item is the first one on the lists
	}
	else if (found == start) {
		start = found->getChild();
		found->getChild()->setParent(NULL);
	}
	//If the item is somewhere in the middle of the list
	else {
		//Links the deleted item's parent and child together
		found->getParent()->setChild(found->getChild());
		found->getChild()->setParent(found->getParent());
	}
	delete found;
	length--;
}