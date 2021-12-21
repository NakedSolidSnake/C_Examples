#include <gtk/gtk.h>


static GtkWidget *create_window(const char *title, const int width, const int height, const int border_width)
{
    GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    if(window)
    {
        gtk_window_set_title (GTK_WINDOW (window), title);
        gtk_container_set_border_width( GTK_CONTAINER (window), border_width);
        gtk_widget_set_size_request (window, width, height);
    }

    return window;
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *label1;
    GtkWidget *label2;
    GtkWidget *name;

    

    gtk_init(&argc, &argv);

    window = create_window("Tables", 150, 100, 10);

    table = gtk_table_new (2, 2, TRUE);
    label1 = gtk_label_new ("Enter the following information...");
    label2 = gtk_label_new ("Name: ");
    name = gtk_entry_new ();

    gtk_table_attach (GTK_TABLE (table), label1, 0, 2, 0, 1, GTK_EXPAND, GTK_SHRINK, 5, 5);
    gtk_table_attach (GTK_TABLE (table), label2, 0, 1, 1, 2, GTK_EXPAND, GTK_SHRINK, 5, 5);
    gtk_table_attach (GTK_TABLE (table), name, 1, 2, 1, 2, GTK_EXPAND, GTK_SHRINK, 5, 5);

    gtk_table_set_row_spacings (GTK_TABLE (table), 5);
    gtk_table_set_col_spacings (GTK_TABLE (table), 5);

    gtk_container_add (GTK_CONTAINER (window), table);
    gtk_widget_show_all (window);

    gtk_main();
    return 0;
}