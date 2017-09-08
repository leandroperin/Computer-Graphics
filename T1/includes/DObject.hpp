#ifndef DOBJECT_HPP
#define DOBJECT_HPP

#include <list>
#include <utility>
#include <string>
#include <math.h>

using namespace std;

enum Type { POINT, LINE, POLYGON };

class DObject {
public:
	DObject(string _name, list<pair<double, double>> _coordinates, bool _toFill);
	string getName();
	list<pair<double, double>> getCoordinates();
	list<pair<double, double>> getCoordinatesView();
	list<pair<double, double>> getCoordinatesClipped();
	string getType();
	pair<double, double> getObjectCenter();
	void setCoordinates(list<pair<double, double>> _coordinates);
	void setCoordinatesView(list<pair<double, double>> _coordinates);
	void setCoordinatesClipped(list<pair<double, double>> _coordinates);
	void translade(double Dx, double Dy);
	void resize(double Sx, double Sy);
	void rotate(double o);
	bool getToFill();

private:
	string name;
	list<pair<double, double>> coordinates;
	list<pair<double, double>> coordinatesView;
	list<pair<double, double>> coordinatesClipped;
	Type type;
	bool toFill;
	void getObjectType();
};

#endif