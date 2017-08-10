#include "../includes/Object.hpp"

Object::Object(string _name, list<pair<int, int>> _coordinates) {
	name = _name;
	coordinates = _coordinates;

	getObjectType();
}

string Object::getName() {
	return name;
}

list<pair<int, int>> Object::getCoordinates() {
	return coordinates;
}

string Object::getType() {
	if (type == POINT) return "Point";
	else if (type == LINE) return "Line";
	return "Polygon";
}

void Object::setCoordinates(list<pair<int, int>> _coordinates) {
	coordinates = _coordinates;

	getObjectType();
}

void Object::getObjectType() {
	int coordinatesSize = coordinates.size();

	if (coordinatesSize == 1) type = POINT;
	else if (coordinatesSize == 2) type = LINE;
	else type = POLYGON;
}