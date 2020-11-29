#include "stopWatch.h"
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>


void start_stop_watch(struct stop_watch *this_timer){
	time_t now;
	time(&now);
	if (this_timer->start_time){
		this_timer->end_time = 0;
	} else {
		this_timer->start_time = now;
	}
}

void pause_stop_watch(struct stop_watch *this_timer){
	time_t now;
	time(&now);
	this_timer->end_time = now;
}

void display_stop_watch(){

}

int add_stop_watch(struct stop_watch_list *this_list){

	if(this_list->count == this_list->max_count){

		this_list->max_count *= 2; // double the max amount of timers
		int new_size = this_list->max_count * sizeof(struct stop_watch);
		// Make new size of stop watches
		struct stop_watch *new_address = realloc(this_list->stop_watches, new_size);
		if (!new_address) // Error checking. It's good for you
			return 1;
		this_list->stop_watches = new_address;
	}

	struct stop_watch *this_stop_watch = &this_list->stop_watches[++this_list->count];

	// Setup stop watch UI
	GtkWidget *display = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);

	// Display
	GtkWidget *screen = GTK_WIDGET(gtk_label_new("00:00:00"));
	gtk_container_add(GTK_CONTAINER(display), screen);

	// Start/Stop Button
	GtkWidget *start_stop = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(start_stop), "Start");

	gtk_container_add(GTK_CONTAINER(display), start_stop);
	
	// Reset Button
	GtkWidget *reset = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(reset), "Reset");

	gtk_container_add(GTK_CONTAINER(display), reset);
	

	this_stop_watch->display = display;

	return 0;
}

int init_stop_watch_list(struct stop_watch_list *new_list){
	new_list->max_count = stop_watchs_default;

	// Make default size of stop watches
	struct stop_watch *new_address = malloc(sizeof(struct stop_watch) * stop_watchs_default);
	if (!new_address) // Error checking. It's good for you
		return 1;
	new_list->stop_watches = new_address;

	// Setup IU
	new_list->list_display = gtk_list_box_new();

	return 0;
}

void destory_stop_watch_list(struct stop_watch_list kill_list){

}

