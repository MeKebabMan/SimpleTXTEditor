#include "_headers_.h"

int main(int argc, char **argv) {
  return CreateGTKAPP("com.TextEditor.SimpleTextEditor",
                      _FUNC(activate_GTK_APP), argc, argv);
}
