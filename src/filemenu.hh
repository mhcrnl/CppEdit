#pragma once

#include <gtkmm/menuitem.h>
#include <gtkmm/imagemenuitem.h>
#include <gtkmm/menu.h>
#include <gtkmm/image.h>

class FileMenu : public Gtk::MenuItem {
public:
	FileMenu();
	~FileMenu();
private:
	Gtk::Menu *menu;
	Gtk::ImageMenuItem *newFile, *open, *save, *saveAs;
	Gtk::Image *newFileIcon, *openIcon, *saveIcon, *saveAsIcon;
	
	void onNewFileClicked();
	void onOpenClicked();
	void onSaveClicked();
	void onSaveAsClicked();
};
