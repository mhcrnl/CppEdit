#include <fstream>

#include "actions.hh"
#include "file_utils.hh"
#include "tabpane.hh"
#include "editor.hh"

void Actions::openFile(std::string path) {
	std::string content = FileUtils::fileContent(path);
		
	Editor *edit = TabPane::currentWidget();
	bool untitled = edit->isUntitled();
	bool saved = edit->isSaved();
	
	if (untitled==false) {
		TabPane::addNewTab();
		edit = TabPane::currentWidget();
	}
	
	edit->setText(content);
	edit->setUntitled(false);
	TabPane::setCurrentFilePath(path);
}
