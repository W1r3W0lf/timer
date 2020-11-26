#include "timer.h"
#include <time.h>
#include <gtk/gtk.h>
#include <semaphore.h>

void init_timer(struct timer *new_timer){
	new_timer->start_time = 0;
	new_timer->end_time = 0;
}

void start_timer(struct timer *this_timer){
	time(&this_timer->start_time); // Set start to current time.

}

void pause_timer(struct timer *this_timer){
	time(&this_timer->end_time); // Set end to current time.

}

void save_timer(struct timer *this_timer){

}

GtkWidget* timer_ui(GtkWidget *timer_display){
	GtkWidget* listBox; // I am going to need to keep this to add more timers to it.

	listBox = gtk_list_box_new();
	timer_display = gtk_label_new("timer_ui");
	gtk_list_box_insert(GTK_LIST_BOX(listBox), timer_display, 0);


	return listBox;
}

