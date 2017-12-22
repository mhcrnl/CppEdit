#include <gtkmm/application.h>

#include "window.hh"

int main(int argc, char **argv) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"org.cppedit");
	
	AppWindow win(app);
	win.show_all();
	
	return app->run(win);
}
