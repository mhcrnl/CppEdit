#pragma once

#include <gtkmm/imagemenuitem.h>
#include <gtkmm/application.h>
#include <gtkmm/menu.h>
#include <gtkmm/image.h>

class FileMenu : public Gtk::MenuItem {
public:
	FileMenu(Glib::RefPtr<Gtk::Application> appP);
	~FileMenu();
private:
	Glib::RefPtr<Gtk::Application> app;
	Gtk::Menu *menu;
	Gtk::ImageMenuItem *newFile, *open, *save, *saveAs, *quit;
	Gtk::Image *newFileIcon, *openIcon, *saveIcon, *saveAsIcon, *quitIcon;
	
	void onNewFileClicked();
	void onOpenClicked();
	void onSaveClicked();
	void onSaveAsClicked();
	void onQuitClicked();
};
