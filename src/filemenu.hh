#pragma once

#include <gtkmm/menuitem.h>
#include <gtkmm/application.h>
#include <gtkmm/menu.h>

class FileMenu : public Gtk::MenuItem {
public:
	FileMenu(Glib::RefPtr<Gtk::Application> appP);
	~FileMenu();
private:
	Glib::RefPtr<Gtk::Application> app;
	Gtk::Menu *menu;
	MenuItem *newFile, *open, *quit;
	void onNewFileClicked();
	void onOpenClicked();
	void onQuitClicked();
};
