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
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
typedef int type;

enum RelationType {
	LESSER,
	GREATER,
	EQUAL
};

class ItemType {
private:
	type value;
public:
	ItemType() { value = 0; }
	ItemType(type newValue) { value = newValue; }

	RelationType ComparedTo(ItemType otherItem) {
		if (value > otherItem.getValue())
			return GREATER;
		else if (value < otherItem.getValue())
			return LESSER;
		return EQUAL;
	}
	//Pre:  An ItemType to compare to
	//Post: GREATER if this ItemType's value is higher, LESSER if it is lesser, and EQUAL if the values are the same

	void setValue(type newValue) { value = newValue; }
	//Pre:  An int (in this case) to set this item's value to
	//Post: Sets this item's value to the provided one

	type getValue() { return value; }
	//Pre:  None
	//Post: Returns this item's value
};
#endif
