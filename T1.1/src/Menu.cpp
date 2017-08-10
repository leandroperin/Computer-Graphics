#include "../includes/Menu.hpp"

Menu::Menu(Gtk::Box *vbox) {
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
	exit(0);
}