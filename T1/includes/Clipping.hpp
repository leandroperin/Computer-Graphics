#ifndef CLIPPING_HPP
#define CLIPPING_HPP

#include "Window.hpp"

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
#define LINE_CLIP_TYPE "LB"

class Clipping {
public:
	Clipping();
	~Clipping();
	void clip(Window* window, DObject* obj);
	void clipPoint(Window* window, DObject* obj);
	void clipLiangBarsky(Window* window, DObject* obj);
	void clipCohenSutherland(Window* window, DObject* obj);
	void clipSutherlandHodgman(Window* window, DObject* obj);
private:
	int getRegionCode(Window* window, pair<double, double> coord);
	pair<double, double> getInter(pair<double, double> p1, pair<double, double> p2, Window* window, int rCode);
};

#endif