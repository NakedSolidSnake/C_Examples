#include <gtk/gtk.h>

static void button_clicked (GtkButton *, GtkWindow *);

int main (int argc, char * argv[])
{
    GtkWidget *window;
    GtkWidget *button;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Save a file");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_widget_set_size_request (window,  200, 100);

    button = gtk_button_new_with_label ("Save As ...");

    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (button_clicked), (gpointer)window);

    gtk_container_add (GTK_CONTAINER (window), button);
    gtk_widget_show_all (window);

    gtk_main ();
    return 0;
}

static void button_clicked (GtkButton *button, GtkWindow *window)
{
    GtkWidget *dialog;
    gchar *filename;

    dialog = gtk_file_chooser_dialog_new ("Save File as ...", 
                                          window,
                                          GTK_FILE_CHOOSER_ACTION_SAVE,
                                          GTK_STOCK_CANCEL,
                                          GTK_RESPONSE_CANCEL,
                                          GTK_STOCK_SAVE,
                                          GTK_RESPONSE_ACCEPT,
                                          NULL);

    gint result = gtk_dialog_run (GTK_DIALOG (dialog));
    if(result == GTK_RESPONSE_ACCEPT)
    {
        filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
        gtk_button_set_label (button, filename);
    }

    gtk_widget_destroy (dialog);
}