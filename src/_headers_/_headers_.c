#include "../_headers_.h"
#include "../toml.h"
#include "gio/gio.h"
#include "glib-object.h"
#include "gtk/gtk.h"
#include <stdio.h>

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



// GET CSS PATH 1

const char *GET_CSS_PATH_1(const char *__TOML_CONFIG) {

  FILE *TOML_PTR = fopen(__TOML_CONFIG, "r");
  if (TOML_PTR == NULL) {
    printf("%s", __TOML_CONFIG);
    return NULL;
  }

  char ERRBUFF[255];
  toml_table_t *toml = toml_parse_file(TOML_PTR, ERRBUFF, sizeof(ERRBUFF));
  if (!toml) {
    printf("%s", ERRBUFF);
    return NULL;
  }

  toml_table_t *CSS_PROP = toml_table_in(toml, "CSS");
  if (!CSS_PROP) {
    printf("2");
    toml_free(CSS_PROP);
    return NULL;
  }

  toml_datum_t CSS_PATH = toml_string_in(CSS_PROP, "PATH");
  if (!CSS_PATH.ok) {
    printf("3");
    toml_free(toml);
    return NULL;
  }

  toml_free(toml);
  fclose(TOML_PTR);

  return (const char *)CSS_PATH.u.s;
}

// GET CSS PATH 2

const char *GET_CSS_PATH_2(const char *__TOML_CONFIG) {

  FILE *TOML_PTR = fopen(__TOML_CONFIG, "r");
  if (TOML_PTR == NULL) {
    printf("%s", __TOML_CONFIG);
    return NULL;
  }

  char ERRBUFF[255];
  toml_table_t *toml = toml_parse_file(TOML_PTR, ERRBUFF, sizeof(ERRBUFF));
  if (!toml) {
    printf("%s", ERRBUFF);
    return NULL;
  }

  toml_table_t *CSS_PROP = toml_table_in(toml, "CSS");
  if (!CSS_PROP) {
    printf("2");
    toml_free(toml);
    return NULL;
  }

  toml_datum_t CSS_INSTALL_PATH = toml_string_in(CSS_PROP, "INSTALL");
  if (!CSS_INSTALL_PATH.ok) {
    printf("3");
    toml_free(toml);
    return NULL;
  }

  toml_free(toml);
  fclose(TOML_PTR);

  return (const char *)CSS_INSTALL_PATH.u.s;
}

// GTK SAVE FILE

void GTK_Savefile(GtkWidget *widget, gpointer user_data) {

}

// GTK OPEN FILE

void GTK_Openfile(GtkWidget *widget, gpointer user_data) {

}

// GTK DESTROY WIDGET

void GTK_DESTROY_WIDGET(GtkWidget *widget, gpointer data) {
  GtkWidget *WINDOW = GTK_WIDGET(data);
  if (GTK_IS_WINDOW(GTK_WINDOW(data))) {
    gtk_window_destroy(GTK_WINDOW(WINDOW));
  }
}