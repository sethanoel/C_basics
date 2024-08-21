#include "cmain.h"

// Initializations
uint Count = 0;

// Main
int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv); // Initialize GTK

    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL); // Create window widget
    g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL); // Connect callback to window

    GtkWidget *lbl = gtk_label_new("Press my button"); // Create label widget

    GtkWidget *btn1 = gtk_button_new_with_label("Click me!"); // Create button widget
    g_signal_connect(btn1, "clicked", G_CALLBACK(count_button), lbl); // Connect callback to button and add label as argument to callback
    GtkWidget *btn2 = gtk_button_new_with_label("Close Window");
    g_signal_connect(btn2, "clicked", G_CALLBACK(end_program), NULL);

    GtkWidget *tbl = gtk_table_new(2, 2, TRUE); // Create table widget
    gtk_table_attach_defaults(GTK_TABLE(tbl), lbl, 0, 2, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(tbl), btn1, 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(tbl), btn2, 1, 2, 1, 2);

    // GtkWidget *vbox = gtk_vbox_new(FALSE, 5); // Create vertical box widget (container)
    // GtkWidget *hbox = gtk_hbox_new(FALSE, 5); // Create horizontal box widget (container)
    // gtk_box_pack_start(GTK_BOX(hbox), btn1, TRUE, TRUE, 0);
    // gtk_box_pack_start(GTK_BOX(hbox), btn2, TRUE, TRUE, 0);
    // gtk_box_pack_start(GTK_BOX(vbox), lbl, TRUE, TRUE, 0);
    // gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(win), vbox); // Add box to window. Windows can only have one widget, boxes can have unlimitted.

    gtk_widget_show_all(win); // Show window container and everything in it

    gtk_main(); // Run GTK main loop

    return 0;
}

// Callbacks and Helpers
void count_button(GtkWidget *btn, gpointer ptr)
{
    char buffer[30];
    Count++;
    sprintf(buffer, "Button clicked %d times", Count);
    gtk_label_set_text(GTK_LABEL(ptr), buffer); // Update label's text
}

void end_program(GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit(); // Quit GTK
}
