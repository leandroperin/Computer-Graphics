#ifndef DOBJECT_HPP
#define DOBJECT_HPP

#include <list>
#include <utility>
#include <string>

using namespace std;

enum Type { POINT, LINE, POLYGON };

class DObject {
public:
	DObject(string _name, list<pair<double, double>> _coordinates);
	string getName();
	list<pair<double, double>> getCoordinates();
	string getType();
	void setCoordinates(list<pair<double, double>> _coordinates);
	void setCoordinatesView(list<pair<double, double>> _coordinates);

private:
	string name;
	list<pair<double, double>> coordinates;
	list<pair<double, double>> coordinatesView;
	Type type;
	void getObjectType();
};

#endif