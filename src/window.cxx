#include <gtkmm/hvbox.h>
#include <gtkmm/button.h>

#include "window.hh"
#include "menubar.hh"
#include "tabpane.hh"

AppWindow::AppWindow(Glib::RefPtr<Gtk::Application> appP) {
	app = appP;

	this->set_title("CppEdit");
	this->set_default_size(500,400);
	this->set_icon_name("accessories-text-editor");
	
	Gtk::VBox *mainLayout = new Gtk::VBox(false,false);
	this->add(*mainLayout);
	
	TabPane *tabpane = new TabPane;
	Menubar *menubar = new Menubar(appP);
	
	mainLayout->pack_start(*menubar,false,false,0);
	mainLayout->pack_start(*tabpane,true,true,0);
}
