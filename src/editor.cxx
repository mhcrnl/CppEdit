#include "editor.hh"

Editor::Editor() {
	edit = new Gtk::TextView;
	edit->set_wrap_mode(Gtk::WRAP_WORD);
	this->add(*edit);
}

Editor::~Editor() {
	delete edit;
}

void Editor::setText(std::string text) {
	edit->get_buffer()->set_text(text);
}

void Editor::setPath(std::string path) {
	filePath = path;
}

std::string Editor::getPath() {
	return filePath;
}

void Editor::setTabLabel(Gtk::Label *label) {
	tabLabel = label;
}

Gtk::Label *Editor::getLabel() {
	return tabLabel;
}

void Editor::setUntitled(bool u) {
	untitled = u;
}

bool Editor::isUntitled() {
	return untitled;
}

void Editor::setSaved(bool s) {
	saved = s;
}

bool Editor::isSaved() {
	return saved;
}
