#include "../includes/BSpline.hpp"

list<pair<double, double>> BSpline::forwardDifferences(DObject* obj) {
    list<pair<double, double>> _coordinates;
    list<pair<double, double>> _objCoordinates = obj->getCoordinates();

    for (int i = 0; i < _objCoordinates.size() - 3; i++) {
        list<pair<double, double>> tempCurve;

        auto it = _objCoordinates.begin();
        advance(it, i);

        for (int j = 0; j < 4; j++) {
          tempCurve.push_back(make_pair(get<0>(*it), get<1>(*it)));
          it++;
        }

        list<pair<double, double>> tempForwardDiff = calcForwardDifferences(tempCurve);

        for (auto it2 = tempForwardDiff.begin(); it2 != tempForwardDiff.end(); ++it2) {
          _coordinates.push_back(make_pair(get<0>(*it2), get<1>(*it2)));
        }
    }

    return _coordinates;
}

list<pair<double, double>> BSpline::calcForwardDifferences(list<pair<double, double>> _coord) {
  list<pair<double, double>> coord;

  double coordMatrix[4][2];
  double B[4][4];
  double _B[4][2];

  // Coordinates list to matrix conversion
  int l = 0;
  for (auto it = _coord.begin(); it != _coord.end(); ++it) {
    coordMatrix[l][0] = get<0>(*it);
    coordMatrix[l][1] = get<1>(*it);
    l++;
  }

  // Result matrix initialization
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      _B[i][j] = 0.0;
    }
  }

  // Base matrix initialization
  B[0][0] = -1.0/6.0; B[0][1] = 3.0/6.0; B[0][2] = -3.0/6.0; B[0][3] = 1.0/6.0;
  B[1][0] = 3.0/6.0; B[1][1] = -6.0/6.0; B[1][2] = 3.0/6.0; B[1][3] = 0.0/6.0;
  B[2][0] = -3.0/6.0; B[2][1] = 0.0/6.0; B[2][2] = 3.0/6.0; B[2][3] = 0.0/6.0;
  B[3][0] = 1.0/6.0; B[3][1] = 4.0/6.0; B[3][2] = 1.0/6.0; B[3][3] = 0.0/6.0;

  // Matrix multiplication
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 4; k++) {
        _B[i][j] += B[i][k] * coordMatrix[k][j];
      }
    }
  }

  double a[2], b[2], c[2], d[2];
  a[0] = _B[0][0]; a[1] = _B[0][1];
  b[0] = _B[1][0]; b[1] = _B[1][1];
  c[0] = _B[2][0]; c[1] = _B[2][1];
  d[0] = _B[3][0]; d[1] = _B[3][1];

  double f0[2], f1[2], f2[2], f3[2];

  for (int i = 0; i < 2; i++) {
    f0[i] = d[i];
    f1[i] = a[i]*0.001 + b[i]*0.01 + c[i]*0.1;
    f2[i] = a[i]*0.006 + b[i]*0.02;
    f3[i] = a[i]*0.006;
  }

  for (int i = 0; i < 10; i++) {
    coord.push_back(make_pair(f0[0], f0[1]));

    for (int j = 0; j < 2; j++) {
      f0[j] += f1[j];
      f1[j] += f2[j];
      f2[j] += f3[j];
    }
  }

  return coord;
}
