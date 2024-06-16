#ifndef __headers_h_
#define __headers_h_

#include "glib.h"
#include <complex.h>
#include <gtk/gtk.h>

// WARNING: USE CORRECTLY!
#define _FUNC(func) ((int*)(func))

// WINDOW DEFAULT WIDTH
#define win_w 550
#define win_h 450

// CREATE GTK APP
int CreateGTKAPP(const char* __appID, int* __FUNC, int argc, char** argv);

const char* GET_CSS_PATH_1(const char* __TOML_CONFIG);

const char* GET_CSS_PATH_2(const char* _TOML_CONFIG);

// GTK Save file (USER_DATA MUST BE A GTK_TEXT_VIEW)
void GTK_Savefile(GtkWidget* widget, gpointer user_data);

// GTK Open file (USER_DATA MUST BE A GTK_TEXT_VIEW)
void GTK_Openfile(GtkWidget* widget, gpointer user_data);

void GTK_DESTROY_WIDGET(GtkWidget *widget, gpointer data);

// SIMPLETXTEDITOR GUI
void activate_GTK_APP(GtkApplication *app, gpointer data);



#endif // __headers_h_
