#pragma once

#include <gtkmm/toolbar.h>
#include <gtkmm/toolbutton.h>

class ToolBar : public Gtk::Toolbar {
public:
	ToolBar();
	~ToolBar();
private:
	Gtk::ToolButton *newFile, *openFile, *saveFile, *saveFileAs;
	Gtk::ToolButton *cut, *copy, *paste, *selectAll;
	Gtk::ToolButton *undo, *redo;
	
	void onNewFileClicked();
	void onOpenFileClicked();
	void onSaveFileClicked();
	void onSaveFileAsClicked();
	void onCutClicked();
};
