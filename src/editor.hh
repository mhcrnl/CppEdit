#pragma once

#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/label.h>
#include <string>

class Editor : public Gtk::ScrolledWindow {
public:
	Editor();
	~Editor();
	void setText(std::string text);
	std::string getText();
	void setPath(std::string path);
	std::string getPath();
	void setTabLabel(Gtk::Label *label);
	Gtk::Label *getLabel();
	void setSaveStatusLabel(Gtk::Label *label);
	void setUntitled(bool u);
	bool isUntitled();
	void setSaved(bool s);
	bool isSaved();
private:
	Gtk::TextView *edit;
	std::string filePath;
	Gtk::Label *tabLabel, *saveStatus;
	bool untitled = true;
	bool saved = true;
	void onChanged();
};
