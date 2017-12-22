#include "editor.hh"

Editor::Editor() {
	edit = new Gtk::TextView;
	this->add(*edit);
}

Editor::~Editor() {
	delete edit;
}

void Editor::setText(std::string text) {
	edit->get_buffer()->set_text(text);
}
