#include "../includes/Menu.hpp"

Menu::Menu(Gtk::Box *vbox, Viewport* _viewport) {
	viewport = _viewport;

	Gtk::MenuBar *menuBar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menuBar, Gtk::PACK_SHRINK, 0);

	Gtk::MenuItem *menuItem_options = Gtk::manage(new Gtk::MenuItem("_Opções", true));
	menuBar->append(*menuItem_options);

	Gtk::Menu *optionsMenu = Gtk::manage(new Gtk::Menu());
	menuItem_options->set_submenu(*optionsMenu);

	Gtk::MenuItem *menuItem_insertObject = Gtk::manage(new Gtk::MenuItem("_Incluir Objeto", true));
	menuItem_insertObject->signal_activate().connect(sigc::mem_fun(*this, &Menu::on_menu_insertObject_click));
	optionsMenu->append(*menuItem_insertObject);

	Gtk::SeparatorMenuItem *menuSeparator = Gtk::manage(new Gtk::SeparatorMenuItem());
	optionsMenu->append(*menuSeparator);

	Gtk::MenuItem *menuItem_quit = Gtk::manage(new Gtk::MenuItem("_Fechar Aplicação", true));
	menuItem_quit->signal_activate().connect(sigc::mem_fun(*this, &Menu::on_menu_quit_click));
	optionsMenu->append(*menuItem_quit);

	buildWindow();
}

void Menu::on_menu_quit_click() {
	exit(0);
}

void Menu::buildWindow() {
	insertWindow.set_title("Inserir Objeto");
	insertWindow.set_default_size(450, 300);
	insertWindow.set_resizable(false);
	insertWindow.set_modal(true);

	vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	insertWindow.add(*vbox);

	Gtk::Label *label_object_name = Gtk::manage(new Gtk::Label("Nome do Objeto:"));
	vbox->add(*label_object_name);

	entry_object_name = Gtk::manage(new Gtk::Entry());
	vbox->add(*entry_object_name);

	Gtk::Grid *grid = Gtk::manage(new Gtk::Grid());
	grid->set_column_spacing(5);
	grid->set_border_width(5);
	vbox->add(*grid);

	Gtk::Frame *frame_point = Gtk::manage(new Gtk::Frame("Ponto"));
	frame_point->set_vexpand(true);
	grid->attach(*frame_point, 0, 0, 40, 2);

	Gtk::Box *box_point = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	box_point->set_spacing(5);
	box_point->set_border_width(10);
	frame_point->add(*box_point);

	Gtk::Label *label_point = Gtk::manage(new Gtk::Label("Coordenada:"));
	box_point->add(*label_point);

	entry_point_x = Gtk::manage(new Gtk::Entry());
	box_point->add(*entry_point_x);

	entry_point_y = Gtk::manage(new Gtk::Entry());
	box_point->add(*entry_point_y);

	Gtk::Button *button_add_point = Gtk::manage(new Gtk::Button("Inserir Ponto"));
	button_add_point->signal_clicked().connect(sigc::mem_fun(*this, &Menu::on_add_point_click));
	box_point->add(*button_add_point);

	Gtk::Button *button_add_to_polygon = Gtk::manage(new Gtk::Button("Adicionar ao Polígono"));
	button_add_to_polygon->signal_clicked().connect(sigc::mem_fun(*this, &Menu::on_add_to_polygon_click));
	box_point->add(*button_add_to_polygon);

	button_fill_polygon = Gtk::manage(new Gtk::CheckButton("Preencher Polígono"));
	box_point->add(*button_fill_polygon);

	Gtk::Frame *frame_line = Gtk::manage(new Gtk::Frame("Reta"));
	frame_line->set_vexpand(true);
	grid->attach(*frame_line, 50, 0, 40, 2);

	Gtk::Box *box_line = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	box_line->set_spacing(5);
	box_line->set_border_width(10);
	frame_line->add(*box_line);

	Gtk::Label *label_line_1 = Gtk::manage(new Gtk::Label("Coordenada 1:"));
	box_line->add(*label_line_1);

	entry_line_x_1 = Gtk::manage(new Gtk::Entry());
	box_line->add(*entry_line_x_1);

	entry_line_y_1 = Gtk::manage(new Gtk::Entry());
	box_line->add(*entry_line_y_1);

	Gtk::Label *label_line_2 = Gtk::manage(new Gtk::Label("Coordenada 2:"));
	box_line->add(*label_line_2);

	entry_line_x_2 = Gtk::manage(new Gtk::Entry());
	box_line->add(*entry_line_x_2);

	entry_line_y_2 = Gtk::manage(new Gtk::Entry());
	box_line->add(*entry_line_y_2);

	Gtk::Button *button_add_line = Gtk::manage(new Gtk::Button("Inserir Reta"));
	button_add_line->signal_clicked().connect(sigc::mem_fun(*this, &Menu::on_add_line_click));
	box_line->add(*button_add_line);

	Gtk::Frame *frame_polygon = Gtk::manage(new Gtk::Frame("Polígono"));
	frame_polygon->set_vexpand(true);
	grid->attach(*frame_polygon, 100, 0, 40, 2);

	Gtk::Box *box_polygon = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	box_polygon->set_spacing(5);
	box_polygon->set_border_width(10);
	frame_polygon->add(*box_polygon);

	Gtk::ScrolledWindow *scrolledWindow_points = Gtk::manage(new Gtk::ScrolledWindow());
	scrolledWindow_points->set_size_request(10, 195);
	box_polygon->add(*scrolledWindow_points);

	textView_points = Gtk::manage(new Gtk::TextView());	
	textView_points->set_editable(false);
	textView_points->set_cursor_visible(false);
	scrolledWindow_points->add(*textView_points);

	Gtk::Button *button_add_polygon = Gtk::manage(new Gtk::Button("Inserir Polígono"));
	button_add_polygon->signal_clicked().connect(sigc::mem_fun(*this, &Menu::on_add_polygon_click));
	box_polygon->add(*button_add_polygon);

	vbox->show_all();
}

void Menu::on_menu_insertObject_click() {
	insertWindow.show();
}

void Menu::on_add_point_click() {
	pair<double,double> coord (atof(entry_point_x->get_text().c_str()), atof(entry_point_y->get_text().c_str()));
	list<pair<double, double>> dot;
	dot.push_back(coord);
	string pName = entry_object_name->get_text().c_str();
	viewport->getWindow()->getDisplayFile()->addObject(new DObject(pName, dot, false));
	viewport->queue_draw();
}

void Menu::on_add_line_click() {
	pair<double,double> coord1 (atof(entry_line_x_1->get_text().c_str()), atof(entry_line_y_1->get_text().c_str()));
	pair<double,double> coord2 (atof(entry_line_x_2->get_text().c_str()), atof(entry_line_y_2->get_text().c_str()));
	list<pair<double, double>> dot;
	dot.push_back(coord1);
	dot.push_back(coord2);
	string pName = entry_object_name->get_text().c_str();
	viewport->getWindow()->getDisplayFile()->addObject(new DObject(pName, dot, false));
	viewport->queue_draw();
}

bool Menu::getToFill() {
	return button_fill_polygon->get_active();
}

void Menu::on_add_polygon_click() {
	string pName = entry_object_name->get_text().c_str();
	viewport->getWindow()->getDisplayFile()->addObject(new DObject(pName, polygonPoints, getToFill()));
	viewport->queue_draw();

	polygonPoints.clear();
	textView_points->get_buffer()->set_text("");
}

void Menu::on_add_to_polygon_click() {
	pair<double,double> coord (atof(entry_point_x->get_text().c_str()), atof(entry_point_y->get_text().c_str()));
	polygonPoints.push_back(coord);

	textView_points->get_buffer()->set_text(textView_points->get_buffer()->get_text() + 
							entry_object_name->get_text().c_str() + ": " + 
							entry_point_x->get_text().c_str() + "," + 
							entry_point_y->get_text().c_str() + "\n");
}