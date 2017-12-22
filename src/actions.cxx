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
	
	if ((untitled==false)||((untitled==true)&&(saved==false))) {
		TabPane::addNewTab();
		edit = TabPane::currentWidget();
	}
	
	edit->setText(content);
	edit->setUntitled(false);
	edit->setSaved(true);
	TabPane::setCurrentFilePath(path);
}

void Actions::saveFile() {
	Editor *edit = TabPane::currentWidget();
	if (edit->isUntitled()) {
		//Call save-as function
		edit = TabPane::currentWidget();
	}
	std::string path = edit->getPath();
	std::string text = edit->getText();
	
	std::ofstream writer;
	writer.open(path);
	writer << text;
	writer.close();
	
	edit->setSaved(true);
}
