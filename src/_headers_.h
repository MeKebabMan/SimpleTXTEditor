#ifndef __headers_h_
#define __headers_h_

#include "glib.h"
#include <gtk/gtk.h>

// WARNING: USE CORRECTLY!
#define _FUNC(func) ((int*)(func))

// CREATE GTK APP
int CreateGTKAPP(const char* __appID, int* __FUNC, int argc, char** argv);

const char* GET_CSS_PATH_1(const char* __TOML_CONFIG);

const char* GET_CSS_PATH_2(const char* _TOML_CONFIG);

// GTK Save file (USER_DATA MUST BE A GTK_TEXT_VIEW)
void GTK_Savefile(GtkWidget* widget, gpointer user_data);

// GTK Open file (USER_DATA MUST BE A GTK_TEXT_VIEW)
void GTK_Openfile(GtkWidget* widget, gpointer user_data);

#endif // __headers_h_
