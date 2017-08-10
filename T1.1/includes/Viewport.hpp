#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP

#include <gtkmm.h>
#include <cairomm/context.h>
#include <list>
#include "Window.hpp"

class Viewport : public Gtk::DrawingArea {
public:
	Viewport(DisplayFile *_displayFile);
	virtual ~Viewport();
	double getXvmin();
	double getYvmin();
	double getXvmax();
	double getYvmax();
	Window* getWindow();

private:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	Window *window;
	double Xvmin; 
	double Yvmin; 
	double Xvmax; 
	double Yvmax;
	pair<int, int> transform(pair<int, int> _coord);

};

#endif