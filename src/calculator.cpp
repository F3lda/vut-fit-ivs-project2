#include <gtk/gtk.h>
#include "basic_math.h"
#include "adv_math.h"
#include <string.h>

#define FILE_UI         "calculator_ui.glade"
#define WIDGET_WINDOW   "mainWindow"


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
int show_question(const char *title, const char *message, GtkApplication *app)
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
void on_button_clicked(GtkButton *button, gpointer user_data)
{
	const char *buttonLabel = gtk_button_get_label(button);
	const char *buttonName = gtk_widget_get_name(GTK_WIDGET(button));
	g_print("Button: %s\n", buttonLabel);
	g_print("Name: %s\n", buttonName);
	
	if(strcmp(buttonLabel, "10 + 20") == 0){
		double result = add(10, 20);
		g_print("10 + 20 = %f\n", result);
	} else if(strcmp(buttonLabel, "Close") == 0){
		int result = show_question("Question", "Are you sure to quit?", (GtkApplication *)user_data);
		g_print("Response is %s\n", result == GTK_RESPONSE_YES ? "Yes" : "No");
		if(result == GTK_RESPONSE_YES){
			CreateWindow((GtkApplication *)user_data);
		}
	}
	
	//on_window_destroy(button, user_data);
}



int on_hover(GtkWidget *button, gpointer user_data)
{
	g_print("hover\n");
	gtk_style_context_add_class(gtk_widget_get_style_context(button),"najete");
	return TRUE;
}

int on_leave(GtkWidget *button, gpointer user_data)
{
	g_print("leave\n");
	gtk_style_context_remove_class(gtk_widget_get_style_context(button),"najete");
	return TRUE;
}

int on_click(GtkWidget *button, gpointer user_data)
{
	g_print("click\n");
	gtk_style_context_add_class(gtk_widget_get_style_context(button),"zmackle");
	return TRUE;
}

int on_release(GtkWidget *button, gpointer user_data)
{
	g_print("release\n");
	gtk_style_context_remove_class(gtk_widget_get_style_context(button),"zmackle");
	return TRUE;
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
	gtk_style_context_add_class(gtk_widget_get_style_context(button),"tlacidlo");
	gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_NONE);
	g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), app);
	g_signal_connect(button, "enter-notify-event", G_CALLBACK(on_hover), NULL);
	g_signal_connect(button, "leave-notify-event", G_CALLBACK(on_leave), NULL);
	g_signal_connect(button, "button-press-event", G_CALLBACK(on_click), NULL);
	g_signal_connect(button, "button-release-event", G_CALLBACK(on_release), NULL);
	

	//TEXT VIEW
	GtkTextBuffer *buffer;
	GtkTextMark *mark;
	GtkTextIter iter;
	const char *text = "TEXT";

	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(gtk_builder_get_object(builder, "textview1")));
	//text = gtk_entry_get_text(GTK_ENTRY(w->entry));
	
	mark = gtk_text_buffer_get_insert(buffer);
	gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);

	/* Insert newline (only if there's already text in the buffer). */
	if (gtk_text_buffer_get_char_count(buffer))
	    gtk_text_buffer_insert(buffer, &iter, "\n", 1);

	gtk_text_buffer_insert(buffer, &iter, text, -1);






	button = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
	gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_NONE);	
	gtk_widget_set_name(button, "tlacidlo2");
	g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), app);



	button = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
	gtk_widget_set_name(button, "tlacidlo3");
	g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), app);
	
	
	//https://elementaryos.stackexchange.com/questions/15936/button-css-not-working-in-juno	
}
/* ********************************************************
******************************************************** */

static void Activate(GtkApplication *app, gpointer userData)
{
	GError *gerror;
	GtkWidget *window;
	GtkBuilder *builder;
	
	// Load UI from file. If error occurs, report it and quit application.
	builder = gtk_builder_new();
	gerror = NULL;
	//const char *XML_DATA = "";
	//gtk_builder_add_from_string(builder, XML_DATA, strlne(XML_DATA), &gerror);
	if(!gtk_builder_add_from_file(builder, FILE_UI, &gerror)){
		g_warning("ERROR loading UI: %s", gerror->message);
		g_free(gerror);
		return;
	}

	// CSS for UI
	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gerror = NULL;
	//const char *CSS_DATA = "";	
	//gtk_css_provider_load_from_data(cssProvider, CSS_DATA, strlen(CSS_DATA), &gerror);
	gtk_css_provider_load_from_path(cssProvider, "calculator_ui_styles.css", &gerror);
	if(gerror != NULL){
		g_warning("ERROR loading CSS: %s", gerror->message);
		g_free(gerror);
	}
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER); // _PRIORITY_APPLICATION
	g_object_unref(cssProvider);


	// Get main window pointer from UI
	window = GTK_WIDGET(gtk_builder_get_object(builder, WIDGET_WINDOW));
	// application add window
	gtk_application_add_window(app, GTK_WINDOW(window));
	
	// Setup window
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 480, 380);
	gtk_window_set_title(GTK_WINDOW(window), "Calculator - COGFIT1920");
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
	gtk_widget_show_all(window);
}

int main(int argc, char *argv[])
{
	GtkApplication *app = gtk_application_new("cz.vutbr.fit.ivs.calculator", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(Activate), NULL);
	int status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
	return status;
}
