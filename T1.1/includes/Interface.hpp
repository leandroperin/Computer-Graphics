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
	void on_moveLeft_click();
	void on_moveUp_click();
	void on_moveDown_click();
	void on_moveRight_click();

};

#endif