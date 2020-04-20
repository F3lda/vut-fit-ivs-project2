#include <gtk/gtk.h>
#include "basic_math.h"
#include "adv_math.h"
#include <string.h>

#define APP_TITLE       "Calculator - COGFIT1920"
#define APP_NAME        "cz.vutbr.fit.ivs.calculator"
#define WINDOW_WIDGET   "mainWindow"
#define WINDOW_WIDTH    480
#define WINDOW_HEIGHT   380
#define FILE_UI         "calculator_ui.glade"
#define FILE_UI_STYLES  "calculator_ui_styles.css"
#define STR_BUFFER_SIZE 255

GtkEntry *ENTRY = NULL;
GtkTextView *TEXTVIEW = NULL;

char RESULT[STR_BUFFER_SIZE] = "";
char OPERAND1[STR_BUFFER_SIZE] = "";
char OPERAND2[STR_BUFFER_SIZE] = "";
char OPERATION[STR_BUFFER_SIZE] = "";
char MEM1[STR_BUFFER_SIZE] = "";
char MEM2[STR_BUFFER_SIZE] = "";

void gtk_textview_scroll_to_bottom(GtkTextView *text_view);
void handleInput(char keyButton);
void handleOPERAND(char *operand);
void handleOPERATION(char *operand);
void handleACTION(char action);
void handleResult();
void updateUI();


/*
** MAIN WINDOW CALLBACKS
*********************************************************
*********************************************************/

// App is finished. Clean up everything.
//*********************************************************
void on_window_destroy(GtkWidget *widget, gpointer user_data)
{
	g_print("Done.\n");
}

// When window is closed
//*********************************************************
int on_window_close(GtkWidget *widget, gpointer user_data)
{
	//return TRUE;	// Returning TRUE stops the window being deleted.
	return FALSE;	// Returning FALSE allows deletion.   
}

// When key is pressed
//*********************************************************
char lastCharStillDown = '\0';
void on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
	//g_print("Key released: %u\n", event->keyval);	
	//g_print("Key released: %s\n", gdk_keyval_name(event->keyval));
	//g_print("Key released: %s\n", event->string);
	
	char ch = (event->string)[0];
	// Two keys down at the same time
	if(lastCharStillDown == '/' && ch == '*'){// factorial
		lastCharStillDown = 'A';
	} else if(lastCharStillDown == '*' && ch == '/'){// root
		lastCharStillDown = 'X';
	} else if(lastCharStillDown == '*' && ch == '-'){// power
		lastCharStillDown = 'Y';
	} else if(lastCharStillDown == '-' && ch == '*'){// logarithm
		lastCharStillDown = 'Z';
	} else if(ch == 'w' || ch == 'r' || ('0' <= ch && ch <= '9') || ch == '/' || ch == '*' || ch == '-' || ch == '+' || ch == '.' || ch == ',' || ch == 13 || ch == 8 || ch == 127){// allow to remember last char 
		lastCharStillDown = ch;
	}
}

// When key is released
//*********************************************************
void on_key_release(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
	//g_print("Key released: %u\n", event->keyval);
	//g_print("Key released: %s\n", gdk_keyval_name(event->keyval));
	//g_print("Key released: %s\n", event->string);
	
	if(lastCharStillDown == 'A' || lastCharStillDown == 'X' || lastCharStillDown == 'Y' || lastCharStillDown == 'Z'){// Two keys down at the same time
		handleInput(lastCharStillDown);
		lastCharStillDown = '\n';// block keys released
	} else if(lastCharStillDown != '\n'){
		lastCharStillDown = '\0';// reset Two keys down at the same time

		char ch = (event->string)[0];
		static char lastChar = '\0';
		if(lastChar == 'w'){// Two keys down not at the same time
			if(ch == '1'){
				handleInput('w');
			} else if(ch == '2'){
				handleInput('s');
			}
		} else if(lastChar == 'r'){// Two keys down not at the same time
			if(ch == '1'){
				handleInput('r');		
			} else if(ch == '2'){
				handleInput('f');
			}
		} else if(('0' <= ch && ch <= '9') || ch == '/' || ch == '*' || ch == '-' || ch == '+' || ch == ','){
			handleInput(ch);
		} else if(ch == '.'){
			handleInput(',');
		} else if(ch == 13){// ENTER
			handleInput('=');
		} else if(ch == 8){// Backspace
			handleInput('K');
		} else if(ch == 127){// Delete
			handleInput('C');
		}
		lastChar = ch;
	}
}


/*
** CALLBACKS
*********************************************************
*********************************************************/

// Button callbacks
//*********************************************************
int on_button_hover(GtkWidget *button, gpointer user_data)
{
	//g_print("hover\n");
	gtk_style_context_add_class(gtk_widget_get_style_context(button),"hover");
	return TRUE;
}

int on_button_leave(GtkWidget *button, gpointer user_data)
{
	//g_print("leave\n");
	gtk_style_context_remove_class(gtk_widget_get_style_context(button),"hover");
	return TRUE;
}

int on_button_press(GtkWidget *button, gpointer user_data)
{
	//g_print("click\n");
	gtk_style_context_add_class(gtk_widget_get_style_context(button),"active");
	return TRUE;
}

int on_button_release(GtkWidget *button, gpointer user_data)
{
	//g_print("release\n");
	gtk_style_context_remove_class(gtk_widget_get_style_context(button),"active");

	const char *buttonLabel = gtk_button_get_label(GTK_BUTTON(button));
	//const char *buttonName = gtk_widget_get_name(button);
	//g_print("Name: %s\n", buttonName);	
	//g_print("Button: %s\n", buttonLabel);
	char ch = buttonLabel[0];
	if(('0' <= ch && ch <= '9') || ch == '/' || ch == '*' || ch == '-' || ch == '+' || ch == ',' || ch == '=' || ch == 'C'){
		handleInput(ch);
	} else if(ch == 'n'){
		handleInput('A');
	} else if(ch == 'y'){
		handleInput('X');
	} else if(ch == 'x'){
		handleInput('Y');
	} else if(ch == 'b'){
		handleInput('Z');
	} else if(strcmp(buttonLabel,"Mr") == 0){
		handleInput('r');
	} else if(strcmp(buttonLabel,"MMr") == 0){
		handleInput('f');
	} else if(strcmp(buttonLabel,"Mw") == 0){
		handleInput('w');
	} else if(strcmp(buttonLabel,"MMw") == 0){
		handleInput('s');
	}
	return TRUE;
}

// Textview callbacks
//*********************************************************
void on_textview_row_selection(GtkTextView *text_view) // unused
{
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view);
	GtkTextIter start, end;
	if(gtk_text_buffer_get_selection_bounds(buffer, &start, &end)){
		gtk_text_iter_set_line_offset(&start, 0);
		gtk_text_iter_forward_to_line_end(&end);
		if(!gtk_text_iter_ends_line(&end))
			gtk_text_iter_set_line_offset(&end, gtk_text_iter_get_chars_in_line(&end));
		char *text = gtk_text_buffer_get_text(buffer, &start, &end, TRUE);
		//g_print("selection: %s\n",text);
		free(text);
	}
}

void on_textview_cursor_move_timeout(GtkTextView *text_view)
{
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view);
	GtkTextMark *mark = gtk_text_buffer_get_insert(buffer);
	GtkTextIter start, end;
	gtk_text_buffer_get_iter_at_mark(buffer, &start, mark);
	
	end = start;
	gtk_text_iter_set_line_offset(&start, 0);
	gtk_text_iter_forward_to_line_end(&end);
	if(!gtk_text_iter_ends_line(&end))
		gtk_text_iter_set_line_offset(&end, gtk_text_iter_get_chars_in_line(&end));
	char *text = gtk_text_buffer_get_text(buffer, &start, &end, TRUE);

	const char *entry_text = gtk_entry_get_text(ENTRY);
	char operand1[STR_BUFFER_SIZE], operation[STR_BUFFER_SIZE], operand2[STR_BUFFER_SIZE], result[STR_BUFFER_SIZE];
	if(sscanf(text, "%s %s %s = %s", operand1, operation, operand2, result) == 4){// && strcmp(entry_text, result) != 0
		strcpy(OPERAND1, operand1);
		strcpy(OPERATION, operation);
		strcpy(OPERAND2, operand2);
		updateUI();
	}

	free(text);
}

void on_textview_cursor_move(GtkTextView *text_view)
{
	g_timeout_add(33, (int (*)(void*))G_CALLBACK(on_textview_cursor_move_timeout), text_view);
	//guint threadID =
	//g_source_remove(threadID); // stop timeout
}

void on_textview_resize(GtkTextView *text_view, GdkRectangle *allocation, gpointer user_data) //allocation->x, allocation->y, allocation->width, allocation->height
{
	// auto scroll to bottom
	gtk_textview_scroll_to_bottom(text_view);
}

// Entry callbacks
//*********************************************************
void on_entry_icon_click(GtkEntry *entry, int icon_pos, GdkEvent *event, GtkTextView *text_view)
{
	if(icon_pos == 0){
		//textview set focus
		gtk_widget_set_can_focus(GTK_WIDGET(text_view), TRUE);
		gtk_widget_grab_focus(GTK_WIDGET(text_view));
		//textview move cursor
		GtkTextBuffer *buffer = gtk_text_view_get_buffer(text_view);
		GtkTextMark *mark = gtk_text_buffer_get_insert(buffer);
		GtkTextIter iter;
		gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);
		if(gtk_text_iter_is_end(&iter)){
			gtk_text_iter_set_line_offset(&iter, 0);
		} else {
			gtk_text_iter_backward_line(&iter);
		}
		gtk_text_buffer_place_cursor(buffer, &iter);
		gtk_text_view_scroll_mark_onscreen(text_view, mark);
		//on_textview_cursor_move_timeout(text_view);
	} else if(icon_pos == 1){
		//backspace button
		handleInput('K');
	}
}


/*
** FUNCTIONS
*********************************************************
*********************************************************/

// Textview functions
//*********************************************************
char * gtk_textview_get_text(GtkTextView *text_view)
{
	GtkTextBuffer *buffer;
	GtkTextIter start, end;
	char *text;

	buffer = gtk_text_view_get_buffer(text_view);
	gtk_text_buffer_get_bounds(buffer, &start, &end);
	text = gtk_text_buffer_get_text(buffer, &start, &end, TRUE);
	return text; //need to free text
}

void gtk_textview_append_text(GtkTextView *text_view, char * text)
{
	GtkTextBuffer *buffer;
	GtkTextIter start, end;

	buffer = gtk_text_view_get_buffer(text_view);
	if (gtk_text_buffer_get_char_count(buffer))
		gtk_text_buffer_insert_at_cursor(buffer, "\n", 1);
	
	gtk_text_buffer_insert_at_cursor(buffer, text, strlen(text));
}

void gtk_textview_set_text(GtkTextView *text_view, char * text)
{
	GtkTextBuffer *buffer;
	GtkTextIter start, end;

	buffer = gtk_text_view_get_buffer(text_view);
	gtk_text_buffer_set_text(buffer, text, strlen(text));
}

void gtk_textview_scroll_to_bottom(GtkTextView *text_view)
{
	GtkTextBuffer *buffer;
	GtkTextIter iter;
	GtkTextMark *mark;

	buffer = gtk_text_view_get_buffer(text_view);
	gtk_text_buffer_get_end_iter(buffer, &iter);
	//gtk_text_iter_set_line_offset(&iter, 0);// Move the iterator to the beginning of line, so we don't scroll in horizontal direction.
	mark = gtk_text_buffer_create_mark(buffer, NULL, &iter, FALSE);
	gtk_text_buffer_place_cursor(buffer, &iter);
	gtk_text_view_scroll_mark_onscreen(text_view, mark);
	gtk_text_buffer_delete_mark(buffer, mark);
}


/*
** WORKING FUNCTIONS
*********************************************************
*********************************************************/

// Handle input
//*********************************************************
void handleInput(char keyButton)
{
	//g_print("Key: %c\n", keyButton);
	char temp_string[STR_BUFFER_SIZE];
	if(('0' <= keyButton && keyButton <= '9') || keyButton == ','){// OPERAND
		sprintf(temp_string, "%c", keyButton);
		handleOPERAND(temp_string);
	} else if(keyButton == '/' || keyButton == '*' || keyButton == '-' || keyButton == '+' || keyButton == 'A' || keyButton == 'X' || keyButton == 'Y' || keyButton == 'Z'){// OPERATION
		sprintf(temp_string, "%c", keyButton);	
		handleOPERATION(temp_string);
	} else {// ACTION
		handleACTION(keyButton);
	}
	//UPDATE UI
	updateUI();
}

void handleOPERAND(char *operand)
{
	
	if(strcmp(OPERATION, "") == 0){// edit first operand
		if(STR_BUFFER_SIZE > strlen(operand)+strlen(OPERAND1)){
			if((operand[0] != ',') || (operand[0] == ',' && strlen(OPERAND1) != 0 && strchr(OPERAND1,',') == NULL)){
				sprintf(OPERAND1, "%s%s", OPERAND1, operand);
			}
		}
	} else {// edit second operand
		if(STR_BUFFER_SIZE > strlen(operand)+strlen(OPERAND2)){
			if((operand[0] != ',') || (operand[0] == ',' && strlen(OPERAND2) != 0 && strchr(OPERAND2,',') == NULL)){
				sprintf(OPERAND2, "%s%s", OPERAND2, operand);
			}
		}
	}
}

void handleOPERATION(char *operation)
{
	if(strcmp(OPERAND1, "") != 0){
		if(operation[0] == 'A'){// !
			sprintf(OPERATION, "!");
		} else if(operation[0] == 'X'){// √
			sprintf(OPERATION, "\u221A"); // √ - Use of unicode - Make sure your C compiler is C99 compliant.
		} else if(operation[0] == 'Y'){// ^
			sprintf(OPERATION, "^");
		} else if(operation[0] == 'Z'){// b LOG(x)
			sprintf(OPERATION, "LOG");
		} else if(STR_BUFFER_SIZE > strlen(operation)){
			sprintf(OPERATION, "%s", operation);
		}
	}
}

void handleACTION(char action)
{
	// OPERATION-ACTION	
	if(action == 'r'){
		if(strcmp(OPERATION, "") == 0){// edit first operand
			if(STR_BUFFER_SIZE > strlen(MEM1)){
				sprintf(OPERAND1, "%s", MEM1);
			}
		} else {// edit second operand
			if(STR_BUFFER_SIZE > strlen(MEM1)){
				sprintf(OPERAND2, "%s", MEM1);
			}
		}
	} else if(action == 'f'){
		if(strcmp(OPERATION, "") == 0){// edit first operand
			if(STR_BUFFER_SIZE > strlen(MEM2)){
				sprintf(OPERAND1, "%s", MEM2);
			}
		} else {// edit second operand
			if(STR_BUFFER_SIZE > strlen(MEM2)){
				sprintf(OPERAND2, "%s", MEM2);
			}
		}
	} else if(action == 'w'){
		if(strcmp(RESULT, "") == 0 && strcmp(OPERAND1, "") == 0){
			strcpy(MEM1, gtk_entry_get_text(ENTRY));
		} else {
			strcpy(MEM1, OPERAND1);
		}
	} else if(action == 's'){
		if(strcmp(RESULT, "") == 0 && strcmp(OPERAND1, "") == 0){
			strcpy(MEM2, gtk_entry_get_text(ENTRY));
		} else {
			strcpy(MEM2, OPERAND1);
		}
	}
	// ACTIONS
	else if(action == '='){// solve
		handleResult();
	} else if(action == 'C'){// clear all
		strcpy(OPERAND1, "");
		strcpy(OPERATION, "");
		strcpy(OPERAND2, "");
	} else if(action == 'K'){// delete one char
		if(strcmp(OPERAND2,"") != 0){
			OPERAND2[strlen(OPERAND2)-1] = '\0';
		} else if(strcmp(OPERATION,"") != 0){
			OPERATION[strlen(OPERATION)-1] = '\0';
		} else if(strcmp(OPERAND1,"") != 0){
			OPERAND1[strlen(OPERAND1)-1] = '\0';
		}
	}
}

void handleResult()
{
	if(strcmp(OPERAND1, "") != 0 && strcmp(OPERATION, "") != 0){
		int herror;
		double operand1, operand2;
		sscanf(OPERAND1, "%lf", &operand1);
		if(strcmp(OPERAND2, "") != 0){
			sscanf(OPERAND2, "%lf", &operand2);
			if(OPERATION[0] == '+'){
				sprintf(RESULT, "%f", add(operand1, operand2));
			} else if(OPERATION[0] == '-'){
				sprintf(RESULT, "%f", sub(operand1, operand2));
			} else if(OPERATION[0] == '*'){
				sprintf(RESULT, "%f", multiply(operand1, operand2));
			} else if(OPERATION[0] == '/'){
				double result = divide(operand1, operand2, &herror);
				if(herror == ZERO_DIVISION) {
					strcpy(RESULT, "ZERO_DIVISION");
				} else {
					sprintf(RESULT, "%f", result);
				}
			}  else if(OPERATION[0] == '^'){
				double result = Exponent(operand1, operand2, 0.001, &herror);
				if(herror == ZERO_DIVISION) {
					strcpy(RESULT, "ZERO_DIVISION");
				} else if(herror == EXPONENT_NEG_BASE_FRAC_POW) {
					strcpy(RESULT, "EXPONENT_NEG_BASE_FRAC_POW");
				} else {
					sprintf(RESULT, "%f", result);
				}
			} else if(strcmp(OPERATION,"\u221A") == 0){
				double result = NthRoot(operand2, operand1, 0.001, &herror);
				if(herror == ZERO_DIVISION) {
					strcpy(RESULT, "ZERO_DIVISION");
				} else if(herror == ROOT_NEGATIVE) {
					strcpy(RESULT, "ROOT_NEGATIVE");
				} else {
					sprintf(RESULT, "%f", result);
				}
			} else if(strcmp(OPERATION,"LOG") == 0){
				double result = logab(operand1, operand2, &herror);
				if(herror == LOG_DF_BASE) {
					strcpy(RESULT, "LOG_DF_BASE");
				} else if(herror == LOG_DF_NUM) {
					strcpy(RESULT, "LOG_DF_NUM");
				} else if(herror == LOG_BASE_1) {
					strcpy(RESULT, "LOG_BASE_1");
				} else {
					sprintf(RESULT, "%f", result);
				}
			}
		} else if(OPERATION[0] == '!'){
			double result = factorial(operand1, &herror);
			if(herror == FACTORIAL_OVERFLOW) {
				strcpy(RESULT, "FACTORIAL_OVERFLOW");
			} else if(herror == INVALID_FACTORIAL) {
				strcpy(RESULT, "INVALID_FACTORIAL");
			} else {
				sprintf(RESULT, "%f", result);
			}
		}
	}
}

void updateUI()
{
	if(ENTRY != NULL){
		char spaces_count = 0;
		char temp_string[STR_BUFFER_SIZE*3];
		sprintf(temp_string, "%s %s %s", OPERAND1, OPERATION, OPERAND2);
		if(strcmp(RESULT, "") == 0){
			g_print("INPUT\n");
			if(strcmp(OPERATION, "") == 0) spaces_count++;
			if(strcmp(OPERAND2, "") == 0) spaces_count++;
		} else {
			g_print("RESULT: %s %s %s = %s\n", OPERAND1, OPERATION, OPERAND2, RESULT);
			sprintf(temp_string, "%s = %s", temp_string, RESULT);
			if(TEXTVIEW != NULL){
				gtk_textview_scroll_to_bottom(TEXTVIEW);
				gtk_textview_append_text(TEXTVIEW, temp_string);
			}
			strcpy(temp_string, RESULT);
			strcpy(RESULT, "");
			strcpy(OPERAND1, "");
			strcpy(OPERATION, "");
			strcpy(OPERAND2, "");
		}
		gtk_entry_set_text(ENTRY, temp_string);
		gtk_editable_set_position(GTK_EDITABLE(ENTRY), strlen(temp_string)-(int)spaces_count); // set cursor position at the end
	}
}


/*
** MAIN
*********************************************************
*********************************************************/
void mainSetup(GtkApplication *app, GtkWidget *window, GtkBuilder *builder)
{
	// SETUP CALLBACKS
	//*********************************************************
	GtkWidget *widget;

	//BUTTONS
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "button23"));
	gtk_widget_set_name(widget, "button_result");
	gtk_style_context_add_class(gtk_widget_get_style_context(widget),"button_result");
	gtk_button_set_relief(GTK_BUTTON(widget), GTK_RELIEF_NONE);
	//g_signal_connect(widget, "clicked", G_CALLBACK(on_button_click), app);
	g_signal_connect(widget, "enter-notify-event", G_CALLBACK(on_button_hover), NULL);
	g_signal_connect(widget, "leave-notify-event", G_CALLBACK(on_button_leave), NULL);
	g_signal_connect(widget, "button-press-event", G_CALLBACK(on_button_press), NULL);
	g_signal_connect(widget, "button-release-event", G_CALLBACK(on_button_release), NULL);
	
	int i = 0;
	while(i < 25){
		char tempBuffer[24];
		sprintf(tempBuffer, "button%d", ++i);
		widget = GTK_WIDGET(gtk_builder_get_object(builder, tempBuffer));
		const char *buttonLabel = gtk_button_get_label(GTK_BUTTON(widget));
		char ch = buttonLabel[0];
		if('0' <= ch && ch <= '9'){
			gtk_style_context_add_class(gtk_widget_get_style_context(widget),"numbers");
		}
		g_signal_connect(widget, "enter-notify-event", G_CALLBACK(on_button_hover), NULL);
		g_signal_connect(widget, "leave-notify-event", G_CALLBACK(on_button_leave), NULL);
		g_signal_connect(widget, "button-press-event", G_CALLBACK(on_button_press), NULL);
		g_signal_connect(widget, "button-release-event", G_CALLBACK(on_button_release), NULL);
	}

	//ENTRY on icon click
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
	g_signal_connect(widget, "icon-press", G_CALLBACK(on_entry_icon_click), GTK_TEXT_VIEW(GTK_WIDGET(gtk_builder_get_object(builder, "textview1"))));
	ENTRY = GTK_ENTRY(widget);

	//TEXT VIEW on row selection
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "textview1"));
	g_signal_connect(widget, "extend-selection", G_CALLBACK(on_textview_row_selection), NULL);
	//TEXT VIEW text auto scroll
	g_signal_connect(widget, "size-allocate", G_CALLBACK(on_textview_resize), NULL);
	//TEXT VIEW on cursor move
	g_signal_connect(widget, "grab-focus", G_CALLBACK(on_textview_cursor_move), NULL);
	//TEXT VIEW on cursor move by arrows
	g_signal_connect(widget, "move-cursor", G_CALLBACK(on_textview_cursor_move), NULL);
	TEXTVIEW = GTK_TEXT_VIEW(widget);
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
	gtk_css_provider_load_from_path(cssProvider, FILE_UI_STYLES, &gerror);
	if(gerror != NULL){
		g_warning("ERROR loading CSS: %s", gerror->message);
		g_free(gerror);
	}
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER); // _PRIORITY_APPLICATION
	g_object_unref(cssProvider);


	// Get main window pointer from UI
	window = GTK_WIDGET(gtk_builder_get_object(builder, WINDOW_WIDGET));
	// application add window
	gtk_application_add_window(app, GTK_WINDOW(window));
	
	// Setup window
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT);
	gtk_window_set_title(GTK_WINDOW(window), APP_TITLE);
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
	GtkApplication *app = gtk_application_new(APP_NAME, G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(Activate), NULL);
	int status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
	return status;
}





/*
** UNUSED CODE EXAMPLES
*********************************************************
*********************************************************/
/*
//*
//* Show question dialog
//*********************************************************
int show_question(const char *title, const char *message, GtkApplication *app)
{
	//GTK_RESPONSE_NONE         = -1,
	//GTK_RESPONSE_REJECT       = -2,
	//GTK_RESPONSE_ACCEPT       = -3,
	//GTK_RESPONSE_DELETE_EVENT = -4,
	//GTK_RESPONSE_OK           = -5,
	//GTK_RESPONSE_CANCEL       = -6,
	//GTK_RESPONSE_CLOSE        = -7,
	//GTK_RESPONSE_YES          = -8,
	//GTK_RESPONSE_NO           = -9,
	//GTK_RESPONSE_APPLY        = -10,
	//GTK_RESPONSE_HELP         = -11

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


//*
//* Child Window Example
//*********************************************************
//*********************************************************
void onDestroyWindow(GtkWidget *widget, GtkApplication *app)
{
	GtkWindow *parentWindow = gtk_application_get_active_window(app);
	gtk_application_remove_window(app, parentWindow);
	g_print("Child window destroyed!\n");
}
//*
//* Create window
//*********************************************************
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
*/