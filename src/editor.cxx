// Copyright 2018 Patrick Flynn
//
// Redistribution and use in source and binary forms, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, 
//	this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this 
//	list of conditions and the following disclaimer in the documentation and/or 
//	other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may 
//	be used to endorse or promote products derived from this software 
//	without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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

void Editor::copy() {
	Glib::RefPtr<Gtk::Clipboard> clip = Gtk::Clipboard::get();
	edit->get_buffer()->copy_clipboard(clip);
}

void Editor::paste() {
	Glib::RefPtr<Gtk::Clipboard> clip = Gtk::Clipboard::get();
	edit->get_buffer()->paste_clipboard(clip,true);
}

void Editor::onChanged() {
	saveStatus->set_text("*");
	saved = false;
}
