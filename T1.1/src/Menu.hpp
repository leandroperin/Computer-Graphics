#ifndef MENU_HPP
#define MENU_HPP

#include <gtkmm.h>

class Menu {
public:
	Menu(Gtk::Box *vbox);

private:
	void on_menu_quit_click();
	void on_menu_insertObject_click();
};

#endif