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
#include <gtkmm/filechooserdialog.h>
#include <fstream>

#include "actions.hh"
#include "file_utils.hh"
#include "tabpane.hh"
#include "editor.hh"

void Actions::openFile() {
	Gtk::FileChooserDialog *dialog = new Gtk::FileChooserDialog("Open File");
	dialog->add_button("_Cancel",Gtk::RESPONSE_CANCEL);
	dialog->add_button("_Open",Gtk::RESPONSE_OK);
	
	int ret = dialog->run();
	if (ret==Gtk::RESPONSE_OK) {
		std::string path = dialog->get_filename();
		delete dialog;
	
		std::string content = FileUtils::fileContent(path);
		
		Editor *edit = TabPane::currentWidget();
		bool untitled = edit->isUntitled();
		bool saved = edit->isSaved();
	
		if ((untitled==false)||((untitled==true)&&(saved==false))) {
			TabPane::addNewTab();
			edit = TabPane::currentWidget();
		}
	
		edit->setText(content);
		edit->setUntitled(false);
		edit->setSaved(true);
		TabPane::setCurrentFilePath(path);	
	} else {
		delete dialog;
	}
}

void Actions::saveFile() {
	Editor *edit = TabPane::currentWidget();
	if (edit->isUntitled()) {
		saveFileAs();
		edit = TabPane::currentWidget();
		if (edit->isUntitled()) {
			return;
		}
	}
	std::string path = edit->getPath();
	std::string text = edit->getText();
	
	std::ofstream writer;
	writer.open(path);
	writer << text;
	writer.close();
	
	edit->setSaved(true);
}

void Actions::saveFileAs() {
	Gtk::FileChooserDialog *dialog = new Gtk::FileChooserDialog("Save File",Gtk::FILE_CHOOSER_ACTION_SAVE);
	dialog->add_button("_Cancel",Gtk::RESPONSE_CANCEL);
	dialog->add_button("_Save",Gtk::RESPONSE_OK);
	
	int ret = dialog->run();
	if (ret==Gtk::RESPONSE_OK) {
		std::string path = dialog->get_filename();
		delete dialog;
		
		TabPane::setCurrentFilePath(path);
		Editor *edit = TabPane::currentWidget();
		edit->setUntitled(false);
		
		saveFile();
	} else {
		delete dialog;
		return;
	}
}

void Actions::cut() {
	TabPane::currentWidget()->cut();
}

void Actions::copy() {
	TabPane::currentWidget()->copy();
}

void Actions::paste() {
	TabPane::currentWidget()->paste();
}
