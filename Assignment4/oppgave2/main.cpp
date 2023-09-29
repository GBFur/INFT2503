#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::Box box;
  Gtk::Entry entry_first_name;
  Gtk::Entry entry_last_name;
  Gtk::Button button;
  Gtk::Label label;

  Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
    set_title("Assignment 4, task 2");

    entry_first_name.set_placeholder_text("First Name");
    entry_last_name.set_placeholder_text("Last Name");
    button.set_label("Combine names");
    button.set_sensitive(false); // Greyed out

    box.pack_start(entry_first_name);
    box.pack_start(entry_last_name);
    box.pack_start(button);
    box.pack_start(label);

    add(box);   // Add vbox to window
    show_all(); // Show all widgets

    entry_first_name.signal_changed().connect([this]() {
      handle_sensitive();
    });

    entry_last_name.signal_changed().connect([this]() {
      handle_sensitive();
    });

    button.signal_clicked().connect([this]() {
      label.set_text("Navn: " + entry_first_name.get_text() + " " + entry_last_name.get_text() + "\n");
    });
  }

private:
  void handle_sensitive() {
    if (entry_first_name.get_text_length() > 0 && entry_last_name.get_text_length() > 0) {
      button.set_sensitive(true);
    } else {
      button.set_sensitive(false);
    }
  }
};

  int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
  }