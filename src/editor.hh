#pragma once

#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <string>

class Editor : public Gtk::ScrolledWindow {
public:
	Editor();
	~Editor();
	void setText(std::string text);
private:
	Gtk::TextView *edit;
};
