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
}

void Menu::on_menu_quit_click() {
	exit(0);
}

void Menu::on_menu_insertObject_click() {
	insertWindow.set_title("Inserir Objeto");
	insertWindow.set_default_size(450, 300);
	insertWindow.set_resizable(false);
	insertWindow.set_modal(true);

	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	insertWindow.add(*vbox);

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

	Gtk::Label *label_point_name = Gtk::manage(new Gtk::Label("Nome do Ponto:"));
	box_point->add(*label_point_name);

	entry_point_name = Gtk::manage(new Gtk::Entry());
	box_point->add(*entry_point_name);

	Gtk::Label *label_point = Gtk::manage(new Gtk::Label("Coordenada:"));
	box_point->add(*label_point);

	entry_point_x = Gtk::manage(new Gtk::Entry());
	box_point->add(*entry_point_x);

	entry_point_y = Gtk::manage(new Gtk::Entry());
	box_point->add(*entry_point_y);

	Gtk::Button *button_add_point = Gtk::manage(new Gtk::Button("Inserir Ponto"));
	button_add_point->signal_clicked().connect(sigc::mem_fun(*this, &Menu::on_add_point_click));
	box_point->add(*button_add_point);

	Gtk::Frame *frame_line = Gtk::manage(new Gtk::Frame("Reta"));
	frame_line->set_vexpand(true);
	grid->attach(*frame_line, 50, 0, 40, 2);

	Gtk::Box *box_line = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	box_line->set_spacing(5);
	box_line->set_border_width(10);
	frame_line->add(*box_line);

	Gtk::Label *label_line_1 = Gtk::manage(new Gtk::Label("Coordenada 1:"));
	box_line->add(*label_line_1);

	Gtk::Entry *entry_line_x_1 = Gtk::manage(new Gtk::Entry());
	box_line->add(*entry_line_x_1);

	Gtk::Entry *entry_line_y_1 = Gtk::manage(new Gtk::Entry());
	box_line->add(*entry_line_y_1);

	Gtk::Label *label_line_2 = Gtk::manage(new Gtk::Label("Coordenada 2:"));
	box_line->add(*label_line_2);

	Gtk::Entry *entry_line_x_2 = Gtk::manage(new Gtk::Entry());
	box_line->add(*entry_line_x_2);

	Gtk::Entry *entry_line_y_2 = Gtk::manage(new Gtk::Entry());
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

	vbox->show_all();
	insertWindow.show();
}

void Menu::on_add_point_click() {
	pair<int,int> coord (atoi(entry_point_x->get_text().c_str()), atoi(entry_point_y->get_text().c_str()));
	list<pair<int, int>> dot;
	dot.push_back(coord);
	string pName = entry_point_name->get_text().c_str();
	entry_point_name->set_text("");
	viewport->getWindow()->getDisplayFile()->addObject(new DObject(pName, dot));
	viewport->queue_draw();
}

void Menu::on_add_line_click() {

}

void Menu::on_add_polygon_click() {

}