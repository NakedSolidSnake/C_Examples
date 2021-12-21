#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *button;
GtkWidget *label;

void end_program(GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit();
}

void bt_click(GtkWidget *wid, gpointer ptr)
{
    gtk_label_set_text(GTK_LABEL(label), "Hello, world!");
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    button = gtk_button_new_with_label("Set Label");
    label = gtk_label_new("");


    g_signal_connect(button, "clicked", G_CALLBACK(bt_click), NULL);
    g_signal_connect(window, "clicked", G_CALLBACK(end_program), NULL);

    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}