#include <gtk/gtk.h>

GtkWidget *txt;

void end_program(GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit();
}

void copy_text(GtkWidget *wid, gpointer ptr)
{
    const char *input = gtk_entry_get_text(GTK_ENTRY(txt));
    gtk_label_set_text(GTK_LABEL(ptr), input);
}

void check_toggle(GtkWidget *wid, gpointer ptr)
{
    printf ("The state of the button is %d\n",
            gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (wid)));
}

void check_combo_box(GtkWidget *wid, gpointer ptr)
{
    int sel = gtk_combo_box_get_active(GTK_COMBO_BOX(wid));
    char *selected = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(wid));
    printf("selected : %d; text: %s\n", sel, selected);
}

int main(int argc, char const *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    GtkWidget *btn = gtk_button_new_with_label("Close window");

    g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
    g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);

    GtkWidget *lbl = gtk_label_new("My label");

    GtkWidget *btn2 = gtk_button_new_with_label("Copy Button");
    g_signal_connect(btn2, "clicked", G_CALLBACK(copy_text), lbl);

    // GtkWidget *chk = gtk_check_button_new_with_label("My Check");
    // g_signal_connect(chk, "toggled", G_CALLBACK(check_toggle), NULL);
    //set to active state
    // gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(chk), TRUE);

    GtkWidget *rad1 = gtk_radio_button_new_with_label(NULL, "Button 1");

    GSList *group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(rad1));

    GtkWidget *rad2 = gtk_radio_button_new_with_label(group, "Button 2");

    // gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rad2), TRUE);

    GtkWidget *comb = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 1");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 2");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 3");
    g_signal_connect(comb, "changed", G_CALLBACK(check_combo_box), NULL);
    gtk_combo_box_set_active(GTK_COMBO_BOX(comb), 0);
    

    //get state
    //int state = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (chk));

    // txt = gtk_entry_new();
    GtkObject *adj = gtk_adjustment_new(0, -10, 10, 1, 0, 0);
    txt = gtk_spin_button_new(GTK_ADJUSTMENT(adj), 0, 0);

    GtkWidget *tab = gtk_table_new(2, 2, TRUE);

    // gtk_table_attach_defaults(GTK_TABLE(tab), lbl, 0,1,0,1);
    gtk_table_attach_defaults(GTK_TABLE(tab), rad1, 0,1,0,1);
    // gtk_table_attach_defaults(GTK_TABLE(tab), btn2, 1,2,0,1);
    // gtk_table_attach_defaults(GTK_TABLE(tab), group, 1,2,0,1);
    gtk_table_attach_defaults(GTK_TABLE(tab), rad2, 1,2,0,1);
    gtk_table_attach_defaults(GTK_TABLE(tab), btn, 0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(tab), txt, 1,2,1,2);
    // gtk_table_attach_defaults(GTK_TABLE(tab), comb, 1,2,1,2);

    gtk_container_add(GTK_CONTAINER(win), tab);
    gtk_widget_show_all(win);

    gtk_main();
    

    return 0;
}
