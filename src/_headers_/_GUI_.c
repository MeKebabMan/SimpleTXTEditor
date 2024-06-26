#include <stdio.h>
#include <gtk/gtk.h>
#include "../_headers_.h"
#include "glib-object.h"
#include "glib.h"
#include "glibconfig.h"
#include "gtk/gtkshortcut.h"

// void
H_VAR activate_GTK_APP(GtkApplication *app, gpointer data) {
  // UPDATE BUTTON OPTIONS!! 
  UPDATE_TOML_BUTTON_OPTIONS(GET_TOML_CONFIG_PATH(), &_BUTTON_OPTIONS_);

  GtkWidget *window;
  GtkWidget *Win_grid;
  GtkWidget *Second_grid;
  GtkWidget *Savefile;
  GtkWidget *Openfile;
  GtkWidget *Quit;
  GtkWidget *Scroll_win;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "SimpleTextEditor");
  gtk_window_set_default_size(GTK_WINDOW(window), win_w, win_h);
  g_signal_connect(window, "destroy", G_CALLBACK(GTK_DESTROY_WINDOW), GTK_WINDOW(window));

  Win_grid = gtk_grid_new();
  gtk_widget_set_halign(Win_grid, GTK_ALIGN_FILL);
  gtk_widget_set_valign(Win_grid, GTK_ALIGN_FILL);
  gtk_widget_set_vexpand(Win_grid, TRUE);
  gtk_widget_set_hexpand(Win_grid, TRUE);

  Second_grid = gtk_grid_new();
  gtk_widget_set_halign(Second_grid, GTK_ALIGN_FILL);
  gtk_widget_set_valign(Second_grid, GTK_ALIGN_FILL);
  gtk_widget_set_vexpand(Second_grid, FALSE);
  gtk_widget_set_hexpand(Second_grid, TRUE);


  Savefile = gtk_button_new_with_label("Save file");
  gtk_widget_set_vexpand(Savefile, TRUE);
  gtk_widget_set_hexpand(Savefile, TRUE);
  gtk_widget_set_name(GTK_WIDGET(Savefile), "savefile");
  g_signal_connect(Savefile, "clicked", G_CALLBACK(GTK_Savefile), window);

  Openfile = gtk_button_new_with_label("Open file");
  gtk_widget_set_vexpand(Openfile, TRUE);
  gtk_widget_set_hexpand(Openfile, TRUE);
  gtk_widget_set_name(GTK_WIDGET(Openfile), "openfile");
	
  g_signal_connect(Openfile, "clicked", G_CALLBACK(GTK_Openfile), window);

  Quit = gtk_button_new_with_label("QUIT");
  gtk_widget_set_vexpand(Quit, TRUE);
  gtk_widget_set_hexpand(Quit, TRUE);
  g_signal_connect(Quit, "clicked", G_CALLBACK(GTK_DESTROY_WINDOW), GTK_WINDOW(window));
  gtk_widget_set_name(GTK_WIDGET(Quit), "quit");

  Scroll_win = gtk_scrolled_window_new();
  gtk_widget_set_vexpand(Scroll_win, TRUE);
  gtk_widget_set_hexpand(Scroll_win, TRUE);

  text_view = gtk_text_view_new();
  gtk_widget_set_name(GTK_WIDGET(text_view), "textbox");

  file_name = gtk_label_new("Untitled.txt");
  gtk_widget_set_halign(file_name, GTK_ALIGN_FILL);
  gtk_widget_set_valign(file_name, GTK_ALIGN_FILL);
  gtk_widget_set_vexpand(file_name, FALSE);
  gtk_widget_set_hexpand(file_name, TRUE);
  gtk_widget_set_name(GTK_WIDGET(file_name), "file");

  char css_full_path[255];

  if (access(GET_CSS_PATH_1(GET_TOML_CONFIG_PATH()), F_OK) == 0) {
    snprintf(css_full_path, sizeof(css_full_path), "%s",
             GET_CSS_PATH_1(GET_TOML_CONFIG_PATH()));
  } else {
    if (access(GET_CSS_PATH_2(GET_TOML_CONFIG_PATH()), F_OK) == 0) {
      snprintf(css_full_path, sizeof(css_full_path), "%s",
               GET_CSS_PATH_2(GET_TOML_CONFIG_PATH()));
    } else {
      g_print("FAILED TO GET CSS PATH!\n%s", GET_TOML_CONFIG_PATH());
      gtk_window_destroy(GTK_WINDOW(window));
      return;
    }
  }

  GtkCssProvider *cssProvider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(cssProvider, css_full_path);
  gtk_style_context_add_provider_for_display(gdk_display_get_default(),
                                             GTK_STYLE_PROVIDER(cssProvider),
                                             GTK_STYLE_PROVIDER_PRIORITY_USER);

  // WINDOW APPENDING
  gtk_window_set_child(GTK_WINDOW(window), Win_grid);

  // WIN_GRID APPENDING
  gtk_grid_attach(GTK_GRID(Win_grid), Second_grid, 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(Win_grid), Scroll_win, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(Win_grid), file_name, 0, 2, 1, 1);

  // CHILDREN APPENDING
  if (_BUTTON_OPTIONS_.use_savefile == H_OK) {
	  gtk_grid_attach(GTK_GRID(Second_grid), Savefile, 0, 0, 1, 1);
  }
  if (_BUTTON_OPTIONS_.use_openfile == H_OK) {
	  gtk_grid_attach(GTK_GRID(Second_grid), Openfile, 1, 0, 1, 1);
  }
  if (_BUTTON_OPTIONS_.use_quit == H_OK) {
	  gtk_grid_attach(GTK_GRID(Second_grid), Quit, 2, 0, 1, 1);
  }
  gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(Scroll_win), text_view);

  gtk_window_present(GTK_WINDOW(window));
}
