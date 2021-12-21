#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *hbox;
    GtkWidget *question;
    GtkWidget *label;
    GtkWidget *pass;
    char *str;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Password");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    str = g_strconcat ("What is the password for ", g_get_user_name(), "?", NULL);
    question = gtk_label_new (str);
    label = gtk_label_new ("Password:");

    pass = gtk_entry_new ();
    gtk_entry_set_visibility (GTK_ENTRY (pass), FALSE);
    gtk_entry_set_invisible_char (GTK_ENTRY (pass), "*");

    hbox = gtk_hbox_new (FALSE, 5);
    gtk_container_add (GTK_CONTAINER (hbox), label);
    gtk_container_add (GTK_CONTAINER (hbox), pass);

    vbox = gtk_vbox_new (FALSE, 5);
    gtk_container_add (GTK_CONTAINER (vbox), question);
    gtk_container_add (GTK_CONTAINER (vbox), hbox);

    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show_all (window);

    gtk_main();
    return 0;
}