#include <gtkmm/menu.h>

#include "filemenu.hh"
#include "tabpane.hh"
#include "actions.hh"

FileMenu::FileMenu(Glib::RefPtr<Gtk::Application> appP) {
	app = appP;
	this->set_label("File");
	
	menu = new Gtk::Menu;
	this->set_submenu(*menu);
	
	newFile = new MenuItem("New");
	open = new MenuItem("Open");
	save = new MenuItem("Save");
	saveAs = new MenuItem("Save As");
	quit = new MenuItem("Quit");
	
	newFile->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onNewFileClicked));
	open->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onOpenClicked));
	save->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onSaveClicked));
	saveAs->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onSaveAsClicked));
	quit->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onQuitClicked));
	
	menu->append(*newFile);
	menu->append(*open);
	menu->append(*save);
	menu->append(*saveAs);
	menu->append(*quit);
}

FileMenu::~FileMenu() {
	delete menu;
	delete newFile;
	delete open;
	delete save;
	delete saveAs;
	delete quit;
}

void FileMenu::onNewFileClicked() {
	TabPane::addNewTab();
}

void FileMenu::onOpenClicked() {
	Actions::openFile();
}

void FileMenu::onSaveClicked() {
	Actions::saveFile();
}

void FileMenu::onSaveAsClicked() {
	Actions::saveFileAs();
}

void FileMenu::onQuitClicked() {
	app->quit();
}
