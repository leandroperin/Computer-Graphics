#include "../includes/Clipping.hpp"

Clipping::Clipping(int _lineClippingType) {
	lineClippingType = _lineClippingType;
}

Clipping::~Clipping() {}

int Clipping::getRegionCode(Window* window, pair<double, double> coord) {
	int code = INSIDE;

	if (get<0>(coord) < window->getXwmin())
		code |= LEFT;
	else if (get<0>(coord) > window->getXwmax())
		code |= RIGHT;

	if (get<1>(coord) < window->getYwmin())
		code |= BOTTOM;
	else if (get<1>(coord) > window->getYwmax())
		code |= TOP;

	return code;
}

pair<double, double> Clipping::getInter(pair<double, double> p1, pair<double, double> p2, Window* window, int rCode) {
	double x, y;

	if (rCode & TOP) {
		x = get<0>(p1) + (get<0>(p2) - get<0>(p1)) * (window->getYwmax() - get<1>(p1)) / (get<1>(p2) - get<1>(p1));
		y = window->getYwmax();
	}
	else if (rCode & BOTTOM) {
		x = get<0>(p1) + (get<0>(p2) - get<0>(p1)) * (window->getYwmin() - get<1>(p1)) / (get<1>(p2) - get<1>(p1));
		y = window->getYwmin();
	}
	else if (rCode & RIGHT) {
		x = get<1>(p1) + (get<1>(p2) - get<1>(p1)) * (window->getXwmax() - get<0>(p1)) / (get<0>(p2) - get<0>(p1));
		y = window->getXwmax();
	}
	else if (rCode & LEFT) {
		x = get<1>(p1) + (get<1>(p2) - get<1>(p1)) * (window->getXwmin() - get<0>(p1)) / (get<0>(p2) - get<0>(p1));
		y = window->getXwmin();
	}

	return pair<double, double> (x, y);
}

void Clipping::clip(Window* window, DObject* obj) {
	if (obj->getType() == "Point")
		clipPoint(window, obj);
	else if (obj->getType() == "Line")
		if (lineClippingType == 1)
			clipLiangBarsky(window, obj);
		else if (lineClippingType == 2)
			clipCohenSutherland(window, obj);
	else
		clipSutherlandHodgman(window, obj);
}

void Clipping::clipPoint(Window* window, DObject* obj) {
	pair<double, double> coord = obj->getCoordinatesView().front();
	list<pair<double, double>> coordClipped;

	if (getRegionCode(window, coord) == INSIDE) {
		coordClipped.push_back(coord);
	} else {
		coordClipped.push_back(pair<double, double> (0.0, 0.0));
	}

	obj->setCoordinatesClipped(coordClipped);
}

void Clipping::clipLiangBarsky(Window* window, DObject* obj) {
	list<pair<double, double>> coord = obj->getCoordinatesView();
	list<pair<double, double>> coordClipped;
	pair<double, double> p1, p2;

	int k = 0;
	for (auto it = coord.begin(); it != coord.end(); ++it) {
		if (k % 2 == 0)
			p1 = (*it);
		else {
			p2 = (*it);
			double u1 = 0.0;
			double u2 = 1.0;
			double xD = get<0>(p2) - get<0>(p1);
			double yD = get<1>(p2) - get<1>(p1);
			double p, q, r;
			bool draw = true;

			for (int i = 0; i < 4; i++) {
				switch (i) {
					case 0: {
						p = -1 * xD;
						q = -1 * (window->getXwmin() - get<0>(p1));
						break;
					}
					case 1: {
						p = xD;
						q = (window->getXwmax() - get<0>(p1));
						break;
					}
					case 2: {
						p = -1 * yD;
						q = -1 * (window->getYwmin() - get<1>(p1));
						break;
					}
					case 3: {
						p = yD;
						q = (window->getYwmax() - get<1>(p1));
						break;
					}
				}

				r = q / p;

				if ((p == 0 && q < 0) || (p < 0 && r > u2) || (p > 0 && r < u1)) {
					draw = false;
					break;
				}
				if (p < 0 && r > u1)
					u1 = r;
				if (p > 0 && r < u2)
					u2 = r;
			}

			if (draw) {
				double x1 = get<0>(p1) + u1*xD;
				double y1 = get<1>(p1) + u1*yD;
				double x2 = get<0>(p1) + u2*xD;
				double y2 = get<1>(p1) + u2*yD;

				coordClipped.push_back(pair<double, double> (x1, y1));
				coordClipped.push_back(pair<double, double> (x2, y2));
			}
		}
		k++;
	}

	obj->setCoordinatesClipped(coordClipped);
}

void Clipping::clipCohenSutherland(Window* window, DObject* obj) {
	list<pair<double, double>> coord = obj->getCoordinatesView();
	list<pair<double, double>> coordClipped;
	pair<double, double> p1, p2;

	int k = 0;
	for (auto it = coord.begin(); it != coord.end(); ++it) {
		if (k % 2 == 0)
			p1 = (*it);
		else {
			p2 = (*it);

			int rCode1 = getRegionCode(window, p1);
			int rCode2 = getRegionCode(window, p2);
			bool draw;

			while (true) {
				if (!rCode1 && !rCode2) {
					draw = true;
					break;
				}
				else if (rCode1 && rCode2) {
					draw = false;
					break;
				}
				else {
					int rCodeOut;

					if (rCode1)
						rCodeOut = rCode1;
					else
						rCodeOut = rCode2;

					pair<double, double> inter = getInter(p1, p2, window, rCodeOut);

					if (rCodeOut == rCode1) {
						p1 = inter;
						rCode1 = getRegionCode(window, p1);
					} else {
						p2 = inter;
						rCode2 = getRegionCode(window, p2);
					}
				}
			}
			if (draw) {
				coordClipped.push_back(p1);
				coordClipped.push_back(p2);
			}
		}
		k++;
	}

	obj->setCoordinatesClipped(coordClipped);
}

void Clipping::clipSutherlandHodgman(Window* window, DObject* obj) {
	list<pair<double, double>> coord = obj->getCoordinatesView();

	for (int i = 0; i < 4; i++) {
		int eCode = pow(2, i);
		list<pair<double, double>> temp = coord;

		coord.clear();
		pair<double, double> l = temp.back();

		for (auto it = temp.begin(); it != temp.end(); ++it) {
			int lCode = getRegionCode(window, l);
			int cCode = getRegionCode(window, (*it));

			if (!(cCode & eCode)) {
				if (lCode & eCode)
					coord.push_back(getInter(l, (*it), window, eCode));
				coord.push_back((*it));
			}
			else if (!(lCode & eCode))
				coord.push_back(getInter(l, (*it), window, eCode));

			l = (*it);
		}
	}

	obj->setCoordinatesClipped(coord);
}