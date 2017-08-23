#include "../includes/Interface.hpp"

Interface::Interface(Gtk::Box *vbox, Viewport *_viewport) {
	viewport = _viewport;

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
	viewport->setObjectsList(textView_objects);
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

	Gtk::Frame *frame_manipulation = Gtk::manage(new Gtk::Frame("Manipular Objetos"));
	box_window->add(*frame_manipulation);

	Gtk::Box *box_manipulation = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	box_manipulation->set_spacing(5);
	box_manipulation->set_border_width(10);
	frame_manipulation->add(*box_manipulation);

	Gtk::Box *box_manipulation_1 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	box_manipulation_1->set_border_width(10);
	box_manipulation->add(*box_manipulation_1);

	Gtk::Box *box_manipulation_name = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	box_manipulation_name->set_spacing(5);
	box_manipulation_name->set_border_width(10);
	box_manipulation_1->add(*box_manipulation_name);

	Gtk::Label *label_object_name = Gtk::manage(new Gtk::Label("Nome do Objeto: "));
	box_manipulation_name->add(*label_object_name);

	entry_object_name = Gtk::manage(new Gtk::Entry());
	entry_object_name->set_hexpand(true);
	box_manipulation_name->add(*entry_object_name);

	Gtk::Box *box_manipulation_2 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	box_manipulation_2->set_spacing(5);
	box_manipulation_2->set_border_width(10);
	box_manipulation_1->add(*box_manipulation_2);

	Gtk::Label *label_X = Gtk::manage(new Gtk::Label("X:"));
	box_manipulation_2->add(*label_X);

	entry_X = Gtk::manage(new Gtk::Entry());
	box_manipulation_2->add(*entry_X);

	Gtk::Label *label_Y = Gtk::manage(new Gtk::Label("Y:"));
	box_manipulation_2->add(*label_Y);

	entry_Y = Gtk::manage(new Gtk::Entry());
	box_manipulation_2->add(*entry_Y);

	Gtk::Button *button_translade = Gtk::manage(new Gtk::Button("Translação"));
	Gtk::Button *button_resize = Gtk::manage(new Gtk::Button("Escalonamento"));

	button_translade->signal_clicked().connect(sigc::mem_fun(*this, &Interface::on_translade_click));
	button_resize->signal_clicked().connect(sigc::mem_fun(*this, &Interface::on_resize_click));

	box_manipulation_2->add(*button_translade);
	box_manipulation_2->add(*button_resize);

	Gtk::Box *box_manipulation_3 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	box_manipulation_3->set_spacing(5);
	box_manipulation_3->set_border_width(10);
	box_manipulation_1->add(*box_manipulation_3);

	Gtk::Label *label_rotation_1 = Gtk::manage(new Gtk::Label("Graus:"));
	box_manipulation_3->add(*label_rotation_1);

	entry_rotation = Gtk::manage(new Gtk::Entry());
	box_manipulation_3->add(*entry_rotation);

	Gtk::Label *label_rotation_2 = Gtk::manage(new Gtk::Label("º"));
	box_manipulation_3->add(*label_rotation_2);

	Gtk::Button *button_world_center = Gtk::manage(new Gtk::Button("Centro do Mundo"));
	Gtk::Button *button_object_center = Gtk::manage(new Gtk::Button("Centro do Objeto"));
	Gtk::Button *button_fixed_point = Gtk::manage(new Gtk::Button("Ponto Fixo"));

	button_world_center->signal_clicked().connect(sigc::mem_fun(*this, &Interface::on_world_rotation_click));
	button_object_center->signal_clicked().connect(sigc::mem_fun(*this, &Interface::on_object_rotation_click));
	button_fixed_point->signal_clicked().connect(sigc::mem_fun(*this, &Interface::on_fixed_rotation_click));

	box_manipulation_3->add(*button_world_center);
	box_manipulation_3->add(*button_object_center);
	box_manipulation_3->add(*button_fixed_point);

	Gtk::Box *box_zoom = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	box_zoom->set_spacing(5);
	box_zoom->set_border_width(10);
	box_window->add(*box_zoom);

	Gtk::Button *button_zoomIn = Gtk::manage(new Gtk::Button("Zoom +"));
	Gtk::Button *button_zoomOut = Gtk::manage(new Gtk::Button("Zoom -"));
	Gtk::Button *button_setWindow = Gtk::manage(new Gtk::Button("Set Window"));

	button_zoomIn->signal_clicked().connect(sigc::mem_fun(*this, &Interface::on_zoomIn_click));
	button_zoomOut->signal_clicked().connect(sigc::mem_fun(*this, &Interface::on_zoomOut_click));

	box_zoom->add(*button_zoomIn);
	box_zoom->add(*button_zoomOut);
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

	frame_viewport->add(*viewport);
	viewport->show();
}

void Interface::on_zoomIn_click() {
	viewport->getWindow()->zoomIn(1.5);
	viewport->queue_draw();
}

void Interface::on_zoomOut_click() {
	viewport->getWindow()->zoomOut(1.5);
	viewport->queue_draw();
}

void Interface::on_translade_click() {
	string objName = entry_object_name->get_text().c_str();
	double Dx = atof(entry_X->get_text().c_str());
	double Dy = atof(entry_Y->get_text().c_str());

	DObject* obj = viewport->getWindow()->getDisplayFile()->getObjectByName(objName);

	obj->translade(Dx, Dy);

	viewport->queue_draw();
}

void Interface::on_resize_click() {
	string objName = entry_object_name->get_text().c_str();
	double Sx = atof(entry_X->get_text().c_str());
	double Sy = atof(entry_Y->get_text().c_str());

	DObject* obj = viewport->getWindow()->getDisplayFile()->getObjectByName(objName);

	obj->resize(Sx, Sy);

	viewport->queue_draw();
}

void Interface::on_world_rotation_click() {
	string objName = entry_object_name->get_text().c_str();
	double o = atof(entry_rotation->get_text().c_str());

	DObject* obj = viewport->getWindow()->getDisplayFile()->getObjectByName(objName);

	obj->rotate(o);

	viewport->queue_draw();
}

void Interface::on_object_rotation_click() {
	string objName = entry_object_name->get_text().c_str();
	double o = atof(entry_rotation->get_text().c_str());

	DObject* obj = viewport->getWindow()->getDisplayFile()->getObjectByName(objName);

	pair<double, double> C = obj->getObjectCenter();
	double Cx = get<0>(C);
	double Cy = get<1>(C);

	obj->translade(-Cx, -Cy);
	obj->rotate(o);
	obj->translade(Cx, Cy);

	viewport->queue_draw();
}

void Interface::on_fixed_rotation_click() {
	string objName = entry_object_name->get_text().c_str();
	double o = atof(entry_rotation->get_text().c_str());
	double x = atof(entry_X->get_text().c_str());
	double y = atof(entry_Y->get_text().c_str());

	DObject* obj = viewport->getWindow()->getDisplayFile()->getObjectByName(objName);

	obj->translade(-x, -y);
	obj->rotate(o);
	obj->translade(x, y);

	viewport->queue_draw();
}