#pragma

#include <gtkmm/headerbar.h>
#include <gtkmm/application.h>

class HeaderBar : public Gtk::HeaderBar {
public:
	HeaderBar(Glib::RefPtr<Gtk::Application> app);
};
