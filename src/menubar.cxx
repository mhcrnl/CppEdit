#include "menubar.hh"
#include "filemenu.hh"

Menubar::Menubar(Glib::RefPtr<Gtk::Application> app) {
	FileMenu *fileMenu = new FileMenu(app);
	
	this->append(*fileMenu);
}
