#include "../includes/DObject.hpp"

#define PI 3.14159265

DObject::DObject(string _name, list<pair<double, double>> _coordinates, bool _toFill) {
	name = _name;
	coordinates = _coordinates;
	toFill = _toFill;

	getObjectType();
}

DObject::DObject(string _name, list<pair<double, double>> _coordinates, bool _toFill, Type _type) {
	name = _name;
	coordinates = _coordinates;
	toFill = _toFill;
	type = _type;
}

string DObject::getName() {
	return name;
}

bool DObject::getToFill() {
	return toFill;
}

list<pair<double, double>> DObject::getCoordinates() {
	return coordinates;
}

list<pair<double, double>> DObject::getCoordinatesView() {
	return coordinatesView;
}

list<pair<double, double>> DObject::getCoordinatesClipped() {
	return coordinatesClipped;
}

string DObject::getType() {
	if (type == POINT) return "Point";
	else if (type == LINE) return "Line";
	else if (type == POLYGON) return "Polygon";
	return "Curve";
}

void DObject::setCoordinatesView(list<pair<double, double>> _coordinates) {
	coordinatesView = _coordinates;
}

void DObject::setCoordinates(list<pair<double, double>> _coordinates) {
	coordinates = _coordinates;
}

void DObject::setCoordinatesClipped(list<pair<double, double>> _coordinates) {
	coordinatesClipped = _coordinates;
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

pair<double, double> DObject::getObjectCenter() {
	double sumX = 0.0;
	double sumY = 0.0;
	int n = coordinates.size();

	for (auto it = coordinates.begin(); it != coordinates.end(); ++it) {
		sumX += get<0>(*it);
		sumY += get<1>(*it);
	}

	pair<double, double> C (sumX / n, sumY / n);
	return C;
}

void DObject::resize(double Sx, double Sy) {
	list<pair<double, double>> _coordList;

	pair<double, double> C = getObjectCenter();
	double Cx = get<0>(C);
	double Cy = get<1>(C);

	double T[3][3];
	T[0][0] = Sx; T[0][1] = 0.0; T[0][2] = 0.0;
	T[1][0] = 0.0; T[1][1] = Sy; T[1][2] = 0.0;
	T[2][0] = 0.0; T[2][1] = 0.0; T[2][2] = 1.0;

	double A[3][3];
	A[0][0] = 1.0; A[0][1] = 0.0; A[0][2] = 0.0;
	A[1][0] = 0.0; A[1][1] = 1.0; A[1][2] = 0.0;
	A[2][0] = 0.0 - Cx; A[2][1] = 0.0 - Cy; A[2][2] = 1.0;

	double B[3][3];
	B[0][0] = 1.0; B[0][1] = 0.0; B[0][2] = 0.0;
	B[1][0] = 0.0; B[1][1] = 1.0; B[1][2] = 0.0;
	B[2][0] = 0.0 + Cx; B[2][1] = 0.0 + Cy; B[2][2] = 1.0;

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
				_P[0][i] += P[0][j] * A[j][i];
			}
		}

		P[0][0] = _P[0][0]; P[0][1] = _P[0][1]; P[0][2] = _P[0][2];
		_P[0][0] = 0.0; _P[0][1] = 0.0; _P[0][2] = 0.0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				_P[0][i] += P[0][j] * T[j][i];
			}
		}

		P[0][0] = _P[0][0]; P[0][1] = _P[0][1]; P[0][2] = _P[0][2];
		_P[0][0] = 0.0; _P[0][1] = 0.0; _P[0][2] = 0.0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				_P[0][i] += P[0][j] * B[j][i];
			}
		}

		double _x = _P[0][0];
		double _y = _P[0][1];

		pair<double,double> _coord (_x, _y);
		_coordList.push_back(_coord);
	}

	coordinates = _coordList;
}

void DObject::rotate(double o) {
	double sinO = sin(o*PI/180);
	double cosO = cos(o*PI/180);

	list<pair<double, double>> _coordList;

	double T[3][3];
	T[0][0] = cosO; T[0][1] = 0.0 - sinO; T[0][2] = 0.0;
	T[1][0] = sinO; T[1][1] = cosO; T[1][2] = 0.0;
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