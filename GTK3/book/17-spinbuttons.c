#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *spin_int;
    GtkWidget *spin_float;
    GtkWidget *vbox;

    GtkAdjustment *integer;
    GtkAdjustment *float_pt;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Spin Buttons");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_widget_set_size_request (window, 150, 100);

    integer = GTK_ADJUSTMENT (gtk_adjustment_new (5.0, 0.0, 10.0, 1.0, 2.0, 2.0));
    float_pt = GTK_ADJUSTMENT (gtk_adjustment_new (0.5, 0.0, 1.0, 0.1, 0.5, 0.5));

    spin_int = gtk_spin_button_new (integer, 1.0, 0);
    spin_float = gtk_spin_button_new (float_pt, 0.1, 1);

    vbox = gtk_vbox_new (FALSE, 5);
    gtk_container_add (GTK_CONTAINER (vbox), spin_int);
    gtk_container_add (GTK_CONTAINER (vbox), spin_float);

    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show_all (window);

    gtk_main();

    return 0;
}