#pragma once

#include <gtkmm/hvbox.h>
#include <gtkmm/notebook.h>
#include <gtkmm/widget.h>
#include <string>

#include "editor.hh"

class TabPane : public Gtk::VBox {
public:
	TabPane();
	static Gtk::Notebook *tabs;
	static void addNewTab(std::string title);
	static void addNewTab();
	static Editor *currentWidget();
	static void setCurrentFilePath(std::string path);
private:
	static void onCloseClicked(Gtk::Widget *btn);
};
