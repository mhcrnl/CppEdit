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
#include <gtkmm/hvbox.h>
#include <gtkmm/button.h>
#include <gtkmm/messagedialog.h>

#include "window.hh"
#include "header.hh"
#include "toolbar.hh"
#include "tabpane.hh"
#include "editor.hh"

AppWindow::AppWindow(Glib::RefPtr<Gtk::Application> appP) {
	app = appP;

	this->set_title("CppEdit");
	this->set_default_size(800,600);
	this->set_icon_name("accessories-text-editor");
	this->signal_delete_event().connect(sigc::mem_fun(*this,&AppWindow::onWindowClosed));
	
	Gtk::VBox *mainLayout = new Gtk::VBox(false,false);
	this->add(*mainLayout);
	
	TabPane *tabpane = new TabPane;
	HeaderBar *titleBar = new HeaderBar(app);
	ToolBar *toolbar = new ToolBar;
	
	this->set_titlebar(*titleBar);
	mainLayout->pack_start(*toolbar,false,false,0);
	mainLayout->pack_start(*tabpane,true,true,0);
}

bool AppWindow::checkSave() {
	bool found = false;
	int count = TabPane::tabs->get_n_pages();
	for (int i = 0; i<count; i++) {
		Editor *edit = static_cast<Editor *>(TabPane::tabs->get_nth_page(i));
		if (!edit->isSaved()) {
			found = true;
		}
	}
	
	if (found) {
		Gtk::MessageDialog *msg = new Gtk::MessageDialog(
			"You have unsaved files!\nDo you wish to exit?",false,
			Gtk::MESSAGE_WARNING,Gtk::BUTTONS_YES_NO,false);
		int ret = msg->run();
		delete msg;
		switch (ret) {
			case Gtk::RESPONSE_YES: return false; break;
			case Gtk::RESPONSE_NO: return true; break;
			default: return false;
		}
	} else {
		return false;
	}
}

bool AppWindow::onWindowClosed(GdkEventAny* event) {
	return checkSave();
}
