#pragma once

#include <gtkmm/window.h>
#include <gtkmm/application.h>

class AppWindow : public Gtk::Window {
public:
	AppWindow(Glib::RefPtr<Gtk::Application> appP);
	static bool checkSave();
private:
	Glib::RefPtr<Gtk::Application> app;
	bool onWindowClosed(GdkEventAny* event);
};
