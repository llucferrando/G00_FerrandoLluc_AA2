#include "Box.h"

Box::Box()
{
	myElement =nullptr;
	myBoxPosition = new Vector2D(0, 0);
}

void Box::PrintBox()
{
	if (myElement == nullptr) {
		std::cout << " ";
	}
	else {
		std::cout << myElement->elementCharacter;
	}
	

}

void Box::PrintGameElements(MapElements* newMapElement)
{
	this->myElement = newMapElement;
}
