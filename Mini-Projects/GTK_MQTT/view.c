#include "view.h"
#include <string.h>
#include <gtk/gtk.h>

static void view_set_humidity_text (void *object, const char *text);
static void view_set_temperature_text (void *object, const char *text);
static void view_set_state (void *object, bool state);
static void view_run (void *object);
static bool view_load_window (view_t *view);

bool view_init (view_t *view)
{
    bool status = false;

    if (view != NULL)
    {        
        memset (view, 0, sizeof (view_t));

        view->base.object = view;
        view->base.set_humidity_text = view_set_humidity_text;
        view->base.set_temperature_text = view_set_temperature_text;
        view->base.set_state = view_set_state;
        view->base.run = view_run;        

        status = true;
    }

    return status;
}

bool view_open (view_t *view, view_args_t *args)
{
    bool status = false;

    if (view != NULL && args !=NULL)
    {        
        view->controller_base = args->controller_base;
        view->argc            = args->argc;
        view->argv            = args->argv;

        status = view_load_window (view);
    }

    return status;
}

bool view_close (view_t *view)
{
    bool status = false;

    if (view != NULL)
    {
        g_slice_free (widgets_t, view->widgets);

        memset (view, 0, sizeof (view_t));

        status = true;
    }

    return status;
}

static void view_set_humidity_text (void *object, const char *text)
{
    view_t *view = (view_t *)object;
    gtk_entry_set_text (GTK_ENTRY (view->widgets->txt_humidity), text);
}

static void view_set_temperature_text (void *object, const char *text)
{
    view_t *view = (view_t *)object;
    gtk_entry_set_text (GTK_ENTRY (view->widgets->txt_temperature), text);
}

static void view_set_state (void *object, bool state)
{
    view_t *view = (view_t *)object;
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (view->widgets->bt_on_off), state);
}

static void view_run (void *object)
{
    view_t *view = (view_t *)object;
    gtk_widget_show (view->widgets->window);
    gtk_main ();
}

static bool view_load_window (view_t *view)
{
    GtkBuilder *builder;

    view->widgets = g_slice_new (widgets_t);

    gtk_init (&view->argc, &view->argv);

    builder = gtk_builder_new ();

    gtk_builder_add_from_file (builder, "glade/window.glade", NULL);

    view->widgets->window          = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
    view->widgets->txt_humidity    = GTK_WIDGET (gtk_builder_get_object (builder, "txt_humidity"));
    view->widgets->txt_temperature = GTK_WIDGET (gtk_builder_get_object (builder, "txt_temperature"));
    view->widgets->bt_on_off       = GTK_WIDGET (gtk_builder_get_object (builder, "bt_on_off"));

    gtk_builder_connect_signals (builder, view);

    g_object_unref (builder);

    return true;
}

void on_window_destroy (void)
{
    gtk_main_quit ();
}

void on_bt_on_off_toggled (GtkToggleButton *bt_on_off, void *data)
{
    view_t *view = (view_t *)data;
    GtkWidget *label = NULL;
    gboolean enable = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (bt_on_off));

    label = gtk_bin_get_child (GTK_BIN (bt_on_off));
    gtk_label_set_text (GTK_LABEL (label), enable ? "OFF" : "ON");
    
    view->controller_base->on_bt_on_off_toggled (view->controller_base->object, enable);
}