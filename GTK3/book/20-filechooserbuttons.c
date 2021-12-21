#include <gtk/gtk.h>

static void folder_changed (GtkFileChooser *, GtkFileChooser *);
static void file_changed (GtkFileChooser *, GtkLabel *);

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *chooser1;
    GtkWidget *chooser2;
    GtkWidget *label;
    GtkWidget *vbox;

    GtkFileFilter *filter1;
    GtkFileFilter *filter2;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "File Chooser Button");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    label = gtk_label_new ("");

    chooser1 = gtk_file_chooser_button_new ("Chooser a Folder", GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
    chooser2 = gtk_file_chooser_button_new ("Chooser a Folder", GTK_FILE_CHOOSER_ACTION_OPEN);

    g_signal_connect (G_OBJECT (chooser1), "selection_changed", G_CALLBACK (folder_changed), (gpointer)chooser2);
    g_signal_connect (G_OBJECT (chooser2), "selection_changed", G_CALLBACK (file_changed), (gpointer)label);

    gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER (chooser1), g_get_home_dir());
    gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER (chooser2), g_get_home_dir());

    filter1 = gtk_file_filter_new ();
    filter2 = gtk_file_filter_new ();

    gtk_file_filter_set_name (filter1, "Image Files");
    gtk_file_filter_set_name (filter2, "All Files");

    gtk_file_filter_add_pattern (filter1, "*.png");
    gtk_file_filter_add_pattern (filter1, "*.jpg");
    gtk_file_filter_add_pattern (filter1, "*.gif");

    gtk_file_filter_add_pattern (filter2, "*");

    gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (chooser2), filter1);
    gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (chooser2), filter2);

    vbox = gtk_vbox_new (FALSE, 5);
    gtk_container_add (GTK_CONTAINER (vbox), chooser1);
    gtk_container_add (GTK_CONTAINER (vbox), chooser2);
    gtk_container_add (GTK_CONTAINER (vbox), label);

    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show_all (window);

    gtk_main();

    return 0;
}

static void folder_changed (GtkFileChooser *chooser1, GtkFileChooser *chooser2)
{
    gchar *folder = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (chooser1));
    gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER (chooser2), folder);
}

static void file_changed (GtkFileChooser *chooser2, GtkLabel *label)
{
    gchar *file = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (chooser2));
    gtk_label_set_text (label, file);
}