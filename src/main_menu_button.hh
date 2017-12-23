#pragma once

#include <gtkmm/menubutton.h>
#include <gtkmm/menu.h>
#include <gtkmm/application.h>
#include <gtkmm/imagemenuitem.h>
#include <gtkmm/image.h>

class MainMenuButton : public Gtk::MenuButton {
public:
	MainMenuButton(Glib::RefPtr<Gtk::Application> appP);
	~MainMenuButton();
private:
	Glib::RefPtr<Gtk::Application> app;
	Gtk::Menu *menu;
	Gtk::ImageMenuItem *quit;
	Gtk::Image *quitIcon;
	
	void onQuitClicked();
};
