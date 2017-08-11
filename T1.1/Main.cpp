#include "includes/Menu.hpp"
#include "includes/Interface.hpp"
#include "includes/Viewport.hpp"

int main(int argc, char* argv[]) {
	Gtk::Main kit(argc, argv);
	Gtk::Window window;

	window.set_default_size(900, 600);
	window.set_title("Computação Gráfica");

	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	window.add(*vbox);

	DisplayFile *displayFile = new DisplayFile();
	Viewport *viewport = new Viewport(displayFile);

	Menu* menu = new Menu(vbox, viewport);
	Interface* interface = new Interface(vbox, viewport);

	vbox->show_all();
	Gtk::Main::run(window);
	return 0;
}