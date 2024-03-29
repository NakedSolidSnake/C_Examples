#include <gtk/gtk.h>
#include <string.h>

static void entry_changed (GtkEditable *, GtkAssistant *);
static void button_toggled (GtkCheckButton *, GtkAssistant *);
static void button_clicked (GtkButton *, GtkAssistant *);
static void assistant_cancel (GtkAssistant *, gpointer);
static void assistant_close (GtkAssistant *, gpointer);

typedef struct 
{
    GtkWidget *widget;
    gint index;
    const gchar *title;
    GtkAssistantPageType type;
    gboolean complete;
} PageInfo;

int main (int argc, char *argv[])
{
    GtkWidget *assistant;
    GtkWidget *entry;
    GtkWidget *label;
    GtkWidget *button;
    GtkWidget *progress;
    GtkWidget *hbox;

    guint i;

    PageInfo page [5] = 
    {
        { NULL, -1, "Introduction",           GTK_ASSISTANT_PAGE_INTRO,    TRUE},
        { NULL, -1, NULL,                     GTK_ASSISTANT_PAGE_CONTENT,  FALSE},
        { NULL, -1, "Click the Check Button", GTK_ASSISTANT_PAGE_CONTENT,  FALSE},
        { NULL, -1, "Click the Button",       GTK_ASSISTANT_PAGE_PROGRESS, FALSE},
        { NULL, -1, "Confirmation",           GTK_ASSISTANT_PAGE_CONFIRM,  TRUE}
    };

    gtk_init (&argc, &argv);

    assistant = gtk_assistant_new ();
    gtk_widget_set_size_request (assistant, 450, 300);
    gtk_window_set_title (GTK_WINDOW (assistant), "GtkAssistant Example");

    g_signal_connect (G_OBJECT (assistant), "destroy", G_CALLBACK (gtk_main_quit), NULL);

    page[0].widget = gtk_label_new ("This is an example of a GtkAssistant. By\n" \ 
                                    "clicking the forward button, you can continue\n" \
                                    "to the next section");

    page[1].widget = gtk_hbox_new (FALSE, 5);
    page[2].widget = gtk_check_button_new_with_label ("Click Me to Continue!");
    page[3].widget = gtk_alignment_new (0.5, 0.5, 0.0, 0.0);
    page[4].widget = gtk_label_new ("Text has been entered in the label and the\n" \ 
                                    "combo box is clicked. If you are done, then\n" \ 
                                    "it is time to leave!");

    label = gtk_label_new ("Your name: ");
    entry = gtk_entry_new ();
    gtk_box_pack_start (GTK_BOX (page[1].widget), label, FALSE, FALSE, 5);
    gtk_box_pack_start (GTK_BOX (page[1].widget), entry, FALSE, FALSE, 5);

    button = gtk_button_new_with_label ("Click Me!");
    progress = gtk_progress_bar_new ();

    hbox = gtk_hbox_new (FALSE, 5);

    gtk_box_pack_start (GTK_BOX (hbox), progress, TRUE, FALSE, 5);
    gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, FALSE, 5);
    gtk_container_add (GTK_CONTAINER (page[3].widget), hbox);
    g_object_set_data (G_OBJECT (page[3].widget), "pbar", (gpointer) progress);

    for (i = 0; i < 5; i++)
    {
        page[i].index = gtk_assistant_append_page (GTK_ASSISTANT (assistant), page[i].widget);
        gtk_assistant_set_page_title (GTK_ASSISTANT (assistant), page[i].widget, page[i].title);
        gtk_assistant_set_page_type (GTK_ASSISTANT (assistant), page[i].widget, page[i].type);
        gtk_assistant_set_page_complete (GTK_ASSISTANT (assistant), page[i].widget, page[i].complete);
    }

    g_signal_connect (G_OBJECT (entry), "changed", G_CALLBACK (entry_changed), (gpointer) assistant);

    g_signal_connect (G_OBJECT (page[2].widget), "toggled", G_CALLBACK (button_toggled), (gpointer) assistant);
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (button_clicked), (gpointer) assistant);
    g_signal_connect (G_OBJECT (assistant), "cancel", G_CALLBACK (assistant_cancel), (gpointer) NULL);
    g_signal_connect (G_OBJECT (assistant), "close", G_CALLBACK (assistant_close), (gpointer) NULL);

    gtk_widget_show_all (assistant);

    gtk_main ();
    return 0;

}


static void entry_changed (GtkEditable *entry, GtkAssistant *assistant)
{
    const gchar *text = gtk_entry_get_text (GTK_ENTRY (entry));
    gint num = gtk_assistant_get_current_page (assistant);
    GtkWidget *page = gtk_assistant_get_nth_page (assistant, num);

    gtk_assistant_set_page_complete (assistant, page, (strlen (text) > 0));
}

static void button_toggled (GtkCheckButton *toggle, GtkAssistant *assistant)
{
    gboolean active = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (toggle));
    gtk_assistant_set_page_complete (assistant, GTK_WIDGET (toggle), active);
}

static void button_clicked (GtkButton *button, GtkAssistant *assistant)
{
    GtkProgressBar *progress;
    GtkWidget *page;
    gdouble percent = 0.0;
    

    gtk_widget_set_sensitive (GTK_WIDGET (button), FALSE);
    page = gtk_assistant_get_nth_page (assistant, 3);
    progress = GTK_PROGRESS_BAR (g_object_get_data (G_OBJECT (page), "pbar"));

    while (percent <= 100.0)
    {
        gchar *message = g_strdup_printf ("%.0f%% Complete", percent);
        gtk_progress_bar_set_fraction (progress, percent / 100.0);
        gtk_progress_bar_set_text (progress, message);

        while (gtk_events_pending ())
            gtk_main_iteration ();

        g_usleep (500000);
        percent += 5.0;
    }

    gtk_assistant_set_page_complete (assistant, page, TRUE);
}

static void assistant_cancel (GtkAssistant *assistant, gpointer data)
{
    gtk_widget_destroy (GTK_WIDGET (assistant));
}

static void assistant_close (GtkAssistant *assistant, gpointer data)
{
    g_print ("You would apply your changes now!\n");
    gtk_widget_destroy (GTK_WIDGET (assistant));
}
