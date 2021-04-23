#include <gtk/gtk.h>

typedef struct {
    GtkWidget *w_lbl_time;
} app_widgets;

gboolean timer_handler(app_widgets *widgets);

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
    app_widgets        *widgets = g_slice_new(app_widgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    widgets->w_lbl_time  = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_time"));
    gtk_builder_connect_signals(builder, widgets);
    g_object_unref(builder);
    
    // start 1 second timer
    g_timeout_add_seconds(1, (GSourceFunc)timer_handler, widgets);

    gtk_widget_show(window);                
    gtk_main();
    g_slice_free(app_widgets, widgets);

    return 0;
}

// handler for the 1 second timer tick
gboolean timer_handler(app_widgets *widgets)
{
    GDateTime *date_time;
    gchar *dt_format;

    date_time = g_date_time_new_now_local();                        // get local time
    dt_format = g_date_time_format(date_time, "%H:%M:%S");            // 24hr time format
    gtk_label_set_text(GTK_LABEL(widgets->w_lbl_time), dt_format);    // update label
    g_free (dt_format);
    
    return TRUE;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}