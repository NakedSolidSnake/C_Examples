#include <gtk/gtk.h>

static void font_changed (GtkFontButton *, GtkWidget *);

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *button;
    GtkWidget *label;
    PangoFontDescription *initial_font;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Font Button");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    label = gtk_label_new ("Look at the font");
    initial_font = pango_font_description_from_string ("Sans Bold 12");
    gtk_widget_modify_font (label, initial_font);

    button = gtk_font_button_new_with_font ("Sans Bold 12");
    gtk_font_button_set_title (GTK_FONT_BUTTON (button), "Choose a Font");

    g_signal_connect (G_OBJECT (button), "font_set", G_CALLBACK (font_changed), (gpointer)label);

    vbox = gtk_vbox_new (FALSE, 5);
    gtk_container_add (GTK_CONTAINER (vbox), button);
    gtk_container_add (GTK_CONTAINER (vbox), label);

    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show_all (window);
    

    gtk_main();

    return 0;
}

static void font_changed (GtkFontButton *button, GtkWidget *label)
{
    const gchar *font, buffer[512];
    PangoFontDescription *desc;

    font = gtk_font_button_get_font_name (button);
    desc = pango_font_description_from_string (font);

    g_snprintf (buffer, sizeof(buffer), "Font: %s", font);
    gtk_widget_modify_font (label, desc);
}