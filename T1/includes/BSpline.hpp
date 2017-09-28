#ifndef BSPLINE_HPP
#define BSPLINE_HPP

#include "DObject.hpp"

class BSpline {
public:
	static list<pair<double, double>> forwardDifferences(DObject* obj);
private:
  static list<pair<double, double>> calcForwardDifferences(list<pair<double, double>> _coord);

};

#endif
