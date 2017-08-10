#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <gtkmm.h>
#include "DisplayFile.hpp"

class Interface {
public:
	Interface(Gtk::Box *vbox, DisplayFile *_displayFile);

private:
	DisplayFile *displayFile;

};

#endif