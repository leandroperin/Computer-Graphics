#ifndef MENU_HPP
#define MENU_HPP

#include <gtkmm.h>
#include "Viewport.hpp"

class Menu {
public:
	Menu(Gtk::Box *vbox, Viewport* _viewport);

private:
	void on_menu_quit_click();
	void on_menu_insertObject_click();
	void on_add_point_click();
	void on_add_line_click();
	void on_add_polygon_click();
	Viewport* viewport;
	Gtk::Window insertWindow;
	Gtk::Entry* entry_point_name;
	Gtk::Entry* entry_point_x;
	Gtk::Entry* entry_point_y;

};

#endif