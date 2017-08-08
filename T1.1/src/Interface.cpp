#include "Interface.hpp"

Interface::Interface(Gtk::Box *vbox) {
	Gtk::Grid *grid = Gtk::manage(new Gtk::Grid());
	grid->set_column_spacing(10);
	grid->set_border_width(10);
	vbox->add(*grid);

	Gtk::Frame *frame_functions = Gtk::manage(new Gtk::Frame("Menu de Funções"));
	frame_functions->set_vexpand(true);
	grid->attach(*frame_functions, 0, 0, 40, 2);

	Gtk::Box *box_functions = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	box_functions->set_spacing(10);
	box_functions->set_border_width(10);
	frame_functions->add(*box_functions);

	Gtk::Label *label_objects = Gtk::manage(new Gtk::Label("Objetos"));
	box_functions->add(*label_objects);

	Gtk::ScrolledWindow *scrolledWindow_objects = Gtk::manage(new Gtk::ScrolledWindow());
	scrolledWindow_objects->set_size_request(10, 100);
	box_functions->add(*scrolledWindow_objects);

	Gtk::TextView *textView_objects = Gtk::manage(new Gtk::TextView());	
	textView_objects->set_editable(false);
	textView_objects->set_cursor_visible(false);
	scrolledWindow_objects->add(*textView_objects);

	Gtk::Frame *frame_window = Gtk::manage(new Gtk::Frame("Window"));
	frame_window->set_vexpand(true);
	box_functions->add(*frame_window);

	Gtk::Box *box_window = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	box_window->set_spacing(10);
	box_window->set_border_width(10);
	frame_window->add(*box_window);

	Gtk::Fixed *fixed_passo = Gtk::manage(new Gtk::Fixed());
	box_window->add(*fixed_passo);

	Gtk::Label *label_passo_1 = Gtk::manage(new Gtk::Label("Passo:"));
	fixed_passo->put(*label_passo_1, 0, 0);

	Gtk::ScrolledWindow *scrolledWindow_passo = Gtk::manage(new Gtk::ScrolledWindow());
	scrolledWindow_passo->set_size_request(100, 1);
	fixed_passo->put(*scrolledWindow_passo, 50, 0);

	Gtk::Entry *entry_passo = Gtk::manage(new Gtk::Entry());
	scrolledWindow_passo->add(*entry_passo);

	Gtk::Label *label_passo_2 = Gtk::manage(new Gtk::Label("%"));
	fixed_passo->put(*label_passo_2, 160, 0);

	Gtk::Frame *frame_viewport = Gtk::manage(new Gtk::Frame("Viewport"));
	frame_viewport->set_vexpand(true);
	grid->attach(*frame_viewport, 40, 0, 50, 2);
}