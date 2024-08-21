/******************************************************************************
 * \file cmain.c
 ******************************************************************************/
#include "cmain.h"

// Global initializations
// Primitive and basic types
uint Count = 0;
// GTK and complex types
GtkWidget *Txt = NULL;
GtkWidget *Spn_Box = NULL;

/******************************************************************************
 * @fn     int main(int argc, char *argv[])
 * @brief  Main function loop.
 * @param  argc Number of command line arguments.
 * @param  argv Array of command line argument strings.
 * @retval retval Error code, otherwise 0 when exits normally.
 ******************************************************************************/
int main(int argc, char *argv[])
{
    // Local initializations
    int retval = 0;
    
    /* ---- Initialize GTK ---- */

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create window widget
    GtkWidget *win_main = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Create label widgets
    GtkWidget *lbl_clk = gtk_label_new("Click my button");
    GtkWidget *lbl_input = gtk_label_new("Type in the textbox and replace me");

    // Create button widgets
    GtkWidget *btn_clk = gtk_button_new_with_label("Click me!");
    GtkWidget *btn_exit = gtk_button_new_with_label("Close");
    GtkWidget *btn_cpy = gtk_button_new_with_label("Copy input text");

    // Create radio button widgets
    // GtkWidget *radio1 = gtk_radio_button_new_with_label(NULL, "This");
    // GtkWidget *radio2 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio1), "That");

    // Create check button widgets
    // GtkWidget *check1 = gtk_check_button_new_with_label("This");
    // GtkWidget *check2 = gtk_check_button_new_with_label("That");

    // Create text entry widget
    // Txt = gtk_entry_new();

    // Create adjustment object
    // GtkObject *adj = gtk_adjustment_new(0, -100, 100, 1, 0, 0);
    // Create spin button widget
    // Spn_Box = gtk_spin_button_new(GTK_ADJUSTMENT(adj), 0, 0);

    // Create combo box widget
    // GtkWidget *combo_box = gtk_combo_box_text_new();
    // gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "Opt 1");
    // gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "Opt 2");
    // gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), "Opt 3");
    // gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box), 0);

    // Create vertical and horizontal box widgets (containers)
    // GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
    // GtkWidget *hbox = gtk_hbox_new(FALSE, 5);

    // Create table widgets (containers)
    GtkWidget *tbl = gtk_table_new(4, 3, TRUE);

    /* ---- Connect callbacks ---- */

    // Connect exit callback to window's delete event
    g_signal_connect(win_main, "delete_event", G_CALLBACK(end_program), NULL);
    // Count callback to btn_clk, lbl_clk as argument to callback
    g_signal_connect(btn_clk, "clicked", G_CALLBACK(count_button), lbl_clk);
    // Exit callback to btn_exit, no argument to callback
    g_signal_connect(btn_exit, "clicked", G_CALLBACK(end_program), NULL);
    // Copy callback to btn_cpy, lbl_input as argument to callback
    g_signal_connect(btn_cpy, "clicked", G_CALLBACK(copy_text_entry), lbl_input);

    /* ---- Set up layout ---- */

    // Table with label widget
    // gtk_table_attach_defaults(GTK_TABLE(tbl), lbl_clk, 0, 1, 0, 1);

    // Boxes with label widget
    // gtk_box_pack_start(GTK_BOX(hbox), btn_clk, TRUE, TRUE, 0);
    // gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    gtk_table_attach_defaults(GTK_TABLE(tbl), combo_box, 0, 3, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(tbl), lbl_input, 0, 3, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(tbl), lbl_clk, 0, 3, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(tbl), btn_cpy, 0, 1, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(tbl), btn_clk, 1, 2, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(tbl), btn_exit, 2, 3, 3, 4);

    // Add box to window. Windows can only have one widget.
    gtk_container_add(GTK_CONTAINER(win_main), tbl);

    // Show window container and everything in it
    gtk_widget_show_all(win_main);

    // Run GTK main loop
    gtk_main();

    return retval;
}

/******************************************************************************
 * Callbacks and Helpers
 ******************************************************************************/

/******************************************************************************
 * @fn void count_button(GtkWidget *btn, gpointer lbl)
 ******************************************************************************/
void count_button(GtkWidget *btn, gpointer lbl)
{
    char buffer[30];
    Count++;
    sprintf(buffer, "Button clicked %d times", Count);
    gtk_label_set_text(GTK_LABEL(lbl), buffer); // Update label's text
}

/******************************************************************************
 * @fn void copy_text_entry(GtkWidget *btn, gpointer lbl)
 ******************************************************************************/
void copy_text_entry(GtkWidget *btn, gpointer lbl)
{
    const char *usr_in = "0";

    if (Spn_Box != NULL)
    {
        usr_in = gtk_entry_get_text(GTK_ENTRY(Spn_Box));
    }
    else if (Txt != NULL)
    {
        usr_in = gtk_entry_get_text(GTK_ENTRY(Txt));
    }
    gtk_label_set_text(GTK_LABEL(lbl), usr_in);
}

/******************************************************************************
 * @fn void end_program(GtkWidget *wid, gpointer ptr)
 ******************************************************************************/
void end_program(GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit(); // Exit GTK's main loop
}
