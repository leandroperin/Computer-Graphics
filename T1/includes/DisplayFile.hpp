#ifndef DISPLAYFILE_HPP
#define DISPLAYFILE_HPP

#include <string>
#include <list>
#include <map>
#include "DObject.hpp"

using namespace std;

class DisplayFile {
public:
	DisplayFile();
	virtual ~DisplayFile();
	void addObject(DObject* _dobject);
	DObject* getObjectByName(string _name);
	void removeObject(string _name);
	list<string> getAllNames();
	list<DObject*> getAllObjects();

private:
	map<string, DObject*> objects;

};

#endif