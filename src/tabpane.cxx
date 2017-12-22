#include <gtkmm/label.h>
#include <gtkmm/button.h>

#include "tabpane.hh"

Gtk::Notebook *TabPane::tabs;

TabPane::TabPane() {
	tabs = new Gtk::Notebook();
	this->pack_start(*tabs,true,true,0);
	
	this->addNewTab();
}

void TabPane::addNewTab(std::string title) {
	Gtk::HBox *tabLabel = new Gtk::HBox(false,0);
	Gtk::Label *label = new Gtk::Label(title);
	Gtk::Button *close = new Gtk::Button();
	close->set_image_from_icon_name("edit-delete");
	close->set_always_show_image(true);
	tabLabel->pack_start(*label,false,false,0);
	tabLabel->pack_start(*close,false,false,0);
	tabLabel->show_all();
	
	Editor *pg = new Editor;
	tabs->append_page(*pg,*tabLabel);
	
	close->signal_clicked().connect(sigc::bind<Gtk::Widget *>(sigc::ptr_fun(&TabPane::onCloseClicked),pg));
	
	tabs->show_all();
}

void TabPane::addNewTab() {
	addNewTab("untitled");
}

Editor *TabPane::currentWidget() {
	int current = tabs->get_current_page();
	if (current==-1) {
		return nullptr;
	}
	Editor *edit = static_cast<Editor *>(tabs->get_nth_page(current));
	return edit;
}

void TabPane::onCloseClicked(Gtk::Widget *btn) {
	int no = tabs->page_num(*btn);
	delete tabs->get_nth_page(no);
}
