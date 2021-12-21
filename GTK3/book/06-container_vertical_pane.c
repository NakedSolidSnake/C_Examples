#include <gtk/gtk.h>

int main(int argc, char *argv[])
{

    GtkWidget *window;
    GtkWidget *vpaned;
    GtkWidget *button1;
    GtkWidget *button2;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Panes");

    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_widget_set_size_request (window, 225, 150);

    vpaned = gtk_vpaned_new();
    button1 = gtk_button_new_with_label ("Resize");
    button2 = gtk_button_new_with_label ("ME");

    g_signal_connect_swapped (G_OBJECT (button1), "clicked", G_CALLBACK (gtk_widget_destroy), (gpointer)window);
    g_signal_connect_swapped (G_OBJECT (button2), "clicked", G_CALLBACK (gtk_widget_destroy), (gpointer)window);

    gtk_paned_add1 (GTK_PANED (vpaned), button1);
    gtk_paned_add2 (GTK_PANED (vpaned), button2);

    gtk_container_add (GTK_CONTAINER (window), vpaned);
    gtk_widget_show_all (window);

    gtk_main();
    return 0;
}