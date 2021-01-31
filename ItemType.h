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
	type value = 0;
public:
	ItemType() {}
	ItemType(type newValue) { value = newValue; }
	RelationType ComparedTo(ItemType otherItem) {
		if (value > otherItem.getValue())
			return GREATER;
		else if (value < otherItem.getValue())
			return LESSER;
		return EQUAL;
	}
	void setValue(type newValue) { value = newValue; }
	type getValue() { return value; }
};
#endif