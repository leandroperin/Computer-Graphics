#include "../includes/DisplayFile.hpp"

DisplayFile::DisplayFile() {
	pair<int, int> coordX (200, 250);
	pair<int, int> coordY (250, 250);
	list<pair<int, int>> line;
	line.push_back(coordX);
	line.push_back(coordY);
	string oName = "Test Line";
	addObject(new DObject(oName, line));

	pair<int, int> coordX2 (250, 260);
	list<pair<int, int>> dot;
	dot.push_back(coordX2);
	string pName = "Test Dot";
	addObject(new DObject(pName, dot));

	pair<int, int> coordX3 (100, 100);
	pair<int, int> coordX4 (100, 200);
	pair<int, int> coordX5 (200, 200);
	pair<int, int> coordX6 (200, 100);
	list<pair<int, int>> polygon;
	polygon.push_back(coordX3);
	polygon.push_back(coordX4);
	polygon.push_back(coordX5);
	polygon.push_back(coordX6);
	string ppName = "Test Polygon";
	addObject(new DObject(ppName, polygon));
}

DisplayFile::~DisplayFile() {
	for (auto it=objects.begin(); it != objects.end(); ++it) {
		delete it->second;
	}
}

void DisplayFile::addObject(DObject* _object) {
	objects[_object->getName()] = _object;
}

DObject* DisplayFile::getObjectByName(string _name) {
	return objects[_name];
}

void DisplayFile::removeObject(string _name) {
	objects.erase(objects.find(_name));
}

list<string> DisplayFile::getAllNames() {
	list<string> allNames;

	for (auto it=objects.begin(); it != objects.end(); ++it) {
		allNames.push_back(it->first);
	}

	return allNames;
}

list<DObject*> DisplayFile::getAllObjects() {
	list<DObject*> allObjects;

	for (auto it=objects.begin(); it != objects.end(); ++it) {
		allObjects.push_back(it->second);
	}

	return allObjects;
}