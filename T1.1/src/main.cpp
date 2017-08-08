#include "Menu.hpp"
#include "Interface.hpp"

int main(int argc, char* argv[]) {
	Gtk::Main kit(argc, argv);
	Gtk::Window window;

	window.set_default_size(900, 600);
	window.set_title("Computação Gráfica");

	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	window.add(*vbox);

	Menu* menu = new Menu(vbox);
	Interface* interface = new Interface(vbox);

	vbox->show_all();
	Gtk::Main::run(window);
	return 0;
}