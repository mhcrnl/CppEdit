#include <gtkmm/clipboard.h>

#include "editor.hh"

Editor::Editor() {
	edit = new Gtk::TextView;
	edit->set_wrap_mode(Gtk::WRAP_WORD);
	edit->get_buffer()->signal_changed().connect(sigc::mem_fun(*this,&Editor::onChanged));
	this->add(*edit);
}

Editor::~Editor() {
	delete edit;
}

void Editor::setText(std::string text) {
	edit->get_buffer()->set_text(text);
}

std::string Editor::getText() {
	return edit->get_buffer()->get_text();
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

void Editor::setSaveStatusLabel(Gtk::Label *label) {
	saveStatus = label;
}

void Editor::setUntitled(bool u) {
	untitled = u;
}

bool Editor::isUntitled() {
	return untitled;
}

void Editor::setSaved(bool s) {
	saved = s;
	saveStatus->set_text("");
}

bool Editor::isSaved() {
	return saved;
}

void Editor::cut() {
	Glib::RefPtr<Gtk::Clipboard> clip = Gtk::Clipboard::get();
	edit->get_buffer()->cut_clipboard(clip,true);
}

void Editor::onChanged() {
	saveStatus->set_text("*");
	saved = false;
}
