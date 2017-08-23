#ifndef DOBJECT_HPP
#define DOBJECT_HPP

#include <list>
#include <utility>
#include <string>

using namespace std;

enum Type { POINT, LINE, POLYGON };

class DObject {
public:
	DObject(string _name, list<pair<int, int>> _coordinates);
	string getName();
	list<pair<int, int>> getCoordinates();
	string getType();
	void setCoordinates(list<pair<int, int>> _coordinates);
	void setCoordinatesView(list<pair<int, int>> _coordinates);

private:
	string name;
	list<pair<int, int>> coordinates;
	list<pair<int, int>> coordinatesView;
	Type type;
	void getObjectType();
};

#endif