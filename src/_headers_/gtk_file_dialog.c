#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "../_headers_.h"
#include "glib-object.h"
#include "glib.h"

// MEMORY ALLOCATIONS HAVE BEEN USED HERE!! THEY SHOULD BE FREED!!
// REMINDER TO CLEAN UP CODE 
// REMINDER TO CHECK FOR UNFREED MEMORY
// REMINDER TO FIX MEMORY LEAKS IF THERE ARE ANY!!

// GTK OPEN FILE

// void 
H_VAR GTK_Openfile_RES(GObject *source_object, GAsyncResult *res,
                      gpointer user_data) {
  GFile *file =
      gtk_file_dialog_open_finish(GTK_FILE_DIALOG(source_object), res, NULL);
  if (file != NULL) {
    gchar *filepath = g_file_get_path(file);
    if (filepath == NULL) {
      g_object_unref(file);
    }

    FILE *FPtr = fopen(filepath, "r");
    if (FPtr == NULL) {
      g_free(filepath);
      g_object_unref(file);
    }

    // GET SIZE
    fseek(FPtr, 0, SEEK_END);
    long buffer_size = ftell(FPtr);
    fseek(FPtr, 0, SEEK_SET);

    char *buffer = (char *)calloc(buffer_size + 1, sizeof(char));
    if (buffer == NULL) {
      fclose(FPtr);
      g_free(filepath);
      g_object_unref(file);
    }

    fread(buffer, buffer_size, sizeof(buffer[0]), FPtr);

    fclose(FPtr);

    // SETTING THE TEXT
    if (text_view == NULL || !GTK_IS_TEXT_VIEW(text_view)) {
      g_print("text_view is invaild!");
      free(buffer);
      g_free(filepath);
      g_object_unref(file);
    }

    GtkTextBuffer *text_view_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(text_view_buffer, buffer, -1);

    if (file_name == NULL || !GTK_IS_LABEL(file_name)) {
      g_print("file_name is invaild!");
      free(buffer);
      g_free(filepath);
      g_object_unref(file);
    }

    gtk_label_set_text(GTK_LABEL(file_name), filepath);

    free(buffer);

    g_free(filepath);
    g_object_unref(file);
  }
}

// void 
H_VAR GTK_Openfile(GtkWidget *widget, gpointer user_data) {

  GtkFileDialog *dialog = gtk_file_dialog_new();
  if (dialog == NULL) {
	  g_print("Failed to create dialog!");
	  return;
  }

  gtk_file_dialog_open(dialog, GTK_WINDOW(user_data), NULL,
                       (GAsyncReadyCallback)GTK_Openfile_RES, NULL);

  g_object_unref(dialog);
}

// GTK SAVE FILE

// void 
H_VAR GTK_Savefile_RES(GObject *source_object, GAsyncResult *res,
                      gpointer user_data) {

  GFile *file =
      gtk_file_dialog_save_finish(GTK_FILE_DIALOG(source_object), res, NULL);
  if (file != NULL) {

    gchar *filepath = g_file_get_path(file);
    if (filepath == NULL) {
      g_object_unref(file);
      return;
    }

    FILE *FPtr = fopen(filepath, "w");
    if (FPtr == NULL) {
      g_free(filepath);
      g_object_unref(file);
      return;
    }

    if (text_view == NULL || !GTK_IS_TEXT_VIEW(text_view)) {
	    fclose(FPtr);
	    g_free(filepath);
	    g_object_unref(file);
	    return;
    }

    // GET TEXT_VIEW TEXT 
    GtkTextIter start, end;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    if (buffer == NULL) {
	    fclose(FPtr);
	    g_free(filepath);
	    g_object_unref(file);
	    return;
    }
    gchar* text;
    gtk_text_buffer_get_bounds (buffer, &start, &end);
    text = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);

    // GETTING FILE SIZE
    fseek(FPtr, 0, SEEK_END);
    long file_size = ftell(FPtr);
    fseek(FPtr, 0, SEEK_SET);

    // PUT TEXT VIEW TEXT INTO THE FILE 
    // DEBUGGING PRINTS 
    // g_print("text_size: %lu\n", sizeof(text));
    // g_print("file_size: %lu\n file_size_value: %lu\n", sizeof(file_size), file_size);
    // g_print("char_size %lu\n gchar_size: %lu", sizeof(char), sizeof(gchar));
    // g_print("text_string_length: %lu\n", strlen(text));
    
    fwrite(text, sizeof(gchar), strlen(text), FPtr);

    // SETTING FILE PATH
    gtk_label_set_text(GTK_LABEL(file_name), filepath);

    fclose(FPtr);
    g_free(filepath);
    g_object_unref(file);
  }
}

// void
H_VAR GTK_Savefile(GtkWidget *widget, gpointer user_data) {

  GtkFileDialog *dialog = gtk_file_dialog_new();
  if (dialog == NULL) {
	  g_print("Failed to create dialog");
	  return;
  }

  gtk_file_dialog_save(dialog, GTK_WINDOW(user_data), NULL,
                       (GAsyncReadyCallback)GTK_Savefile_RES, NULL);

  g_object_unref(dialog);
}
