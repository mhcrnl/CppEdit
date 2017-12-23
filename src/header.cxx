#include "header.hh"
#include "main_menu_button.hh"

HeaderBar::HeaderBar(Glib::RefPtr<Gtk::Application> app) {
	this->set_title("CppEdit");
	this->set_show_close_button();
	
	MainMenuButton *menu = new MainMenuButton(app);
	this->pack_start(*menu);
}
