#include "header.hh"
#include "filemenu.hh"

HeaderBar::HeaderBar(Glib::RefPtr<Gtk::Application> app) {
	this->set_title("CppEdit");
	this->set_show_close_button();
	
	FileMenu *fileMenu = new FileMenu(app);
	this->pack_start(*fileMenu);
}
