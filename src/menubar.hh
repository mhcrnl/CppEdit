#pragma once

#include <gtkmm/menubar.h>
#include <gtkmm/application.h>

class Menubar : public Gtk::MenuBar {
public:
	Menubar(Glib::RefPtr<Gtk::Application> app);
};
