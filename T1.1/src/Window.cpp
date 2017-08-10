#include "../includes/Window.hpp"

Window::Window(int _Xwmin, int _Ywmin, int _Xwmax, int _Ywmax, DisplayFile *_displayFile) {
	Xwmin = _Xwmin;
	Xwmax = _Xwmax;
	Ywmin = _Ywmin;
	Ywmax = _Ywmax;
	displayFile = _displayFile;
}

Window::~Window() {}

void Window::zoomIn(double _zoomScale) {
	double width = Xwmax - Xwmin;
	double height = Ywmax - Ywmin;

	Xwmin += (width - (width / _zoomScale)) / 2;
	Xwmax -= (width - (width / _zoomScale)) / 2;
	Ywmin += (height - (height / _zoomScale)) / 2;
	Ywmax -= (height - (height / _zoomScale)) / 2;
}

void Window::zoomOut(double _zoomScale) {
	double width = Xwmax - Xwmin;
	double height = Ywmax - Ywmin;

	Xwmin -= ((width * _zoomScale) - width) / 2;
	Xwmax += ((width * _zoomScale) - width) / 2;
	Ywmin -= ((height * _zoomScale) - height) / 2;
	Ywmax += ((height * _zoomScale) - height) / 2;
}

void Window::moveRight(double _distance) {
	//TODO
}

void Window::moveUp(double _distance) {
	//TODO
}

void Window::moveDown(double _distance) {
	//TODO
}

void Window::moveLeft(double _distance) {
	//TODO
}

DisplayFile* Window::getDisplayFile() {
	return displayFile;
}