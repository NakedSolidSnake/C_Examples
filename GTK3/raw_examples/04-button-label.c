#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *button;
GtkWidget *label; 

void end_program(GtkWidget *w, gpointer p)
{
    gtk_main_quit();
}

void button_set_text(GtkWidget *w, gpointer p)
{
    gtk_label_set_text(GTK_LABEL(label), "Hello World");
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    button = gtk_button_new_with_label("Press");
    label  = gtk_label_new("");

    g_signal_connect(button, "clicked", G_CALLBACK(button_set_text), NULL);
    g_signal_connect(window, "delete_event", G_CALLBACK(end_program), NULL);

    GtkWidget *box = gtk_hbox_new(FALSE, 3);
    gtk_box_pack_start (GTK_BOX(box), button, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(box), label, TRUE, TRUE, 0);
    gtk_container_add (GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);

    gtk_main();
}