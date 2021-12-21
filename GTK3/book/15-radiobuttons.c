#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *radio1;
    GtkWidget *radio2;
    GtkWidget *radio3;
    GtkWidget *radio4;
    GSList *group = NULL;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Radio Buttons");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    radio1 = gtk_radio_button_new_with_label (group, "I want be clicked!");
    gtk_radio_button_set_group (GTK_RADIO_BUTTON (radio1), group);

    radio2 = gtk_radio_button_new_with_label (NULL, "Click Me instead!");
    gtk_radio_button_join_group(GTK_RADIO_BUTTON (radio2), GTK_RADIO_BUTTON (radio1));

    radio3 = gtk_radio_button_new_with_label (NULL, "No! Click me!");
    gtk_radio_button_join_group(GTK_RADIO_BUTTON (radio3), GTK_RADIO_BUTTON (radio1));
    radio4 = gtk_radio_button_new_with_label (NULL, "No! Click me instead!");
    gtk_radio_button_join_group(GTK_RADIO_BUTTON (radio4), GTK_RADIO_BUTTON (radio1));

    vbox = gtk_vbox_new (FALSE, 5);

    gtk_container_add (GTK_CONTAINER (vbox), radio1);
    gtk_container_add (GTK_CONTAINER (vbox), radio2);
    gtk_container_add (GTK_CONTAINER (vbox), radio3);
    gtk_container_add (GTK_CONTAINER (vbox), radio4);

    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show_all (window);


    gtk_main();

    return 0;
}