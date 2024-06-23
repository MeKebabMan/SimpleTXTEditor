#ifndef __headers_h_
#define __headers_h_

#include "glib.h"
#include <gtk/gtk.h>
#include <stdbool.h>

// ERROR HANDLING 
#define H_OK true 
#define H_ERR false 
#define H_NO NULL

// FUNCTION TYPES
#define H_BOOL bool
#define H_PTR void*
#define H_VAR void

// WARNING: USE CORRECTLY!
#define _FUNC(func) ((int*)(func))

// WINDOW DEFAULT WIDTH
#define win_w 550
#define win_h 450

// BUTTON OPTIONS STRUCT 
typedef struct {
	bool use_savefile;
	bool use_openfile;
	bool use_quit;
} Button_Options_struct;

const char* GET_TOML_CONFIG_PATH();

// TOML_FILE_PATH 

extern const char* TOML_FILE_PATH;

extern Button_Options_struct  _BUTTON_OPTIONS_;

// EXTERN GTKWIDGET LOCATED IN MAIN.C (CAREFUL!) 
extern GtkWidget* text_view;
extern GtkWidget* file_name;

// CREATE GTK APP
int CreateGTKAPP(const char* __appID, int* __FUNC, int argc, char** argv);

// DOES NOT RETURN H_OK / H_ERR 
const char* GET_CSS_PATH_1(const char* __TOML_CONFIG);

// DOES NOT RETURN H_OK / H_ERR 
const char* GET_CSS_PATH_2(const char* _TOML_CONFIG);

// DOES NOT RETURN H_OK / H_ERR 
// GTK Save file (USER_DATA MUST BE A GTK_TEXT_VIEW)
H_VAR GTK_Savefile(GtkWidget* widget, gpointer user_data);

// DOES NOT RETURN H_OK / H_ERR 
// GTK Open file (USER_DATA MUST BE A GTK_TEXT_VIEW)
H_VAR GTK_Openfile(GtkWidget* widget, gpointer user_data);

// DOES NOT RETURN H_OK / H_ERR 
H_VAR GTK_DESTROY_WINDOW(GtkWidget* widget, gpointer data);

// DOES NOT RETURN H_OK / H_ERR 
// SIMPLETXTEDITOR GUI
H_VAR activate_GTK_APP(GtkApplication *app, gpointer data);

// RETURNS H_OK / H_ERR 
H_BOOL UPDATE_TOML_BUTTON_OPTIONS(const char* __TOML_CONFIG, Button_Options_struct* _OPTIONS);

#endif // __headers_h_
