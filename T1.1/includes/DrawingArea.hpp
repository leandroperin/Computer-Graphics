#ifndef DRAWINGAREA_HPP
#define DRAWINGAREA_HPP

#include <gtkmm/drawingarea.h>

class DrawingArea : public Gtk::DrawingArea {
public:
	DrawingArea();

private:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

};

#endif