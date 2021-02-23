#include <gtk/gtk.h>

enum {
    FILE_NAME,
    FILE_OFFSET,
    FILE_SIZE,
    FILE_DESCRIPTION, /* Not used by the view, maybe used elsewhere */
    COLOR,            /* Just to show how the model can affect the view */
    N_COLUMNS
};

gint main(gint argc, gchar **argv)
{
    GtkListStore*      model;
    GtkWidget*         view;
    GtkTreeViewColumn* column;
    GtkWidget*         window;

    gtk_init(&argc, &argv);

    /* MODEL */
    model = gtk_list_store_new(N_COLUMNS,
                               G_TYPE_STRING,   /* FILE_NAME */
                               G_TYPE_UINT,     /* FILE_OFFSET */
                               G_TYPE_UINT,     /* FILE_SIZE */
                               G_TYPE_STRING,   /* FILE_DESCRIPTION */
                               G_TYPE_STRING    /* COLOR */
                              );
    gtk_list_store_insert_with_values(model, NULL, -1,
                                      FILE_NAME, "test name",
                                      FILE_OFFSET, 0,
                                      FILE_SIZE, 10,
                                      -1);
    gtk_list_store_insert_with_values(model, NULL, -1,
                                      FILE_NAME, "Dummy",
                                      FILE_OFFSET, 123,
                                      COLOR, "black",
                                      -1);
    gtk_list_store_insert_with_values(model, NULL, -1,
                                      COLOR, "blue",
                                      -1);

    gtk_list_store_insert_with_values(model, NULL, -1,
                                      FILE_DESCRIPTION, "blue",
                                      -1);

    /* VIEW */
    view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(model));
    g_object_unref(model);

    column = gtk_tree_view_column_new_with_attributes("Name",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", FILE_NAME,
                                                      "background", COLOR,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    column = gtk_tree_view_column_new_with_attributes("Offset",
                                                      gtk_cell_renderer_spin_new(),
                                                      "text", FILE_OFFSET,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    column = gtk_tree_view_column_new_with_attributes("Size",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", FILE_SIZE,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    /* MAIN */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_add(GTK_CONTAINER(window), view);
    gtk_widget_show_all(window);

    gtk_main ();

    return 0;
}