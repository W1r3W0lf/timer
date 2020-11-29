#include "timer.h"
#include <time.h>
#include <gtk/gtk.h>
//#include <semaphore.h>
#include <stdlib.h>


void start_timer(struct timer *this_timer){
	time_t now;
	time(&now);
	this_timer->start_time = now;
}

void pause_timer(struct timer *this_timer){

}

void reset_timer(struct timer *this_timer){
	this_timer->start_time = 0;
	this_timer->end_time = 0;
}

void save_timer(struct timer *this_timer){

}


void init_timer_list(struct timer_list *new_timer_list){
	new_timer_list->timers = malloc(sizeof(struct timer) * timer_list_starting_count);
	new_timer_list->max_count = timer_list_starting_count;
	new_timer_list->count = 0;
}


GtkWidget* timer_ui(){
	GtkWidget* listBox; // I am going to need to keep this to add more timers to it.
	GtkWidget* timer_display;

	listBox = gtk_list_box_new();
	timer_display = gtk_label_new("timer_ui");
	gtk_list_box_insert(GTK_LIST_BOX(listBox), timer_display, 0);

	return listBox;
}

