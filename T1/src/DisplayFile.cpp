#include "../includes/DisplayFile.hpp"

DisplayFile::DisplayFile() {}

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