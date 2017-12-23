#include "toolbar.hh"

ToolBar::ToolBar() {
	newFile = new Gtk::ToolButton;
	openFile = new Gtk::ToolButton;
	saveFile = new Gtk::ToolButton;
	saveFileAs = new Gtk::ToolButton;
	cut = new Gtk::ToolButton;
	copy = new Gtk::ToolButton;
	paste = new Gtk::ToolButton;
	selectAll = new Gtk::ToolButton;
	undo = new Gtk::ToolButton;
	redo = new Gtk::ToolButton;
	
	newFile->set_icon_name("document-new");
	openFile->set_icon_name("document-open");
	saveFile->set_icon_name("document-save");
	saveFileAs->set_icon_name("document-save-as");
	cut->set_icon_name("edit-cut");
	copy->set_icon_name("edit-copy");
	paste->set_icon_name("edit-paste");
	selectAll->set_icon_name("edit-select-all");
	undo->set_icon_name("edit-undo");
	redo->set_icon_name("edit-redo");
	
	this->append(*newFile);
	this->append(*openFile);
	this->append(*saveFile);
	this->append(*saveFileAs);
	this->append(*cut);
	this->append(*copy);
	this->append(*paste);
	this->append(*selectAll);
	this->append(*undo);
	this->append(*redo);
}

ToolBar::~ToolBar() {
	delete newFile;
	delete openFile;
	delete saveFile;
	delete saveFileAs;
	delete cut;
	delete copy;
	delete paste;
	delete selectAll;
	delete undo;
	delete redo;
}
