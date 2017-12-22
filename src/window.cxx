#include <gtkmm/hvbox.h>
#include <gtkmm/button.h>
#include <gtkmm/messagedialog.h>

#include "window.hh"
#include "menubar.hh"
#include "tabpane.hh"
#include "editor.hh"

AppWindow::AppWindow(Glib::RefPtr<Gtk::Application> appP) {
	app = appP;

	this->set_title("CppEdit");
	this->set_default_size(500,400);
	this->set_icon_name("accessories-text-editor");
	this->signal_delete_event().connect(sigc::mem_fun(*this,&AppWindow::onWindowClosed));
	
	Gtk::VBox *mainLayout = new Gtk::VBox(false,false);
	this->add(*mainLayout);
	
	TabPane *tabpane = new TabPane;
	Menubar *menubar = new Menubar(appP);
	
	mainLayout->pack_start(*menubar,false,false,0);
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
