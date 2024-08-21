#include "cmain.h"

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv); // Initialize GTK
    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL); // Create window widget
    gtk_widget_show(win); // Show window
    gtk_main(); // Run GTK main loop

    return 0;
}
