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
#include <gtkmm/menu.h>
#include <gtkmm/image.h>

#include "filemenu.hh"
#include "tabpane.hh"
#include "actions.hh"

FileMenu::FileMenu() {
	this->set_label("File");
	
	menu = new Gtk::Menu;
	this->set_submenu(*menu);
	
	newFile = new Gtk::ImageMenuItem("New");
	open = new Gtk::ImageMenuItem("Open");
	save = new Gtk::ImageMenuItem("Save");
	saveAs = new Gtk::ImageMenuItem("Save As");
	
	newFile->set_always_show_image();
	open->set_always_show_image();
	save->set_always_show_image();
	saveAs->set_always_show_image();
	
	newFileIcon = new Gtk::Image;
	newFileIcon->set_from_icon_name("document-new",Gtk::ICON_SIZE_MENU);
	newFile->set_image(*newFileIcon);
	
	openIcon = new Gtk::Image;
	openIcon->set_from_icon_name("document-open",Gtk::ICON_SIZE_MENU);
	open->set_image(*openIcon);
	
	saveIcon = new Gtk::Image;
	saveIcon->set_from_icon_name("document-save",Gtk::ICON_SIZE_MENU);
	save->set_image(*saveIcon);
	
	saveAsIcon = new Gtk::Image;
	saveAsIcon->set_from_icon_name("document-save-as",Gtk::ICON_SIZE_MENU);
	saveAs->set_image(*saveAsIcon);
	
	newFile->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onNewFileClicked));
	open->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onOpenClicked));
	save->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onSaveClicked));
	saveAs->signal_activate().connect(sigc::mem_fun(*this,&FileMenu::onSaveAsClicked));
	
	menu->append(*newFile);
	menu->append(*open);
	menu->append(*save);
	menu->append(*saveAs);
}

FileMenu::~FileMenu() {
	delete menu;
	delete newFile;
	delete open;
	delete save;
	delete saveAs;
	delete newFileIcon;
	delete openIcon;
	delete saveIcon;
	delete saveAsIcon;
}

void FileMenu::onNewFileClicked() {
	TabPane::addNewTab();
}

void FileMenu::onOpenClicked() {
	Actions::openFile();
}

void FileMenu::onSaveClicked() {
	Actions::saveFile();
}

void FileMenu::onSaveAsClicked() {
	Actions::saveFileAs();
}
