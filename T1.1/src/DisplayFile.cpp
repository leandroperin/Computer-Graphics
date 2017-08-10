#include "../includes/DisplayFile.hpp"

DisplayFile::DisplayFile() {
	pair<int, int> coordX (150, 50);
	pair<int, int> coordY (150, 100);
	list<pair<int, int>> line;
	line.push_back(coordX);
	line.push_back(coordY);
	string oName = "Test Line";
	addObject(new DObject(oName, line));

	pair<int, int> coordX2 (150, 100);
	pair<int, int> coordY2 (200, 100);
	list<pair<int, int>> line2;
	line2.push_back(coordX2);
	line2.push_back(coordY2);
	string oName2 = "Test Line 2";
	addObject(new DObject(oName2, line2));
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