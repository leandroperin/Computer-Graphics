#include "../includes/Viewport.hpp"

Viewport::Viewport(DisplayFile *_displayFile) {
	window = new Window(0, 0, 200, 200, _displayFile);

	Xvmin = 0;
	Yvmin = 0;
	Xvmax = 200;
	Yvmax = 200;
}

Viewport::~Viewport() {}

double Viewport::getXvmin() {
	return Xvmin;
}

double Viewport::getYvmin() {
	return Yvmin;
}

double Viewport::getXvmax() {
	return Xvmax;
}

double Viewport::getYvmax() {
	return Yvmax;
}

Window* Viewport::getWindow() {
	return window;
}

bool Viewport::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();

	// coordinates for the center of the window
	int xc, yc;
	xc = width / 2;
	yc = height / 2;

	cr->set_line_width(2.0);

	list<DObject*> objects = window->getDisplayFile()->getAllObjects();

	cr->set_source_rgb(0.8, 0.0, 0.0);
	for (auto it = objects.begin(); it != objects.end(); ++it) {
		list<pair<int, int>> coord = (*it)->getCoordinates();	
		list<pair<int, int>> coordView;

		for (auto it2 = coord.begin(); it2 != coord.end(); ++it2) {
			coordView.push_back(transform(*it2));
		}

		(*it)->setCoordinatesView(coordView);

		if ((*it)->getType() == "Line") {
			cr->move_to(get<0>(coordView.front()), get<1>(coordView.front()));
			cr->line_to(get<0>(coordView.back()), get<1>(coordView.back()));
			cr->stroke();
		}
	}

	return true;
}

pair<int, int> Viewport::transform(pair<int, int> _coord) {
	double Xw = get<0>(_coord);
	double Yw = get<1>(_coord);

	double Xv = ((Xw - window->getXwmin()) / (window->getXwmax() - window->getXwmin())) * (Xvmax - Xvmin);

	double Yv = (1.0 - (Yw - window->getYwmin()) / (window->getYwmax() - window->getYwmin())) * (Yvmax - Yvmin);

	return pair<int, int>(Xv, Yv);
}