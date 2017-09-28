#ifndef MENU_HPP
#define MENU_HPP

#include <gtkmm.h>
#include "Viewport.hpp"
#include "Curva2.hpp"

class Menu {
public:
	Menu(Gtk::Box *vbox, Viewport* _viewport);

private:
	void on_menu_quit_click();
	void on_menu_insertObject_click();
	void on_add_point_click();
	void on_add_line_click();
	void on_add_polygon_click();
	void on_add_curve_click();
	void on_add_spline_click();
	void on_add_to_polygon_click();
	void buildWindow();
	bool getToFill();
	Viewport* viewport;
	Gtk::Window insertWindow;
	Gtk::Box* vbox;
	Gtk::Entry* entry_object_name;
	Gtk::Entry* entry_point_x;
	Gtk::Entry* entry_point_y;
	Gtk::Entry* entry_line_x_1;
	Gtk::Entry* entry_line_y_1;
	Gtk::Entry* entry_line_x_2;
	Gtk::Entry* entry_line_y_2;
	Gtk::TextView* textView_points;
	Gtk::CheckButton* button_fill_polygon;
	list<pair<double, double>> polygonPoints;

};

#endif
