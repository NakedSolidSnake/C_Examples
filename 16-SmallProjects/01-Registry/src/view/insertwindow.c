#include <view/insertwindow.h>
#include <gtk/gtk.h>


static void init_components(void);
static void register_signals(void);
static void end_program(GtkWidget *wid, gpointer ptr);
static void get_data_fields(GtkWidget *wid, gpointer ptr);




GtkWidget *window; 
GtkWidget *bt_submit; 
GtkWidget *txt_name;
GtkWidget *txt_address;
GtkWidget *sp_age;
GtkWidget *lbl_name;
GtkWidget *lbl_address;
GtkWidget *lbl_age;
GtkWidget *tab;


void insert_window_load(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    init_components();

    register_signals();

    gtk_main();

}


/*
    +-------+-------------+
    | label |  txt_name   |
    +-------+-------------+
    | label | txt_address |
    +-------+-------------+
    | label |     age     |
    +-------+-------------+
    |       |    button   |
    +-------+-------------+
*/

static void init_components(void)
{
    GtkObject *range = gtk_adjustment_new(0, 0, 120, 1, 0, 0);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    bt_submit = gtk_button_new_with_label("Submit"); 
    txt_name = gtk_entry_new();
    txt_address = gtk_entry_new();
    sp_age = gtk_spin_button_new(GTK_ADJUSTMENT(range), 0, 0);
    lbl_name = gtk_label_new("Name: ");
    lbl_address = gtk_label_new("Address: ");
    lbl_age = gtk_label_new("Age: ");

    tab = gtk_table_new(2, 2, TRUE);

    gtk_table_attach_defaults(GTK_TABLE(tab), lbl_name, 0,1,0,1);
    gtk_table_attach_defaults(GTK_TABLE(tab), txt_name, 1,2,0,1);

    gtk_table_attach_defaults(GTK_TABLE(tab), lbl_address, 0,1,1,2);
    gtk_table_attach_defaults(GTK_TABLE(tab), txt_address, 1,2,1,2);

    gtk_table_attach_defaults(GTK_TABLE(tab), lbl_age, 0,1,2,3);
    gtk_table_attach_defaults(GTK_TABLE(tab), sp_age, 1,2,2,3);

    gtk_table_attach_defaults(GTK_TABLE(tab), bt_submit, 1,2,3,4);

    gtk_container_add(GTK_CONTAINER(window), tab);
    gtk_widget_show_all(window);
}

static void register_signals(void)
{
    g_signal_connect(window, "delete_event", G_CALLBACK(end_program), NULL);
    g_signal_connect(bt_submit, "clicked", G_CALLBACK(get_data_fields), NULL);
}

static void end_program(GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit();
}

static void get_data_fields(GtkWidget *wid, gpointer ptr)
{
    char *name = (char *)gtk_entry_get_text(GTK_ENTRY(txt_name));
    char *address = (char *)gtk_entry_get_text(GTK_ENTRY(txt_address));
    int age = atoi(gtk_entry_get_text(GTK_ENTRY(sp_age)));

    printf("name: %s\naddress: %s\nage: %d\n", name, address, age);
  
}