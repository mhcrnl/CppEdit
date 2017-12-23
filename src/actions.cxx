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
