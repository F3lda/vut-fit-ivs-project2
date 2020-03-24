#include <gtk/gtk.h>

#define FILE_UI			"calculator_ui.glade"
#define WIDGET_WINDOW	"mainWindow"


/*
** App is finished. Clean up everything.
*********************************************************/
void on_window_destroy(GtkWidget *widget, gpointer user_data)
{
	g_print("Done.\n");
}

/*
** When closing window
*********************************************************/
int on_window_close(GtkWidget *widget, gpointer user_data)
{
	//return TRUE;	// Returning TRUE stops the window being deleted.
	return FALSE;	// Returning FALSE allows deletion.   
}

/*
** When key is pressed
*********************************************************/
void on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
	char buffer[100];
	sprintf(buffer, "%u", event->keyval);
	g_print("Key pressed: %s\n",buffer);
}

/*
** When key is released
*********************************************************/
void on_key_release(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
	char buffer[100];
	sprintf(buffer, "%u", event->keyval);
	g_print("Key pressed: %s\n",buffer);
}

/*
** Show question dialog
*********************************************************/
int show_question(char *title, char *message, GtkApplication *app)
{
/*
	GTK_RESPONSE_NONE         = -1,
	GTK_RESPONSE_REJECT       = -2,
	GTK_RESPONSE_ACCEPT       = -3,
	GTK_RESPONSE_DELETE_EVENT = -4,
	GTK_RESPONSE_OK           = -5,
	GTK_RESPONSE_CANCEL       = -6,
	GTK_RESPONSE_CLOSE        = -7,
	GTK_RESPONSE_YES          = -8,
	GTK_RESPONSE_NO           = -9,
	GTK_RESPONSE_APPLY        = -10,
	GTK_RESPONSE_HELP         = -11
*/
	GtkWindow *parentWindow = gtk_application_get_active_window(app);
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(parentWindow,
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_QUESTION,
		GTK_BUTTONS_YES_NO,
		"%s", message);
	gtk_window_set_title(GTK_WINDOW(dialog), title);
	// keep window on top
	gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
	gtk_window_set_transient_for(GTK_WINDOW(dialog), parentWindow);
	
	// show dialog
	gtk_application_add_window(app, GTK_WINDOW(dialog));
	int response = gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_application_remove_window(app, GTK_WINDOW(dialog));
	gtk_widget_destroy(dialog);
	
	return response;
}


/*
** FUNCTIONS
*********************************************************
*********************************************************/

void onDestroyWindow(GtkWidget *widget, GtkApplication *app)
{
	GtkWindow *parentWindow = gtk_application_get_active_window(app);
	gtk_application_remove_window(app, parentWindow);
	g_print("Child window destroyed!\n");
}
/*
** Create window
*********************************************************/
void CreateWindow(GtkApplication *app)
{
	GtkWindow *parentWindow = gtk_application_get_active_window(app);
	GtkWidget *window;
	GtkWidget *button;

	// Setup window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	// application add window
	gtk_application_add_window(app, GTK_WINDOW(window));
	gtk_window_set_title(GTK_WINDOW(window), "Tooltip");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ON_PARENT);
	// keep window on top
	gtk_window_set_modal(GTK_WINDOW(window), TRUE);
	gtk_window_set_transient_for(GTK_WINDOW(window), parentWindow);
	gtk_window_set_destroy_with_parent(GTK_WINDOW(window), TRUE);
	
	// Customize window
	gtk_container_set_border_width(GTK_CONTAINER(window), 15);

	button = gtk_button_new_with_label("Button");
	gtk_widget_set_tooltip_text(button, "Button widget");

	gtk_widget_set_halign(button, GTK_ALIGN_START);
	gtk_widget_set_valign(button, GTK_ALIGN_START);

	gtk_container_add(GTK_CONTAINER(window), button);
	
	
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(onDestroyWindow), app);
	gtk_widget_show_all(window);
}


/* Callback for the buttons */
void on_button_clicked(GtkButton* button, gpointer user_data)
{
	g_print("Hello World\n");
	
	int result = show_question("Question", "Are you sure to quit?", user_data);
	g_print("Response is %s\n", result == GTK_RESPONSE_YES ? "Yes" : "No");
	if(result == GTK_RESPONSE_YES){
		CreateWindow(user_data);
	}
	
	//on_window_destroy(button, user_data);
}

/*
** MAIN
*********************************************************
*********************************************************/
void mainSetup(GtkApplication *app, GtkWidget *window, GtkBuilder *builder)
{
	// test button
	GtkWidget *button;
	button = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
	g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), app);
}
/* ********************************************************
******************************************************** */

static void Activate(GtkApplication *app, gpointer userData)
{
	GtkWidget *window;
	GtkBuilder *builder;
	
	// Construct a GtkBuilder instance and load our UI description
	builder = gtk_builder_new();

	// Load UI from file. If error occurs, report it and quit application.
	GError *gerror = NULL;
	if(!gtk_builder_add_from_file(builder, FILE_UI, &gerror)){
		g_warning("ERROR loading UI: %s", gerror->message);
		g_free(gerror);
		return;
	}

	// Get main window pointer from UI
	window = GTK_WIDGET(gtk_builder_get_object(builder, WIDGET_WINDOW));
	// application add window
	gtk_application_add_window(app, GTK_WINDOW(window));
	
	// Setup window
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 320, 240);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator COGFIT-19-20");
	// Connect signal handlers to the widgets
	g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);
    g_signal_connect(window, "delete_event", G_CALLBACK(on_window_close), NULL);  

	// key events
    g_signal_connect(window, "key_press_event", G_CALLBACK(on_key_press), NULL);
    g_signal_connect(window, "key_release_event", G_CALLBACK(on_key_release), NULL);

	// setup application
	mainSetup(app, window, builder);
	
	// Destroy builder, since we don't need it anymore
	g_object_unref(builder);
	// Show window. All other widgets are automatically shown by GtkBuilder
	gtk_widget_show(window);
}

int main(int argc, char *argv[])
{
    GtkApplication *app = gtk_application_new("cz.vutbr.fit.ivs.calculator", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(Activate), NULL);
	int status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
    return status;
}