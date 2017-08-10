#include "displayFile.hpp"

DisplayFile::DisplayFile() {
	pair<int, int> coordX (2, 2);
	pair<int, int> coordY (5, 5);
	list<pair<int, int>> line;
	line.push_back(coordX);
	line.push_back(coordY);
	string oName = "Test Line";
	addObject(new Object(oName, line));
}

DisplayFile::~DisplayFile() {
	for (auto it=objects.begin(); it != objects.end(); ++it) {
		delete it->second;
	}
}

void DisplayFile::addObject(Object* _object) {
	objects[_object->getName()] = _object;
}

Object* DisplayFile::getObjectByName(string _name) {
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

list<Object*> DisplayFile::getAllObjects() {
	list<Object*> allObjects;

	for (auto it=objects.begin(); it != objects.end(); ++it) {
		allObjects.push_back(it->second);
	}

	return allObjects;
}