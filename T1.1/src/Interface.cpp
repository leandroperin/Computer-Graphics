#include "Interface.hpp"
#include "DrawingArea.hpp"

Interface::Interface(Gtk::Box *vbox) {
	Gtk::Grid *grid = Gtk::manage(new Gtk::Grid());
	grid->set_column_spacing(10);
	grid->set_border_width(10);
	vbox->add(*grid);

	Gtk::Frame *frame_functions = Gtk::manage(new Gtk::Frame("Menu de Funções"));
	frame_functions->set_vexpand(true);
	grid->attach(*frame_functions, 0, 0, 40, 2);

	Gtk::Box *box_functions = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	box_functions->set_spacing(5);
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
	box_window->set_border_width(10);
	frame_window->add(*box_window);

	Gtk::Box *box_window_1 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	box_window_1->set_spacing(5);
	box_window_1->set_border_width(10);
	box_window->add(*box_window_1);

	Gtk::Label *label_passo_1 = Gtk::manage(new Gtk::Label("Passo:"));
	box_window_1->add(*label_passo_1);

	Gtk::Entry *entry_passo = Gtk::manage(new Gtk::Entry());
	box_window_1->add(*entry_passo);

	Gtk::Label *label_passo_2 = Gtk::manage(new Gtk::Label("%"));
	box_window_1->add(*label_passo_2);

	Gtk::Button *button_In = Gtk::manage(new Gtk::Button("In"));
	Gtk::Button *button_Out = Gtk::manage(new Gtk::Button("Out"));
	box_window_1->add(*button_In);
	box_window_1->add(*button_Out);

	Gtk::Box *box_window_2 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	box_window_2->set_spacing(5);
	box_window_2->set_border_width(10);
	box_window->add(*box_window_2);

	Gtk::Button *button_Left = Gtk::manage(new Gtk::Button("Left"));
	Gtk::Button *button_Up = Gtk::manage(new Gtk::Button("Up"));
	Gtk::Button *button_Down = Gtk::manage(new Gtk::Button("Down"));
	Gtk::Button *button_Right = Gtk::manage(new Gtk::Button("Right"));
	box_window_2->add(*button_Left);
	box_window_2->add(*button_Up);
	box_window_2->add(*button_Down);
	box_window_2->add(*button_Right);

	Gtk::Frame *frame_rotation = Gtk::manage(new Gtk::Frame("Rotação"));
	box_window->add(*frame_rotation);

	Gtk::Box *box_degrees = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	box_degrees->set_spacing(5);
	box_degrees->set_border_width(10);
	frame_rotation->add(*box_degrees);

	Gtk::Label *label_rotation_1 = Gtk::manage(new Gtk::Label("Graus:"));
	box_degrees->add(*label_rotation_1);

	Gtk::Entry *entry_rotation = Gtk::manage(new Gtk::Entry());
	box_degrees->add(*entry_rotation);

	Gtk::Label *label_rotation_2 = Gtk::manage(new Gtk::Label("º"));
	box_degrees->add(*label_rotation_2);

	Gtk::Button *button_X = Gtk::manage(new Gtk::Button("X"));
	Gtk::Button *button_Y = Gtk::manage(new Gtk::Button("Y"));
	Gtk::Button *button_Z = Gtk::manage(new Gtk::Button("Z"));
	box_degrees->add(*button_X);
	box_degrees->add(*button_Y);
	box_degrees->add(*button_Z);

	Gtk::Box *box_zoom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	box_zoom->set_spacing(5);
	box_zoom->set_border_width(10);
	box_window->add(*box_zoom);

	Gtk::Button *button_zoomUp = Gtk::manage(new Gtk::Button("Zoom +"));
	Gtk::Button *button_zoomDown = Gtk::manage(new Gtk::Button("Zoom -"));
	Gtk::Button *button_setWindow = Gtk::manage(new Gtk::Button("Set Window"));
	box_zoom->add(*button_zoomUp);
	box_zoom->add(*button_zoomDown);
	box_zoom->add(*button_setWindow);

	Gtk::Frame *frame_projection = Gtk::manage(new Gtk::Frame("Projeção"));
	box_window->add(*frame_projection);

	Gtk::Box *box_projection = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	box_projection->set_spacing(5);
	box_projection->set_border_width(10);
	frame_projection->add(*box_projection);

	Gtk::RadioButton *radio_parallel = Gtk::manage(new Gtk::RadioButton("Paralela"));
	Gtk::RadioButton *radio_perspective = Gtk::manage(new Gtk::RadioButton("Perspectiva"));
	radio_perspective->join_group(*radio_parallel);

	box_projection->add(*radio_parallel);
	box_projection->add(*radio_perspective);

	Gtk::Frame *frame_viewport = Gtk::manage(new Gtk::Frame("Viewport"));
	frame_viewport->set_vexpand(true);
	grid->attach(*frame_viewport, 40, 0, 50, 2);

	DrawingArea drawingArea;
	frame_viewport->add(drawingArea);
}