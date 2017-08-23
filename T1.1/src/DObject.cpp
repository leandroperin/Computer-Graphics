#include "../includes/DObject.hpp"

DObject::DObject(string _name, list<pair<double, double>> _coordinates) {
	name = _name;
	coordinates = _coordinates;

	getObjectType();
}

string DObject::getName() {
	return name;
}

list<pair<double, double>> DObject::getCoordinates() {
	return coordinates;
}

string DObject::getType() {
	if (type == POINT) return "Point";
	else if (type == LINE) return "Line";
	return "Polygon";
}

void DObject::setCoordinatesView(list<pair<double, double>> _coordinates) {
	coordinatesView = _coordinates;
}

void DObject::setCoordinates(list<pair<double, double>> _coordinates) {
	coordinates = _coordinates;
}

void DObject::getObjectType() {
	int coordinatesSize = coordinates.size();

	if (coordinatesSize == 1) type = POINT;
	else if (coordinatesSize == 2) type = LINE;
	else type = POLYGON;
}

void DObject::translade(double Dx, double Dy) {
	list<pair<double, double>> _coordList;

	double T[3][3];
	T[0][0] = 1.0; T[0][1] = 0.0; T[0][2] = 0.0;
	T[1][0] = 0.0; T[1][1] = 1.0; T[1][2] = 0.0;
	T[2][0] = Dx; T[2][1] = Dy; T[2][2] = 1.0;

	for (auto it = coordinates.begin(); it != coordinates.end(); ++it) {
		double _P[1][3];
		double P[1][3];

		_P[0][0] = 0.0; _P[0][1] = 0.0; _P[0][2] = 0.0;

		P[0][0] = get<0>(*it);
		P[0][1] = get<1>(*it);
		P[0][2] = 1.0;

		// Matrix multiplication
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				_P[0][i] += P[0][j] * T[j][i];
			}
		}

		double _x = _P[0][0];
		double _y = _P[0][1];

		pair<double,double> _coord (_x, _y);
		_coordList.push_back(_coord);
	}

	coordinates = _coordList;
}

void DObject::resize(double Sx, double Sy) {
	list<pair<double, double>> _coordList;

	double T[3][3];
	T[0][0] = Sx; T[0][1] = 0.0; T[0][2] = 0.0;
	T[1][0] = 0.0; T[1][1] = Sy; T[1][2] = 0.0;
	T[2][0] = 0.0; T[2][1] = 0.0; T[2][2] = 1.0;

	for (auto it = coordinates.begin(); it != coordinates.end(); ++it) {
		double _P[1][3];
		double P[1][3];

		_P[0][0] = 0.0; _P[0][1] = 0.0; _P[0][2] = 0.0;

		P[0][0] = get<0>(*it);
		P[0][1] = get<1>(*it);
		P[0][2] = 1.0;

		// Matrix multiplication
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				_P[0][i] += P[0][j] * T[j][i];
			}
		}

		double _x = _P[0][0];
		double _y = _P[0][1];

		pair<double,double> _coord (_x, _y);
		_coordList.push_back(_coord);
	}

	coordinates = _coordList;
}