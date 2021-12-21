#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *table;
    GtkWidget *user;
    GtkWidget *real;
    GtkWidget *home;
    GtkWidget *host;
    GtkWidget *lbl1;
    GtkWidget *lbl2;
    GtkWidget *lbl3;
    GtkWidget *lbl4;
    int result;

    gtk_init (&argc, &argv);

    dialog = gtk_dialog_new_with_buttons ("Edit User Information",
                                          NULL,
                                          GTK_DIALOG_MODAL,
                                          GTK_STOCK_OK,
                                          GTK_RESPONSE_OK,
                                          GTK_STOCK_CANCEL,
                                          GTK_RESPONSE_CANCEL,
                                          NULL);

    gtk_dialog_set_default_response (GTK_DIALOG (dialog), GTK_RESPONSE_OK);

    lbl1 = gtk_label_new ("User Name: ");
    lbl2 = gtk_label_new ("Real Name: ");
    lbl3 = gtk_label_new ("Home Dir: ");
    lbl4 = gtk_label_new ("Host Name: ");

    user = gtk_entry_new ();
    real = gtk_entry_new ();
    home = gtk_entry_new ();
    host = gtk_entry_new ();

    table = gtk_table_new (4, 2, FALSE);
    gtk_table_attach_defaults (GTK_TABLE (table), lbl1, 0, 1, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE (table), lbl2, 0, 1, 1, 2);
    gtk_table_attach_defaults (GTK_TABLE (table), lbl3, 0, 1, 2, 3);
    gtk_table_attach_defaults (GTK_TABLE (table), lbl4, 0, 1, 3, 4);

    gtk_table_attach_defaults (GTK_TABLE (table), user, 1, 2, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE (table), real, 1, 2, 1, 2);
    gtk_table_attach_defaults (GTK_TABLE (table), home, 1, 2, 2, 3);
    gtk_table_attach_defaults (GTK_TABLE (table), host, 1, 2, 3, 4);

    gtk_table_set_row_spacings (GTK_TABLE (table), 5);
    gtk_table_set_col_spacings (GTK_TABLE (table), 5);
    gtk_container_set_border_width (GTK_CONTAINER (table), 5);

    content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
    gtk_container_add (GTK_CONTAINER (content_area), table);

    gtk_widget_show_all (dialog);

    result = gtk_dialog_run (GTK_DIALOG (dialog));

    switch (result)
    {
        case GTK_RESPONSE_OK:
            g_print ("User Name: %s\n", gtk_entry_get_text (GTK_ENTRY (user)));
            g_print ("Real Name: %s\n", gtk_entry_get_text (GTK_ENTRY (real)));
            g_print ("Home Folder: %s\n", gtk_entry_get_text (GTK_ENTRY (home)));
            g_print ("Host Name: %s\n", gtk_entry_get_text (GTK_ENTRY (host)));

            break;

        case GTK_RESPONSE_APPLY:
            break;

        default:
            break; 
    }

    gtk_widget_destroy (dialog);

    return 0;
}