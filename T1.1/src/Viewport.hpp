#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP



#include <gtkmm/drawingarea.h>
#include <gdkmm/rgba.h>
#include <cairomm/context.h>
#include <list>
#include "Window.hpp"


class Viewport : public Gtk::DrawingArea{
public:
	Viewport(double Xvmin, double Yvmin, double Xvmax, double Yvmax);
	virtual ~Viewport();
	double getXvmin();
	double getYvmin();
	double getXvmax();
	double getYvmax();

private:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	Window* Window;
	double Xvmin; 
	double Yvmin; 
	double Xvmax; 
	double Yvmax;

}

