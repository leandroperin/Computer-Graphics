#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

#include <gtkmm.h>
#include <cairomm/context.h>
#include <list>
#include "Clipping.hpp"
#include "Curva2.hpp"
#include "BSpline.hpp"

class Viewport : public Gtk::DrawingArea {
public:
	Viewport(DisplayFile *_displayFile);
	virtual ~Viewport();
	double getXvmin();
	double getYvmin();
	double getXvmax();
	double getYvmax();
	Window* getWindow();
	void setObjectsList(Gtk::TextView* _objectsList);
	void setLiangBarskyRadio(Gtk::RadioButton* radio);
	void setCohenSutherlandRadio(Gtk::RadioButton* radio);

private:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	Window *window;
	double Xvmin;
	double Yvmin;
	double Xvmax;
	double Yvmax;
	pair<double, double> transform(pair<double, double> _coord);
	int getLineClippingType();
	Gtk::TextView* objectsList;
	Gtk::RadioButton* LiangBarskyRadio;
	Gtk::RadioButton* CohenSutherlandRadio;

};

#endif
