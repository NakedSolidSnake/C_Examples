#include <gtk/gtk.h>

static void run_color_selection_dialog (GtkButton *, GtkWindow *, gboolean);
static void modal_clicked (GtkButton *, GtkWindow *);
static void nonmodal_clicked (GtkButton *, GtkWindow *);
static void dialog_response (GtkDialog *, gint, gpointer);

static GdkColor global_color;
static guint global_alpha = 65535;

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *hbox;
    GtkWidget *modal;
    GtkWidget *nonmodal;
    gint i;

    gtk_init (&argc, &argv);

    for (i = 0; i < argc; i++)
        if (gdk_color_parse (argv[i], &global_color))
            break;

    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Color Selection Dialogs");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_widget_set_size_request (window, 200, 75);

    modal = gtk_button_new_with_label ("Modal");
    nonmodal = gtk_button_new_with_label ("Non-Modal");

    g_signal_connect (G_OBJECT (modal), "clicked", G_CALLBACK (modal_clicked), (gpointer)window);
    g_signal_connect (G_OBJECT (nonmodal), "clicked", G_CALLBACK (nonmodal_clicked), (gpointer)window);

    hbox = gtk_hbox_new (TRUE, 10);
    gtk_container_add (GTK_CONTAINER (hbox), modal);
    gtk_container_add (GTK_CONTAINER (hbox), nonmodal);

    gtk_container_add (GTK_CONTAINER (window), hbox);
    gtk_widget_show_all (window);

    gtk_main();

    return 0;
}


static void run_color_selection_dialog (GtkButton *button, GtkWindow *window, gboolean domodal)
{
    GtkWidget *dialog;
    GtkWidget *colorsel;
    gchar *title;

    if (domodal)
        title = "Choose Color -- Modal";
    else 
        title = "Choose Color -- Non-Modal";

    dialog = gtk_color_selection_dialog_new (title);
    gtk_window_set_modal (GTK_WINDOW (dialog), domodal);

    colorsel = GTK_COLOR_SELECTION_DIALOG (dialog)->colorsel;
    gtk_color_selection_set_has_opacity_control (GTK_COLOR_SELECTION (colorsel), TRUE);

    gtk_color_selection_set_current_color (GTK_COLOR_SELECTION (colorsel), &global_color);
    gtk_color_selection_set_current_alpha (GTK_COLOR_SELECTION (colorsel), global_color);

    g_signal_connect (G_OBJECT (dialog), "response", G_CALLBACK (dialog_response), NULL);

    gtk_widget_show_all (dialog);
}

static void modal_clicked (GtkButton *button, GtkWindow *window)
{
    run_color_selection_dialog (button, window, TRUE);
}

static void nonmodal_clicked (GtkButton *button, GtkWindow *window)
{
    run_color_selection_dialog (button, window, FALSE);
}

static void dialog_response (GtkDialog *dialog, gint result, gpointer data)
{
    GtkWidget *colorsel;
    GdkColor color = {0,};
    guint16 alpha = 0;

    switch (result)
    {
        case GTK_RESPONSE_HELP:
            g_print ("Read the GTK+ API documentation.\n");
            break;

        case GTK_RESPONSE_OK:
            colorsel = GTK_COLOR_SELECTION_DIALOG (dialog)->colorsel;
            alpha = gtk_color_selection_get_current_alpha (GTK_COLOR_SELECTION (colorsel));
            gtk_color_selection_get_current_color (GTK_COLOR_SELECTION (colorsel), &color);

            g_print ("#%04X%04X%04X%04X\n", color.red, color.green, color.blue, alpha);

            global_color = color;
            global_alpha = alpha;

        default:
            gtk_widget_destroy (GTK_WIDGET (dialog));
    }
}