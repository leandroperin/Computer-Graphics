#include "../includes/Curva2.hpp"

list<pair<double, double>> Curva2::blend(DObject* obj) {
	list<pair<double, double>> _coordinates;
	list<pair<double, double>> _objCoordinates = obj->getCoordinates();

	pair<double, double> p1;
	pair<double, double> p2;
	pair<double, double> p3;
	pair<double, double> p4;

	int count = 0;
	for (auto it = _objCoordinates.begin(); it != _objCoordinates.end(); ++it) {
		if (count == 0)	p1 = (*it);
		if (count == 1)	p2 = (*it);
		if (count == 2)	p3 = (*it);
		if (count == 3)	p4 = (*it);

		count++;
	}

	for (double t = 0; t <= 1; t += d) {
		pair<double, double> p11 (get<0>(p1) + ((get<0>(p2) - get<0>(p1)) * t), 
								  get<1>(p1) + ((get<1>(p2) - get<1>(p1)) * t));
		pair<double, double> p21 (get<0>(p2) + ((get<0>(p3) - get<0>(p2)) * t), 
								  get<1>(p2) + ((get<1>(p3) - get<1>(p2)) * t));
		pair<double, double> p31 (get<0>(p3) + ((get<0>(p4) - get<0>(p3)) * t), 
								  get<1>(p3) + ((get<1>(p4) - get<1>(p3)) * t));

		pair<double, double> p22 (get<0>(p11) + ((get<0>(p21) - get<0>(p11)) * t), 
								  get<1>(p11) + ((get<1>(p21) - get<1>(p11)) * t));
		pair<double, double> p32 (get<0>(p21) + ((get<0>(p31) - get<0>(p21)) * t), 
								  get<1>(p21) + ((get<1>(p31) - get<1>(p21)) * t));

		pair<double, double> p33 (get<0>(p22) + ((get<0>(p32) - get<0>(p22)) * t), 
								  get<1>(p22) + ((get<1>(p32) - get<1>(p22)) * t));

		_coordinates.push_back(p33);
	}

	return _coordinates;
}