#include "timer.h"
#include <time.h>
#include <gtk/gtk.h>
//#include <semaphore.h>
#include <stdlib.h>


void start_timer(struct timer *this_timer){

}

void pause_timer(struct timer *this_timer){

}

void reset_timer(struct timer *this_timer){

}

void save_timer(struct timer *this_timer){

}


void init_timer_list(struct timer_list *new_timer_list){
	new_timer_list->timers = malloc(sizeof(struct timer) * timer_list_starting_count);
	new_timer_list->max_timer_count = timer_list_starting_count;
	new_timer_list->timer_count = 0;
}


GtkWidget* timer_ui(GtkWidget *timer_display){
	GtkWidget* listBox; // I am going to need to keep this to add more timers to it.

	listBox = gtk_list_box_new();
	timer_display = gtk_label_new("timer_ui");
	gtk_list_box_insert(GTK_LIST_BOX(listBox), timer_display, 0);


	return listBox;
}

