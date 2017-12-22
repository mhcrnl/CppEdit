#include <gtkmm/menu.h>

#include "filemenu.hh"
#include "tabpane.hh"
#include "editor.hh"

FileMenu::FileMenu(Glib::RefPtr<Gtk::Application> appP) {
	app = appP;
	this->set_label("File");
	
	menu = new Gtk::Menu;
	this->set_submenu(*menu);
	
	newFile = new MenuItem("New");
	open = new MenuItem("Open");
	quit = new MenuItem("Quit");
	
	newFile->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onNewFileClicked));
	open->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onOpenClicked));
	quit->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onQuitClicked));
	
	menu->append(*newFile);
	menu->append(*open);
	menu->append(*quit);
}

FileMenu::~FileMenu() {
	delete menu;
	delete newFile;
	delete open;
	delete quit;
}

void FileMenu::onNewFileClicked() {
	TabPane::addNewTab();
}

void FileMenu::onOpenClicked() {
	
}

void FileMenu::onQuitClicked() {
	app->quit();
}
