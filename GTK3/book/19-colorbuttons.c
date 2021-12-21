#include <gtk/gtk.h>
#include <stdio.h>

static void color_changed (GtkColorButton *, GtkWidget *);
static void print_init (GtkColorButton *, GtkWidget *);

int main (int argc, char *argv[])
{

    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *label;
    GtkWidget *hbox;

    GdkColor color;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Color Button");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    gdk_color_parse ("#003366", &color);
    button = gtk_color_button_new_with_color (&color);
    gtk_color_button_set_title (GTK_COLOR_BUTTON (button), "Select a color");

    label = gtk_label_new ("Look at my color!");
    gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &color);

    g_signal_connect (G_OBJECT (button), "color_set", G_CALLBACK (color_changed), (gpointer) label);
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (print_init), (gpointer) label);

    hbox = gtk_hbox_new (FALSE, 5);
    gtk_container_add (GTK_CONTAINER (hbox), button);
    gtk_container_add (GTK_CONTAINER (hbox), label);

    gtk_container_add (GTK_CONTAINER (window), hbox);
    gtk_widget_show_all (window);

    // g_signal_emit (controller, signals[IM_UPDATE], 0);

    
    g_signal_emit_by_name (G_OBJECT (button), "clicked", 0);

    gtk_main();

    return 0;
}


static void color_changed (GtkColorButton *button, GtkWidget *label)
{
    GdkColor color;
    gtk_color_button_get_color (button, &color);
    gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &color);
}

static void print_init (GtkColorButton *button, GtkWidget *label)
{
    printf("Hello World.\n");
}