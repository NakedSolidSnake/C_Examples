#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *scale_int;
    GtkWidget *scale_float;
    GtkWidget *vbox;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Scales");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_widget_set_size_request (window, 250, -1);

    scale_int = gtk_hscale_new_with_range (0.0, 10.0, 1.0);
    scale_float = gtk_hscale_new_with_range (0.0, 1.0, 0.1);

    gtk_scale_set_digits (GTK_SCALE (scale_int), 0);
    gtk_scale_set_digits (GTK_SCALE (scale_float), 1);

    gtk_scale_set_value_pos (GTK_SCALE (scale_int), GTK_POS_RIGHT);
    gtk_scale_set_value_pos (GTK_SCALE (scale_float), GTK_POS_LEFT);

    vbox = gtk_vbox_new (FALSE, 5);
    gtk_container_add (GTK_BOX (vbox), scale_int);
    gtk_container_add (GTK_BOX (vbox), scale_float);

    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show_all (window);

    gtk_main ();

    return 0;
}