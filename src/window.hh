#pragma once

#include <gtkmm/window.h>
#include <gtkmm/application.h>

class AppWindow : public Gtk::Window {
public:
	AppWindow(Glib::RefPtr<Gtk::Application> appP);
private:
	Glib::RefPtr<Gtk::Application> app;
};
