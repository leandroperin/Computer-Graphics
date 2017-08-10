#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "DisplayFile.hpp"

class Window {
public:
	Window(int _Xwmin, int _Ywmin, int _Xwmax, int _Ywmax, DisplayFile *_displayFile);
	virtual ~Window();
	void zoomIn(double _zoomScale);
	void zoomOut(double _zoomScale);
	void moveRight(double _distance);
	void moveUp(double _distance);
	void moveDown(double _distance);
	void moveLeft(double _distance);

private:
	int Xwmin;
	int Ywmin;
	int Xwmax;
	int Ywmax;
	DisplayFile *displayFile;
};

#endif