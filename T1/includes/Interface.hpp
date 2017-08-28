#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <gtkmm.h>
#include "Viewport.hpp"

class Interface {
public:
	Interface(Gtk::Box *vbox, Viewport *_viewport);

private:
	Viewport *viewport;
	Gtk::Entry *entry_object_name;
	Gtk::Entry *entry_X;
	Gtk::Entry *entry_Y;
	Gtk::Entry *entry_rotation;
	void on_zoomIn_click();
	void on_zoomOut_click();
	void on_translade_click();
	void on_resize_click();
	void on_world_rotation_click();
	void on_object_rotation_click();
	void on_fixed_rotation_click();
};

#endif