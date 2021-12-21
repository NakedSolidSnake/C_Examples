#include <gtk/gtk.h>

GtkWidget *button;
GtkWidget *label;

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    GtkWidget *window;


    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "glade/main_window.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    gtk_builder_connect_signals(builder, NULL);

    button = GTK_WIDGET(gtk_builder_get_object(builder, "bt_action"));
    label = GTK_WIDGET(gtk_builder_get_object(builder, "lb_action"));

    g_object_unref(builder);

    gtk_widget_show(window);

    gtk_main();

    return 0;
}

void on_window_main_destroy(void)
{
    gtk_main_quit();
}

void on_bt_action_clicked(void)
{
    gtk_label_set_text(GTK_LABEL(label), "Hello, World!");
}