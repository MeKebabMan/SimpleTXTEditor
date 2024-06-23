#include "_headers_.h"

// GLOBAL VARIABLES (DO NOT CHANGE IN MAIN.C!!)
GtkWidget* text_view;
GtkWidget *file_name;

// TOML_CONFIG_PATH 
const char* TOML_FILE_PATH = ".config/SimpleTXTEditor/SimpleTXTEditor.toml";

// BUTTON OPTIONS
Button_Options_struct _BUTTON_OPTIONS_ = {
	true, // use savefile
	true, // use openfile 
	true, // use quit
};

int main(int argc, char **argv) {
  return CreateGTKAPP("com.TextEditor.SimpleTextEditor",
                      _FUNC(activate_GTK_APP), argc, argv);
}
