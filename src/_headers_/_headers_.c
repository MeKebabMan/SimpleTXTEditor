#include "../_headers_.h"
#include "gio/gio.h"
#include "glib-object.h"
#include "glib.h"
#include "gtk/gtk.h"
#include "gtk/gtkshortcut.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CREATE GTK APP

int CreateGTKAPP(const char *__appID, int *__FUNC, int argc, char **argv) {

  GtkApplication *app;
  int status = 0;

  app = gtk_application_new(__appID, G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(__FUNC), NULL);

  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}

// void
H_VAR GTK_DESTROY_WINDOW(GtkWidget *widget, gpointer data) {
  GtkWidget *_WIDGET = GTK_WIDGET(data);
  if (GTK_IS_WINDOW(GTK_WINDOW(data))) {
    gtk_window_destroy(GTK_WINDOW(_WIDGET));
  }
}

const char* GET_TOML_CONFIG_PATH() {
	const char* HOME_ENV = g_get_home_dir();

	const unsigned int buffer_size = 255;
	char* buffer = (char*)calloc(buffer_size + 1, sizeof(char));

	if (buffer == NULL) {
		return H_NO;
	}

	if (TOML_FILE_PATH == H_NO) {
		free(buffer);
		return H_NO;
	}

	// APPEND THE STRINGS!
	size_t buffer_count = snprintf(buffer, buffer_size - 1, "%s/%s", HOME_ENV, TOML_FILE_PATH);

	// ERROR HANDLING!
	if (buffer[buffer_count] == '\0') {
		// ADD 1 INTO THE CHECK FOR THE NULL TERMINATOR
		if (buffer_count != strlen(HOME_ENV) + strlen(TOML_FILE_PATH) + 1) {
			free(buffer);
			return H_NO;
		}
	} else {
		// SKIP ADDING 1 FOR THE NULL TERMINATOR
		if (buffer_count != strlen(HOME_ENV) + strlen(TOML_FILE_PATH)) {
			free(buffer);
			return H_NO;
		}
	}

	// DUP THE STRING 
	const char* static_buffer = strdup(buffer);
	if (static_buffer == H_NO) {
		free(buffer);
		return H_NO;
	}

	// FREE THE ALLOCATED BUFFER & RETURN THE STATIC BUFFER
	free(buffer);

	// RETURNING THE STATIC BUFFER
	return (const char*)static_buffer;

}
