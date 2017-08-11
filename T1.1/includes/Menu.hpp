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
	Viewport* viewport;

};

#endif