#include "stopWatch.h"
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>


void start_stop_watch(struct stop_watch *this_stop_watch){
	time_t now;
	time(&now);
	if (this_stop_watch->start_time){
		this_stop_watch->end_time = 0;
	} else {
		this_stop_watch->start_time = now;
	}
}

void pause_stop_watch(struct stop_watch *this_stop_watch){
	time_t now;
	time(&now);
	this_stop_watch->end_time = now;
}

void display_stop_watch(){

}

//void add_stop_watch(struct stop_watch_list *this_stop_watch_list){
void add_stop_watch(void *input){
	struct stop_watch_list *this_stop_watch_list = input;


	if(this_stop_watch_list->count == this_stop_watch_list->max_count){

		this_stop_watch_list->max_count *= 2; // double the max amount of stop_watchs
		int new_size = this_stop_watch_list->max_count * sizeof(struct stop_watch);
		// Make new size of stop watches
		struct stop_watch *new_address = realloc(this_stop_watch_list->stop_watches, new_size);
		this_stop_watch_list->stop_watches = new_address;
	}

	struct stop_watch *this_stop_watch = &this_stop_watch_list->stop_watches[++this_stop_watch_list->count];

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
}

int init_stop_watch_list(struct stop_watch_list *new_stop_watch_list){
	new_stop_watch_list->max_count = stop_watchs_default;

	// Make default size of stop watches
	struct stop_watch *new_address = malloc(sizeof(struct stop_watch) * stop_watchs_default);
	if (!new_address) // Error checking. It's good for you
		return 1;
	new_stop_watch_list->stop_watches = new_address;

	// Setup IU
	new_stop_watch_list->list_display = gtk_list_box_new();

	return 0;
}

void destory_stop_watch_list(struct stop_watch_list *kill_list){

}

GtkWidget* stop_watch_ui(struct stop_watch_list *this_stop_watch_list){

	// Create List Box to store Stop Watches
	this_stop_watch_list->list_display = gtk_list_box_new();
	// Create an add button to make new Stop Watches
	GtkWidget* add_button = gtk_button_new_with_label("+");
	g_signal_connect(add_button, "clicked", G_CALLBACK(add_stop_watch), &this_stop_watch_list);

	gtk_list_box_insert(GTK_LIST_BOX(this_stop_watch_list->list_display), add_button, 0);

	return this_stop_watch_list->list_display;
}

