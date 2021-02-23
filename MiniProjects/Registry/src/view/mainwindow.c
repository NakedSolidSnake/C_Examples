#include <view/mainwindow.h>
#include <view/insertwindow.h>
#include <gtk/gtk.h>

#define COLUMNS   3

typedef enum {
    FILE_NAME,
    FILE_ADDRESS,
    FILE_AGE,        
}FILES;

static int _argc = -1;
static char **_argv = NULL;

static GtkListStore      *model;
static GtkWidget         *view;
static GtkTreeViewColumn *columnName;
static GtkTreeViewColumn *columnAddress;
static GtkTreeViewColumn *columnAge;
static GtkWidget         *window;
static GtkWidget         *bt_insert; 
static GtkWidget         *tab;

static void init_components(void);
static void register_signals(void);
static void end_program(GtkWidget *wid, gpointer ptr);
static void load_insertwindow(GtkWidget *wid, gpointer ptr);
static void update(void);


void mainwindow_load(int argc, char *argv[])
{
    _argc = argc;
    _argv = argv;

    gtk_init(&argc, &argv);

    init_components();

    register_signals();    
    
    gtk_main ();
}

void set_new_item(const char *name, const char *address, const int age)
{
    gtk_list_store_insert_with_values(model,
                                      NULL,
                                      -1,
                                      FILE_NAME, name,
                                      FILE_ADDRESS, address,
                                      FILE_AGE, age,
                                      -1);

    update();
}

static void init_components(void)
{
    /* MODEL                   AMOUNT       NAME           ADDRESS        AGE   */
    model = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_UINT);

     /* VIEW */
    view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(model));
    g_object_unref(model);

    /* Add columns to the tree */
     columnName = gtk_tree_view_column_new_with_attributes("Name",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", FILE_NAME,                                                      
                                                      NULL);    

    columnAddress = gtk_tree_view_column_new_with_attributes("Address",
                                                      gtk_cell_renderer_spin_new(),
                                                      "text", FILE_ADDRESS,
                                                      NULL);
    
    columnAge = gtk_tree_view_column_new_with_attributes("Age",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", FILE_AGE,
                                                      NULL);

    gtk_tree_view_append_column(GTK_TREE_VIEW(view), columnName);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), columnAddress);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), columnAge);

    bt_insert = gtk_button_new_with_label("Insert"); 

    tab = gtk_table_new(2, 2, TRUE);
    gtk_table_set_homogeneous (tab, (gboolean) 1);
    gtk_table_attach_defaults(GTK_TABLE(tab), view, 0,2,0,1);
    gtk_table_attach_defaults(GTK_TABLE(tab), bt_insert, 1,2,1,2);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_add(GTK_CONTAINER(window), tab);
    gtk_widget_show_all(window);
}

static void end_program(GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit();
}

static void register_signals(void)
{
    g_signal_connect(window, "delete_event", G_CALLBACK(end_program), NULL);
    g_signal_connect(bt_insert, "clicked", G_CALLBACK(load_insertwindow), NULL);
}

static void load_insertwindow(GtkWidget *wid, gpointer ptr)
{
    insert_window_load(&_argc, &_argv);
}

static void update(void)
{
   gtk_tree_view_set_model(GTK_TREE_VIEW(view), NULL); 
   gtk_tree_view_set_model(GTK_TREE_VIEW(view), model);
}