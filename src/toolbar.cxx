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
#include "toolbar.hh"
#include "tabpane.hh"
#include "actions.hh"

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
	
	newFile->signal_clicked().connect(sigc::mem_fun(*this,&ToolBar::onNewFileClicked));
	openFile->signal_clicked().connect(sigc::mem_fun(*this,&ToolBar::onOpenFileClicked));
	saveFile->signal_clicked().connect(sigc::mem_fun(*this,&ToolBar::onSaveFileClicked));
	saveFileAs->signal_clicked().connect(sigc::mem_fun(*this,&ToolBar::onSaveFileAsClicked));
	cut->signal_clicked().connect(sigc::mem_fun(*this,&ToolBar::onCutClicked));
	copy->signal_clicked().connect(sigc::mem_fun(*this,&ToolBar::onCopyClicked));
	paste->signal_clicked().connect(sigc::mem_fun(*this,&ToolBar::onPasteClicked));
	
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

void ToolBar::onNewFileClicked() {
	TabPane::addNewTab();
}

void ToolBar::onOpenFileClicked() {
	Actions::openFile();
}

void ToolBar::onSaveFileClicked() {
	Actions::saveFile();
}

void ToolBar::onSaveFileAsClicked() {
	Actions::saveFileAs();
}

void ToolBar::onCutClicked() {
	Actions::cut();
}

void ToolBar::onCopyClicked() {
	Actions::copy();
}

void ToolBar::onPasteClicked() {
	Actions::paste();
}
