#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    // builder = gtk_builder_new();
    // gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
    // Update October 2019: The line below replaces the 2 lines above
    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_rb_1_toggled(GtkToggleButton *toggleButton, GtkLabel *label)
{
    gtk_label_set_text(label, "1%");
}

void on_rb_2_toggled(GtkToggleButton *toggleButton, GtkLabel *label)
{
    gtk_label_set_text(label, "2%");
}

void on_rb_3_toggled(GtkToggleButton *toggleButton, GtkLabel *label)
{
    gtk_label_set_text(label, "5%");
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}