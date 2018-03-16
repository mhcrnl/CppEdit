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
#include "main_menu_button.hh"
#include "filemenu.hh"
#include "window.hh"

MainMenuButton::MainMenuButton(Glib::RefPtr<Gtk::Application> appP) {
	app = appP;
	this->set_label("Menu");
	
	menu = new Gtk::Menu;
	this->set_popup(*menu);
	
	FileMenu *filemenu = new FileMenu;
	menu->append(*filemenu);
	
	quit = new Gtk::ImageMenuItem("Quit");
	
	quit->set_always_show_image();
	
	quitIcon = new Gtk::Image;
	quitIcon->set_from_icon_name("application-exit",Gtk::ICON_SIZE_MENU);
	quit->set_image(*quitIcon);
	
	quit->signal_activate().connect(sigc::mem_fun(*this,&MainMenuButton::onQuitClicked));
	
	menu->append(*quit);
	
	menu->show_all();
}

MainMenuButton::~MainMenuButton() {
	delete menu;
	delete quit;
	delete quitIcon;
}

void MainMenuButton::onQuitClicked() {
	if (AppWindow::checkSave()==false) {
		app->quit();
	}
}
