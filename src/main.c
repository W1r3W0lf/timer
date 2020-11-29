#include <time.h>
//#include <stdio.h>
#include <unistd.h> // Used only for sleep
#include <gtk/gtk.h>
//#include <glib.h>

// Threading for time updating
#include <pthread.h>
//#include <semaphore.h>

#include "clock.h"
#include "alarm.h"
#include "stopWatch.h"
#include "timer.h"

// Data Structures
enum mode{
	clock_mode, timer_mode, stop_watch_mode, alarm_mode
};

// Global Vareables
enum mode app_mode;


GtkLabel *clock_display_label;

// Each one of these should be made into there own list data structure

struct timer_list my_timer_list;

struct stop_watch_list my_stop_watch_list;

struct alarm_list my_alarm_list;

// Running signal to kill timerd when the program closes
_Atomic(int) running;

// Prodotypes
void* timerd();
pthread_t timerd_proc;

/* on_activate
 * app The GTK application
 *
 * Sets up the initial UI for the program.
 */
static void on_activate (GtkApplication *app){

	GtkWindow *window;
	GtkNotebook *notebook;
	GtkLabel *label;
	GtkLabel *label2;
	GtkWidget *section_ui;

	// Setup the window
	window = GTK_WINDOW(gtk_application_window_new(app));
	gtk_window_set_title(window, "Timer");
	gtk_window_set_default_size(window, 200, 200);

	notebook = GTK_NOTEBOOK(gtk_notebook_new());

	// Setup the Clock UI

	label = GTK_LABEL(gtk_label_new("Clock"));
	clock_display_label = clock_ui(clock_display_label);
	gtk_notebook_append_page(notebook,GTK_WIDGET(clock_display_label) , GTK_WIDGET(label));

	// Setup the Timer UI
	label = GTK_LABEL(gtk_label_new("Timer"));
	section_ui = timer_ui();
	gtk_notebook_append_page(notebook, section_ui, GTK_WIDGET(label));

	// Setup the Stop Watch UI
	label = GTK_LABEL(gtk_label_new("Stop Watch"));
	label2 = GTK_LABEL(gtk_label_new("Test3"));
	gtk_notebook_append_page(notebook,GTK_WIDGET(label2) , GTK_WIDGET(label));

	// Setup the Alarm UI
	label = GTK_LABEL(gtk_label_new("Alarm"));
	label2 = GTK_LABEL(gtk_label_new("Test4"));
	gtk_notebook_append_page(notebook,GTK_WIDGET(label2) , GTK_WIDGET(label));

	gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(notebook));

	gtk_widget_show_all(GTK_WIDGET(window));
}

int main(int argc, char** argv){

	// Start timerd running in the backgound
	pthread_create(&timerd_proc, NULL, timerd, NULL);
	running = 1;

	int status;

	app_mode = clock_mode;

	GtkApplication *app = gtk_application_new("com.michaeljury.timer", G_APPLICATION_FLAGS_NONE);

	g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}

/* timerd
 *
 * Updates the clock/timer/stopwatch values
 * Keeps track of when the alarms should go off.
 */
void* timerd(){

	while(running){

		switch(app_mode){

			case clock_mode:
				update_clock(clock_display_label);
				break;

			case alarm_mode:

				break;

			case timer_mode:

				break;

			case stop_watch_mode:

				break;
		}

		sleep(1);
	}

	return NULL;
}

/* exit_timer
 *
 * Saves the active state and exits the program.
 */ 
void exit_timer(){
	running = 0; // Kill update thread
	gtk_main_quit();
}
