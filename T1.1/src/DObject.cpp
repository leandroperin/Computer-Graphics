#include "../includes/DObject.hpp"

DObject::DObject(string _name, list<pair<int, int>> _coordinates) {
	name = _name;
	coordinates = _coordinates;

	getObjectType();
}

string DObject::getName() {
	return name;
}

list<pair<int, int>> DObject::getCoordinates() {
	return coordinates;
}

string DObject::getType() {
	if (type == POINT) return "Point";
	else if (type == LINE) return "Line";
	return "Polygon";
}

void DObject::setCoordinatesView(list<pair<int, int>> _coordinates) {
	coordinatesView = _coordinates;
}

void DObject::setCoordinates(list<pair<int, int>> _coordinates) {
	coordinates = _coordinates;
}

void DObject::getObjectType() {
	int coordinatesSize = coordinates.size();

	if (coordinatesSize == 1) type = POINT;
	else if (coordinatesSize == 2) type = LINE;
	else type = POLYGON;
}