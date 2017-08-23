#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <gtkmm.h>
#include "Viewport.hpp"

class Interface {
public:
	Interface(Gtk::Box *vbox, Viewport *_viewport);

private:
	Viewport *viewport;
	void on_zoomIn_click();
	void on_zoomOut_click();
	void on_translade_click();
	void on_resize_click();

};

#endif