#include "main_menu_button.hh"
#include "filemenu.hh"
#include "window.hh"

MainMenuButton::MainMenuButton(Glib::RefPtr<Gtk::Application> appP) {
	app = appP;
	this->set_label("Menu");
	
	menu = new Gtk::Menu;
	this->set_popup(*menu);
	
	FileMenu *filemenu = new FileMenu;
	menu->append(*filemenu);
	
	quit = new Gtk::ImageMenuItem("Quit");
	
	quit->set_always_show_image();
	
	quitIcon = new Gtk::Image;
	quitIcon->set_from_icon_name("application-exit",Gtk::ICON_SIZE_MENU);
	quit->set_image(*quitIcon);
	
	quit->signal_activate().connect(sigc::mem_fun(*this,&MainMenuButton::onQuitClicked));
	
	menu->append(*quit);
	
	menu->show_all();
}

MainMenuButton::~MainMenuButton() {
	delete menu;
	delete quit;
	delete quitIcon;
}

void MainMenuButton::onQuitClicked() {
	if (AppWindow::checkSave()==false) {
		app->quit();
	}
}
