#include <time.h>
#include <stdio.h>
#include <unistd.h> // Used only for sleep
#include <gtk/gtk.h>

// Threading for time updating
#include <pthread.h>
#include <semaphore.h>

#include "clock.h"
#include "alarm.h"
#include "stopWatch.h"
#include "timer.h"

// Data Structures
enum mode{
	clock_mode, timer_mode, stopWatch_mode, alarm_mode
};

// Global Vareables
enum mode app_mode;

#define max_alarms 10
#define max_timers 10
#define max_stopWatches 10

struct alarm alarm_list[max_alarms];
//struct timer timer_list[max_timers]; // This is broken for some reason
struct stopWatch stopWatche_list[max_stopWatches];


// Running signal to kill timerd when the program closes
_Atomic(int) running;

// Prodotypes
void timerd();

// UI elements
GtkLabel clock_display;

/* on_activate
 * app The GTK application
 *
 * Sets up the initial UI for the program.
 */
static void on_activate (GtkApplication *app){

	GtkWidget *window;

	// Setup the window
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Timer");

	gtk_widget_show_all(window);
}

int main(int argc, char** argv){

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
void timerd(){

	while(running){

		switch(app_mode){

			case clock_mode:
				//update_clock(clock_display);
				break;

			case alarm_mode:

				break;

			case timer_mode:

				break;

			case stopWatch_mode:

				break;
		}

		sleep(1);
	}

}

/* exit_timer
 *
 * Saves the active state and exits the program.
 */ 
void exit_timer(){
	printf("save_file\n");
	running = 0; // Kill update thread
	gtk_main_quit();
}
