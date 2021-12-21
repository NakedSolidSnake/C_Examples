#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *button;

void end_program(GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit();
}

void bt_click(GtkWidget *wid, gpointer ptr)
{    
    gtk_widget_set_size_request(window, 200, 200);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Size control");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    gtk_window_set_resizable(window, TRUE);

    button = gtk_button_new_with_label("Control Window");



    g_signal_connect(button, "clicked", G_CALLBACK(bt_click), NULL);
    g_signal_connect(window, "clicked", G_CALLBACK(end_program), NULL);

    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}