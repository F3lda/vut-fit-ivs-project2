#include <gtk/gtk.h>
#include "./../libs/basic_math.h"
#include "./../libs/adv_math.h"
#include <string.h>

#define APP_TITLE       "Calculator - COGFIT1920"
#define APP_VERSION     "1.0"
#define APP_NAME        "cz.vutbr.fit.ivs.calculator"
#define APP_ICON        "accessories-calculator"
#define APP_DOCUMENT    "https://github.com/F3lda/vut-fit-ivs-project2/blob/master/dokumentace.pdf"
#define APP_COPYRIGHT   "(c) GviDream"
#define APP_DESCRIPTION "A simple calculator created using GTK library for linux." // Also change app description in .desktop file
#define APP_WEBSITE     "https://github.com/F3lda/vut-fit-ivs-project2/"
#define APP_WEB_LABEL   "GitHub"
#define WINDOW_WIDGET   "mainWindow"
#define WINDOW_WIDTH    480
#define WINDOW_HEIGHT   380
#define FILE_UI         "calculator_ui.glade"
#define FILE_UI_STYLES  "calculator_ui_styles.css"
#define STR_BUFFER_SIZE 255
#define MATH_PRECISION  0.001

#define XML_DATA        "<?xml version=\"1.0\" encoding=\"UTF-8\"?><interface><requires lib=\"gtk+\" version=\"3.20\"/><object class=\"GtkImage\" id=\"iconNo1\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"stock\">gtk-index</property></object><object class=\"GtkImage\" id=\"iconNo2\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"stock\">gtk-index</property></object><object class=\"GtkImage\" id=\"iconNo3\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"resource\">iconNo</property></object><object class=\"GtkImage\" id=\"iconNo4\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"stock\">gtk-index</property></object><object class=\"GtkImage\" id=\"iconNo5\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"stock\">gtk-index</property></object><object class=\"GtkWindow\" id=\"mainWindow\"><property name=\"can_focus\">False</property><property name=\"icon_name\">accessories-calculator</property><child type=\"titlebar\"><placeholder/></child><child><object class=\"GtkBox\" id=\"box1\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"orientation\">vertical</property><child><object class=\"GtkMenuBar\" id=\"menubar1\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><child><object class=\"GtkMenuItem\" id=\"menuitem2\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"label\" translatable=\"yes\">_Odkazy</property><property name=\"use_underline\">True</property><child type=\"submenu\"><object class=\"GtkMenu\" id=\"menu2\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><child><object class=\"GtkImageMenuItem\" id=\"imagemenuitem21\"><property name=\"label\">Wolfram Alpha</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"image\">iconNo1</property><property name=\"use_stock\">False</property><property name=\"always_show_image\">True</property></object></child><child><object class=\"GtkImageMenuItem\" id=\"imagemenuitem22\"><property name=\"label\">GeoGebra</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"image\">iconNo2</property><property name=\"use_stock\">False</property><property name=\"always_show_image\">True</property></object></child></object></child></object></child><child><object class=\"GtkMenuItem\" id=\"menuitem3\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"label\" translatable=\"yes\">_Nápověda</property><property name=\"use_underline\">True</property><child type=\"submenu\"><object class=\"GtkMenu\" id=\"menu3\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><child><object class=\"GtkImageMenuItem\" id=\"imagemenuitem31\"><property name=\"label\">gtk-help</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"use_underline\">True</property><property name=\"use_stock\">True</property><property name=\"always_show_image\">True</property></object></child><child><object class=\"GtkSeparatorMenuItem\" id=\"separatormenuitem32\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property></object></child><child><object class=\"GtkImageMenuItem\" id=\"imagemenuitem33\"><property name=\"label\">O programu CALCULATOR</property><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"image\">iconNo3</property><property name=\"use_stock\">False</property></object></child></object></child></object></child></object><packing><property name=\"expand\">False</property><property name=\"fill\">True</property><property name=\"position\">0</property></packing></child><child><object class=\"GtkScrolledWindow\" id=\"scrolledwindow1\"><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"hscrollbar_policy\">never</property><property name=\"shadow_type\">in</property><child><object class=\"GtkTextView\" id=\"textview1\"><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"editable\">False</property><property name=\"justification\">right</property><property name=\"indent\">10</property></object></child></object><packing><property name=\"expand\">True</property><property name=\"fill\">True</property><property name=\"position\">1</property></packing></child><child><object class=\"GtkEntry\" id=\"entry1\"><property name=\"name\">entrybox</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"editable\">False</property><property name=\"invisible_char\">●</property><property name=\"truncate_multiline\">True</property><property name=\"caps_lock_warning\">False</property><property name=\"primary_icon_stock\">gtk-go-up</property><property name=\"secondary_icon_stock\">gtk-clear</property><property name=\"placeholder_text\" translatable=\"yes\">výpočet</property></object><packing><property name=\"expand\">False</property><property name=\"fill\">True</property><property name=\"position\">2</property></packing></child><child><object class=\"GtkGrid\" id=\"grid1\"><property name=\"visible\">True</property><property name=\"can_focus\">False</property><property name=\"row_homogeneous\">True</property><property name=\"column_homogeneous\">True</property><child><object class=\"GtkButton\" id=\"button1\"><property name=\"label\">n!</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"hexpand\">True</property><property name=\"relief\">none</property><property name=\"use_underline\">True</property><property name=\"always_show_image\">True</property></object><packing><property name=\"left_attach\">0</property><property name=\"top_attach\">0</property></packing></child><child><object class=\"GtkButton\" id=\"button2\"><property name=\"label\">y√x</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"hexpand\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">1</property><property name=\"top_attach\">0</property></packing></child><child><object class=\"GtkButton\" id=\"button3\"><property name=\"label\" translatable=\"yes\">x^y</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"hexpand\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">2</property><property name=\"top_attach\">0</property></packing></child><child><object class=\"GtkButton\" id=\"button4\"><property name=\"label\" translatable=\"yes\">b LOG(x)</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"hexpand\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">3</property><property name=\"top_attach\">0</property></packing></child><child><object class=\"GtkButton\" id=\"button5\"><property name=\"label\" translatable=\"yes\">C</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"hexpand\">True</property><property name=\"relief\">none</property><property name=\"image_position\">right</property></object><packing><property name=\"left_attach\">4</property><property name=\"top_attach\">0</property></packing></child><child><object class=\"GtkButton\" id=\"button6\"><property name=\"label\" translatable=\"yes\">1</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">0</property><property name=\"top_attach\">1</property></packing></child><child><object class=\"GtkButton\" id=\"button7\"><property name=\"label\" translatable=\"yes\">2</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">1</property><property name=\"top_attach\">1</property></packing></child><child><object class=\"GtkButton\" id=\"button8\"><property name=\"label\" translatable=\"yes\">3</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">2</property><property name=\"top_attach\">1</property></packing></child><child><object class=\"GtkButton\" id=\"button9\"><property name=\"label\" translatable=\"yes\">+</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">3</property><property name=\"top_attach\">1</property></packing></child><child><object class=\"GtkButton\" id=\"button10\"><property name=\"label\" translatable=\"yes\">Mr</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">4</property><property name=\"top_attach\">1</property></packing></child><child><object class=\"GtkButton\" id=\"button11\"><property name=\"label\" translatable=\"yes\">4</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">0</property><property name=\"top_attach\">2</property></packing></child><child><object class=\"GtkButton\" id=\"button12\"><property name=\"label\" translatable=\"yes\">5</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">1</property><property name=\"top_attach\">2</property></packing></child><child><object class=\"GtkButton\" id=\"button13\"><property name=\"label\" translatable=\"yes\">6</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">2</property><property name=\"top_attach\">2</property></packing></child><child><object class=\"GtkButton\" id=\"button14\"><property name=\"label\" translatable=\"yes\">-</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">3</property><property name=\"top_attach\">2</property></packing></child><child><object class=\"GtkButton\" id=\"button15\"><property name=\"label\" translatable=\"yes\">MMr</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">4</property><property name=\"top_attach\">2</property></packing></child><child><object class=\"GtkButton\" id=\"button16\"><property name=\"label\" translatable=\"yes\">7</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">0</property><property name=\"top_attach\">3</property></packing></child><child><object class=\"GtkButton\" id=\"button17\"><property name=\"label\" translatable=\"yes\">8</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">1</property><property name=\"top_attach\">3</property></packing></child><child><object class=\"GtkButton\" id=\"button18\"><property name=\"label\" translatable=\"yes\">9</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">2</property><property name=\"top_attach\">3</property></packing></child><child><object class=\"GtkButton\" id=\"button19\"><property name=\"label\" translatable=\"yes\">*</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">3</property><property name=\"top_attach\">3</property></packing></child><child><object class=\"GtkButton\" id=\"button20\"><property name=\"label\" translatable=\"yes\">Mw</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">4</property><property name=\"top_attach\">3</property></packing></child><child><object class=\"GtkButton\" id=\"button21\"><property name=\"label\" translatable=\"yes\">,</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">0</property><property name=\"top_attach\">4</property></packing></child><child><object class=\"GtkButton\" id=\"button22\"><property name=\"label\" translatable=\"yes\">0</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">1</property><property name=\"top_attach\">4</property></packing></child><child><object class=\"GtkButton\" id=\"button23\"><property name=\"label\" translatable=\"yes\">===</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">2</property><property name=\"top_attach\">4</property></packing></child><child><object class=\"GtkButton\" id=\"button24\"><property name=\"label\" translatable=\"yes\">/</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">3</property><property name=\"top_attach\">4</property></packing></child><child><object class=\"GtkButton\" id=\"button25\"><property name=\"label\" translatable=\"yes\">MMw</property><property name=\"visible\">True</property><property name=\"can_focus\">True</property><property name=\"receives_default\">True</property><property name=\"relief\">none</property></object><packing><property name=\"left_attach\">4</property><property name=\"top_attach\">4</property></packing></child></object><packing><property name=\"expand\">False</property><property name=\"fill\">True</property><property name=\"position\">3</property></packing></child></object></child></object></interface>"
#define CSS_DATA        "button {border-width: 1px;border-radius: 3px; background-color: #bfbfbf;} button.numbers {background-color: #e8e8e8; color: black;} button.button_result {color: navy;} button.hover {border-color: gray; color: green;} button.active {border-color: red; color: orange;} entry {font-size: 24px; color: black;} textview {font-size: 18px;}"

GtkEntry *ENTRY = NULL;
GtkTextView *TEXTVIEW = NULL;

char RESULT[STR_BUFFER_SIZE] = "";
char OPERAND1[STR_BUFFER_SIZE] = "";
char OPERAND2[STR_BUFFER_SIZE] = "";
char OPERATION[STR_BUFFER_SIZE] = "";
char MEM1[STR_BUFFER_SIZE] = "";
char MEM2[STR_BUFFER_SIZE] = "";

void handleInput(char keyButton);
void handleOPERAND(char operand);
void handleOPERATION(char operation);
void handleACTION(char action);
void actionSOLVE();
void handleResult(double result, int herror);
void updateUI();



//*********************************************************
//*  CUSTOM FUNCTIONS
//*********************************************************

/**
 * @brief Funkce pro otevření url adresy ve webovém prohlížeči
 *
 * @param *url Ukazatel na řetězec obsahující url adresu
 * @return TRUE - při chybě, FALSE - při správném otevření přohlížeče
 */
int open_url(const char *url)
{
	char URL[strlen(url)+50];
	strcpy(URL, "xdg-open ");
	strcat(URL, url);
	if(system(URL) == 0){// linux
		return 0;
	}
	strcpy(URL, "start ");
	strcat(URL, url);
	if(system(URL) == 0){// windows
		return 0;
	}
	strcpy(URL, "cmd /c start \"\" \"");
	strcat(URL, url);
	strcat(URL, "\"");
	if(system(URL) == 0){// windows
		return 0;
	}
	strcpy(URL, "open ");
	strcat(URL, url);
	if(system(URL) == 0){// macos
		return 0;
	}
	return 1;
}

/**
 * @brief Funkce pro zobrazení dialogu O programu
 *
 * @param *parentWindow Ukazatel na nadřazené okno, ke kterému bude dialog přiřazen
 */
void show_about(GtkWindow *parentWindow)
{
	GError *gerror = NULL;
	//GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("icon.png", &gerror);
	GdkPixbuf *pixbuf = gtk_icon_theme_load_icon(gtk_icon_theme_get_default(), APP_ICON, 64, (GtkIconLookupFlags)NULL, &gerror);
	if(gerror != NULL){
		g_warning("ERROR loading CSS: %s", gerror->message);
		g_free(gerror);
		return;
	}
	GtkWidget *dialog = gtk_about_dialog_new();
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog), APP_TITLE);
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), APP_VERSION); 
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), APP_COPYRIGHT);
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), APP_DESCRIPTION);
	gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(dialog), GTK_LICENSE_GPL_3_0);
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), APP_WEBSITE);
	gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(dialog), APP_WEB_LABEL);
	if(!pixbuf){
		g_print("pixbuffer error\n");
	} else {
		gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);	
		g_object_unref(pixbuf), pixbuf = NULL;
	}
	gtk_window_set_destroy_with_parent(GTK_WINDOW(dialog), TRUE);
	gtk_window_set_transient_for(GTK_WINDOW(dialog), parentWindow);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}



//*********************************************************
//*  GTK CUSTOM TEXTVIEW FUNCTIONS
//*********************************************************

/**
 * @brief Funkce pro získání textu z prvku TextView
 *
 * @param *text_view Ukazatel na prvek TextView
 * @return Ukazatel na řetězec obsahující text z TextView [Nutnost uvolnit pamět pomocí funkce free()]
 */
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

/**
 * @brief Funkce pro změnu obsahu prvku TextView
 *
 * @param *text_view Ukazatel na prvek TextView
 * @param *text Ukazatel na na řetězec, jehož obsah bude zkopírován do prvku TextView
 */
void gtk_textview_set_text(GtkTextView *text_view, char *text)
{
	GtkTextBuffer *buffer;
	GtkTextIter start, end;

	buffer = gtk_text_view_get_buffer(text_view);
	gtk_text_buffer_set_text(buffer, text, strlen(text));
}

/**
 * @brief Funkce pro přidání obsahu prvku TextView
 *
 * @param *text_view Ukazatel na prvek TextView
 * @param *text Ukazatel na na řetězec, jehož obsah bude přidán na konec TextView
 */
void gtk_textview_append_text(GtkTextView *text_view, char * text)
{
	GtkTextBuffer *buffer;
	GtkTextIter start, end;

	buffer = gtk_text_view_get_buffer(text_view);
	if (gtk_text_buffer_get_char_count(buffer))
		gtk_text_buffer_insert_at_cursor(buffer, "\n", 1);
	
	gtk_text_buffer_insert_at_cursor(buffer, text, strlen(text));
}

/**
 * @brief Funkce pro vertikální zascrollování na konec (spodní část) prvku TextView
 *
 * @param *text_view Ukazatel na prvek TextView
 */
void gtk_textview_scroll_to_bottom(GtkTextView *text_view)
{
	GtkTextBuffer *buffer;
	GtkTextIter iter;
	GtkTextMark *mark;

	buffer = gtk_text_view_get_buffer(text_view);
	gtk_text_buffer_get_end_iter(buffer, &iter);
	//gtk_text_iter_set_line_offset(&iter, 0);// move the iterator to the beginning of line -> so it doesn't scroll in horizontal direction
	mark = gtk_text_buffer_create_mark(buffer, NULL, &iter, FALSE);
	gtk_text_buffer_place_cursor(buffer, &iter);
	gtk_text_view_scroll_mark_onscreen(text_view, mark);
	gtk_text_buffer_delete_mark(buffer, mark);
}



//*********************************************************
//*  MAIN WINDOW CALLBACKS
//*********************************************************


// Window Callbacks
//*********************************************************

/**
 * @brief Funkce volaná těsně před ukončením programu [na tomto místě se může uvolnit všechna alokovaná paměť]
 *
 * @param *widget Ukazatel na volající prvek
 * @param user_data Uživatelská data připojená k volání při jeho registraci [V tomto případě vždy NULL]
 */
void on_window_destroy(GtkWidget *widget, gpointer user_data)
{
	g_print("Done.\n");
}

/**
 * @brief Funkce volaná při zavření programu
 *
 * @param *widget Ukazatel na volající prvek
 * @param user_data Uživatelská data připojená k volání při jeho registraci [V tomto případě vždy NULL]
 * @return TRUE - při zrušení zavření programu, FALSE - pro dokončení zavření programu
 */
int on_window_close(GtkWidget *widget, gpointer user_data)
{
	//return TRUE;	// Returning TRUE stops the window being deleted.
	return FALSE;	// Returning FALSE allows deletion.   
}


// Keyboard Callbacks
//*********************************************************

/**
 * @brief Funkce volaná při stisku klávesy na klávesnici
 *
 * @param *widget Ukazatel na volající prvek
 * @param *event Ukazatel na strukturu obsahující informace o vzniklé události
 * @param user_data Uživatelská data připojená k volání při jeho registraci [V tomto případě vždy NULL]
 */
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

/**
 * @brief Funkce volaná při uvolnění klávesy na klávesnici
 *
 * @param *widget Ukazatel na volající prvek
 * @param *event Ukazatel na strukturu obsahující informace o vzniklé události
 * @param user_data Uživatelská data připojená k volání při jeho registraci [V tomto případě vždy NULL]
 */
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


// Button Callbacks
//*********************************************************

/**
 * @brief Funkce volaná při najetí myší na tlačítko uživatelského rozhraní
 *
 * @param *button Ukazatel na volající prvek/tlačítko
 * @param user_data Uživatelská data připojená k volání při jeho registraci [V tomto případě vždy NULL]
 * @return TRUE - pokud funkce odpověděla na událost [zamezí se defaultnímu chování při najetí myší na tlačítko], FALSE - pokud funkce neodpověděla na událost [systém provede defaultní chování]
 */
int on_button_hover(GtkWidget *button, gpointer user_data)
{
	//g_print("hover\n");
	gtk_style_context_add_class(gtk_widget_get_style_context(button),"hover");
	return TRUE;
}

/**
 * @brief Funkce volaná při odjetí myší z tlačítka uživatelského rozhraní
 *
 * @param *button Ukazatel na volající prvek/tlačítko
 * @param user_data Uživatelská data připojená k volání při jeho registraci [V tomto případě vždy NULL]
 * @return TRUE - pokud funkce odpověděla na událost [zamezí se defaultnímu chování při odjetí myší z tlačítka], FALSE - pokud funkce neodpověděla na událost [systém provede defaultní chování]
 */
int on_button_leave(GtkWidget *button, gpointer user_data)
{
	//g_print("leave\n");
	gtk_style_context_remove_class(gtk_widget_get_style_context(button),"hover");
	return TRUE;
}

/**
 * @brief Funkce volaná při zmáčknutí tlačítka uživatelského rozhraní
 *
 * @param *button Ukazatel na volající prvek/tlačítko
 * @param user_data Uživatelská data připojená k volání při jeho registraci [V tomto případě vždy NULL]
 * @return TRUE - pokud funkce odpověděla na událost [zamezí se defaultnímu chování při zmáčknutí tlačítka], FALSE - pokud funkce neodpověděla na událost [systém provede defaultní chování]
 */
int on_button_press(GtkWidget *button, gpointer user_data)
{
	//g_print("click\n");
	gtk_style_context_add_class(gtk_widget_get_style_context(button),"active");
	return TRUE;
}

/**
 * @brief Funkce volaná při uvolnění tlačítka uživatelského rozhraní
 *
 * @param *button Ukazatel na volající prvek/tlačítko
 * @param user_data Uživatelská data připojená k volání při jeho registraci [V tomto případě vždy NULL]
 * @return TRUE - pokud funkce odpověděla na událost [zamezí se defaultnímu chování při uvolnění tlačítka], FALSE - pokud funkce neodpověděla na událost [systém provede defaultní chování]
 */
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


// TextView Callbacks
//*********************************************************

/**
 * @brief Funkce volaná při trojkliknutí na jakýkoliv řádek prvku TextView
 *
 * @param *text_view Ukazatel na volající prvek TextView
 */
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

/**
 * @brief Funkce volaná pro zpracování pohybu kurzoru v prvku TextView
 *
 * @param *text_view Ukazatel na volající prvek TextView
 */
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

/**
 * @brief Funkce volaná při pohybu kurzoru v prvku TextView [funkce volá po uplynutí času další funkci, která pohyb kurzoru zpracuje; čeká se na přesun kurzoru a obnovení UI]
 *
 * @param *text_view Ukazatel na volající prvek TextView
 */
void on_textview_cursor_move(GtkTextView *text_view)
{//TODO gtk_text_iter_is_end -> dont use timeout
	g_timeout_add(33, (int (*)(void*))G_CALLBACK(on_textview_cursor_move_timeout), text_view);
	//guint threadID =
	//g_source_remove(threadID); // stop timeout
}

/**
 * @brief Funkce volaná při změně velikosti prvku TextView
 *
 * @param *text_view Ukazatel na volající prvek TextView
 */
void on_textview_resize(GtkTextView *text_view, GdkRectangle *allocation, gpointer user_data) //allocation->x, allocation->y, allocation->width, allocation->height
{
	// auto scroll to bottom
	gtk_textview_scroll_to_bottom(text_view);
}


// Entry Callbacks
//*********************************************************

/**
 * @brief Funkce volaná při kliknutí na ikonku prvku Entry
 *
 * @param *entry Ukazatel na volající prvek Entry
 * @param icon_pos Identifikátor ikony
 * @param *event Ukazatel na strukturu obsahující informace o vzniklé události
 * @param *text_view Uživatelská data připojená k volání při jeho registraci [V tomto případě vždy ukazatel na prvek TextView]
 */
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


// MenuBar Callbacks
//*********************************************************

/**
 * @brief Funkce volaná při kliknutí na tličítko menu lišty
 *
 * @param *menu_item Ukazatel na volající talčítko/prvek MenuItem
 * @param *parentWindow Ukazatel na nadřazené okno programu [slouží k zobrazení dialogu O programu]
 */
void on_toolbar_button_clicked(GtkWidget *menu_item, GtkWindow *parentWindow)
{
	const char *itemLabel = gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item));
	//g_print("Item: %s\n", itemLabel);
	if(itemLabel[0] == 'W'){
		open_url("https://www.wolframalpha.com");
	} else if(itemLabel[0] == 'G'){
		open_url("https://www.geogebra.org");
	} else if(itemLabel[0] == 'g'){// documentation
		open_url(APP_DOCUMENT);
	} else 	if(itemLabel[0] == 'O'){
		show_about(parentWindow);
	}
}



//*********************************************************
//*  WORKING FUNCTIONS
//*********************************************************

/**
 * @brief Funkce volaná při jakémkoliv přijmu vstupních dat [klávesnice, myš (tlačítka)]
 *
 * @param keyButton Vstupní data v podobě jednoho znaku <char>
 */
void handleInput(char keyButton)
{
	//g_print("Key: %c\n", keyButton);
	if(('0' <= keyButton && keyButton <= '9') || keyButton == ','){// OPERAND
		handleOPERAND(keyButton);
	} else if(keyButton == '/' || keyButton == '*' || keyButton == '-' || keyButton == '+' || keyButton == 'A' || keyButton == 'X' || keyButton == 'Y' || keyButton == 'Z'){// OPERATION	
		handleOPERATION(keyButton);
	} else {// ACTION
		handleACTION(keyButton);
	}
	//UPDATE UI
	updateUI();
}

/**
 * @brief Funkce volaná při zachycení části operandu na vstupu. Funkce jej uloží do paměti aktuálně aktivního operandu [první/levý nebo druhý/pravý]
 *
 * @param keyButton Vstupní data v podobě jednoho znaku <char> [zde číslo od 0 do 9 a znak čárky (,)]
 */
void handleOPERAND(char operand)
{
	// maybe TODO max double size in input to avoid buffer overflow
	if(strcmp(OPERATION, "") == 0){// edit first operand
		if(STR_BUFFER_SIZE > 1+strlen(OPERAND1)){
			if((operand != ',' && operand != '0') || (operand == ',' && strlen(OPERAND1) != 0 && strchr(OPERAND1,',') == NULL) || (operand == '0' && (strlen(OPERAND1) != 1 || OPERAND1[0] != '0'))){
				sprintf(OPERAND1, "%s%c", OPERAND1, operand);
			}
		}
	} else {// edit second operand
		if(STR_BUFFER_SIZE > 1+strlen(OPERAND2)){
			if((operand != ',' && operand != '0') || (operand == ',' && strlen(OPERAND2) != 0 && strchr(OPERAND2,',') == NULL) || (operand == '0' && (strlen(OPERAND2) != 1 || OPERAND2[0] != '0'))){
				sprintf(OPERAND2, "%s%c", OPERAND2, operand);
			}
		}
	}
}

/**
 * @brief Funkce volaná při zachycení operace na vstupu. Funkce operaci dešifruje ze znaku na vstupu a uloží ji do paměti již jako znak dané operace
 *
 * @param keyButton Vstupní data v podobě jednoho znaku <char> [zde znaky A, X, Y, Z nebo /, *, -, +]
 */
void handleOPERATION(char operation)
{
	if(strcmp(OPERAND1, "") != 0){
		if(operation == 'A'){// !
			sprintf(OPERATION, "!");
		} else if(operation == 'X'){// √
			sprintf(OPERATION, "\u221A"); // √ - Use of unicode - Make sure your C compiler is C99 compliant.
		} else if(operation == 'Y'){// ^
			sprintf(OPERATION, "^");
		} else if(operation == 'Z'){// b LOG(x)
			sprintf(OPERATION, "LOG");
		} else {
			sprintf(OPERATION, "%c", operation);
		}
	}
}

/**
 * @brief Funkce volaná při zachycení akce na vstupu. Funkce akci dešifruje ze znaku na vstupu a provede
 *
 * @param keyButton Vstupní data v podobě jednoho znaku <char> [zde znaky r, f, w, s, nebo =, C, K]
 */
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
	else if(action == '='){// solve math problem
		actionSOLVE();
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

/**
 * @brief Funkce volaná při zachycení akce k vyřešení zadaného příkladu. Funkce dešifruje jaká matematická funkce má být použita a provede výpočet na zadaných operandech
 *
 */
void actionSOLVE()
{
	if(strcmp(OPERAND1, "") != 0 && strcmp(OPERATION, "") != 0){
		int herror;
		double operand1, operand2;
		sscanf(OPERAND1, "%lf", &operand1);
		if(strcmp(OPERAND2, "") != 0){
			sscanf(OPERAND2, "%lf", &operand2);
			if(OPERATION[0] == '+'){
				handleResult(add(operand1, operand2), 0);
			} else if(OPERATION[0] == '-'){
				handleResult(sub(operand1, operand2), 0);
			} else if(OPERATION[0] == '*'){
				handleResult(multiply(operand1, operand2), 0);
			} else if(OPERATION[0] == '/'){
				double result = divide(operand1, operand2, &herror);
				handleResult(result, herror);
			}  else if(OPERATION[0] == '^'){
				double result = Exponent(operand1, operand2, MATH_PRECISION, &herror);
				handleResult(result, herror);
			} else if(strcmp(OPERATION,"\u221A") == 0){
				double result = NthRoot(operand2, operand1, MATH_PRECISION, &herror);
				handleResult(result, herror);
			} else if(strcmp(OPERATION,"LOG") == 0){
				double result = logab(operand1, operand2, &herror);
				handleResult(result, herror);
			}
		} else if(OPERATION[0] == '!'){
			double result = factorial(operand1, &herror);
			handleResult(result, herror);
		}
	}
}

/**
 * @brief Funkce volaná po vyřešení matematického problému. Funkce zjistí, zda při řešení nedošlo k chybě a výsledek uloží do paměti
 *
 * @param result Výsledek matematické operace
 * @param herror Proměnná pro kontrulu, zda nenastal chyba při výpočtu
 */
void handleResult(double result, int herror)
{
	char error_table[8][64] = {"ZERO_DIVISION", "INVALID_FACTORIAL", "FACTORIAL_OVERFLOW", "ROOT_NEGATIVE", "EXPONENT_NEG_BASE_FRAC_POW", "LOG_DF_BASE", "LOG_DF_NUM", "LOG_BASE_1"};
	if(herror == 0){
		sprintf(RESULT, "%g", result);//maybe TODO remove trailing zeroes in the result
	} else if(1 <= herror && herror <= 8) {
		strcpy(RESULT, error_table[herror-1]);
	} else {
		strcpy(RESULT, "UNKNOWN ERROR");
	}
}

/**
 * @brief Funkce volaná po zachycení vstupu. Při změně dat je aplikuje do uživatelského prostředí
 *
 */
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



//*********************************************************
//*  MAIN
//*********************************************************

/**
 * @brief Hlavní funkce volaná při inicializaci uživatelského prostředí. Slouží k základnímu nastavení aplikace a uživatelského prostředí [nachazí se zde registrování událostí]
 *
 * @param *app Ukazatel na prvek GtkApplication
 * @param *window Ukazatel na hlavní okno aplikace
 * @param *builder Ukazatel na prvek GtkBuilder pro práci s uživatelským prostředím
 */
void mainSetup(GtkApplication *app, GtkWidget *window, GtkBuilder *builder)
{
	// GET SETTINGS
	//*********************************************************
	GtkSettings *settings;
	gchar *theme_name;
	settings = gtk_settings_get_default();
	g_object_get(settings, "gtk-theme-name", &theme_name, NULL);
	g_print("Theme: %s\n", theme_name);
	
	GtkIconTheme *icon_theme = gtk_icon_theme_get_default();
	GtkIconInfo *iconinfo = gtk_icon_theme_lookup_icon (icon_theme, APP_ICON, 48, (GtkIconLookupFlags)NULL);
	const char *icon_file = gtk_icon_info_get_filename (iconinfo);
	g_print("Icon: %s\n", icon_file);

	// SETUP CALLBACKS
	//*********************************************************
	GtkWidget *widget;
	
	//MENU ITEMS
	int menu_buttons[6] = {21,22,31,33};
	int ii = 0;
	while(ii < 4){
		char tempBuffer[24];
		sprintf(tempBuffer, "imagemenuitem%d", menu_buttons[ii++]);
		widget = GTK_WIDGET(gtk_builder_get_object(builder, tempBuffer));
		g_signal_connect(widget, "activate", G_CALLBACK(on_toolbar_button_clicked), GTK_WINDOW(window));
	}

	//BUTTONS
	widget = GTK_WIDGET(gtk_builder_get_object(builder, "button23"));
	gtk_widget_set_name(widget, "button_result");
	gtk_style_context_add_class(gtk_widget_get_style_context(widget),"button_result");
	gtk_button_set_relief(GTK_BUTTON(widget), GTK_RELIEF_NORMAL); //GTK_RELIEF_NORMAL or GTK_RELIEF_NONE
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
//*********************************************************
//*  MAIN - END
//*********************************************************


/**
 * @brief Funkce knihovny GTK při spuštění aplikace nainicializuje uživatelské prostředí a zobrazí je (hlavní okno) -> spustí celou aplikaci
 *
 * @param *app Ukazatel na prvek GtkApplication
 * @param *window Ukazatel na hlavní okno aplikace
 * @param *builder Ukazatel na prvek GtkBuilder pro práci s uživatelským prostředím
 */
static void Activate(GtkApplication *app, gpointer userData)
{
	GError *gerror;
	GtkWidget *window;
	GtkBuilder *builder;
	
	// Load UI from file. If error occurs, report it and quit application.
	builder = gtk_builder_new();
	gerror = NULL;
	//const char *XML_DATA = "";
	gtk_builder_add_from_string(builder, XML_DATA, strlen(XML_DATA), &gerror);
	//gtk_builder_add_from_file(builder, FILE_UI, &gerror);
	if(gerror != NULL){
		g_warning("ERROR loading UI: %s", gerror->message);
		g_free(gerror);
		return;
	}

	// CSS for UI
	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gerror = NULL;
	//const char *CSS_DATA = "";	
	gtk_css_provider_load_from_data(cssProvider, CSS_DATA, strlen(CSS_DATA), &gerror);
	//gtk_css_provider_load_from_path(cssProvider, FILE_UI_STYLES, &gerror);
	if(gerror != NULL){
		g_warning("ERROR loading CSS: %s", gerror->message);
		g_free(gerror);
		return;
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

/**
 * @brief První volaná funkce po spuštění programu. Funkce spouští funkce a celou aplikace postavenou na knihovně GTK
 *
 * @param argc Počet argumentů při spuštění aplikace
 * @param *argv[] ukazatel na řetězce obsahují argumenty
 */
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
}*/
